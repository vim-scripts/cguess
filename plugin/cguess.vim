" File:		cguess.vim
" Maintainer:	Andrzej Zaborowski 'balrog' <balrogg@gmail.com>
" License:	Vim License (see vim's :help license)
" Version:	0.2
" URL:		http://www.zabor.org/cguess
"
" This plugin provides some features  that can make writing
" code in some  languages easier  (for lazy programmers  at
" least), like showing information on the identifiers cont-
" ained in a namespace  whose name has been typed and auto-
" completing these identifiers.
"
" To use the plugin, source it with :so cguess.vim and just
" edit a source file in a supported language.
"
" TODO: improve  the choice window keymaps,  make searching
" across all the identifier,  not only the first  character
" and make the window close when it is not found so that if
" a user is typing and the window pops up,  they can ignore
" it and have the same text entered.
"
" TODO: display the namespace name as window title.
"
" TODO: possibly make use of chooser in GUI and balloons if
" information about functions' parameters is displayed.
"
" TODO: find a way to split the window and do stuff without
" leaving INSERT mode cause this resets the point where the
" mode was started and then the  functionality of backspace
" is changed (unless you  have "start" included in variable
" backspace) or find a way to restore this point. ^O is not
" any better.
"
" TODO: when  cguess finally supports  caching common data,
" the first time it's  run echo "Parsing... (^C to Abort)".
" For caching the plugin will pass --file-local=foo as well
" as --temp=/bar and cguess will write symbol trees to /bar
" in binary  for all files  except foo which will  be fully
" parsed. --file-local  will also cause cguess not to parse
" functions outside foo.
"
" TODO: later we could feed the  whole source to cguess and
" only tell it the  line and column where it  should finish
" parsing so  things like actions in yacc grammars could be
" processed too.
"
" TODO: check how many lines cguess emited, if none, return
" silently and if one show it as a tip, otherwise split the
" window.
"
" TODO: the script should  call cguess and return to insert
" mode immediately  and then check  if cguess has  finished
" every 100ms or similar.

" Has this already been loaded?
if exists("loaded_cguess")
  finish
endif
let loaded_cguess = "v0.2"

" Line continuation used here
let s:cpo_save = &cpo
set cpo&vim

"---
" Default settings for global configuration variables

" Split vertically instead of horizontally?
if !exists("g:cguessVertical")
  let g:cguessVertical = 1
endif

" How big to make the window? Set to "" to avoid resizing
if !exists("g:cguessWinSizeVert")
  let g:cguessWinSizeVert = 18
endif
if !exists("g:cguessWinSizeHoriz")
  let g:cguessWinSizeHoriz = 8
endif

" When opening a new window, split below current window (or
" above)?  1 = below, 0 = to above
if !exists("g:cguessSplitBelow")
  let g:cguessSplitBelow = &splitbelow
endif

" Split to right of current window (or to left)?
" 1 = to right, 0 = to left
if !exists("g:cguessSplitRight")
  let g:cguessSplitRight = 1 " &splitright
endif

" Run the preprocessor before interpeting the code?
" This more correctly should be local to buffer, but
" it wouldn't be very handy then.
if !exists("g:cguessPreprocess")
  let g:cguessPreprocess = 1
endif

" Additional parameters passed to the C preprocessor
" TODO: check errors from system()
" TODO: collect some standard CFLAGS.
" For projects using automake we can somehow extract
" the include dirs from the Makefile in current directory
" using some strange hack.
" Also we could parse errors from cpp and lookup the paths
" in the "locate" database.
" Makefile should gather the gcc and g++ default paths.
if !exists("g:cguessCFLAGS")
  let install_path = system("echo -n `cc --print-search-dirs"
	\ . " | grep install: | sed 's/^install: /-I/'`")
	\ . "include"
  let gccincludes = escape(install_path, "\\ ()[]")
  let gppincludes = system("echo -n \\  `ls -d /usr/include/"
	\ . "c++/*/*/ /usr/include/c++/*/ | sed s#^/#-I/#g`")

" We pass -D__CGUESS__ to let the program know it is
" not a normal compilation, just in case. _GNU_SOURCE is
" critical on Linux, for some reason the standard headers
" and cpp generate incorrect code without it. But if
" __GNUC__ is also defined a lot of GCC specific keywords
" is inserted in the code, that we don't want to parse.
" Until cguess can ignore GNU C++ attributes on its own,
" we will make preprocessor skip them.
  let macros = " -D_GNU_SOURCE -D__CGUESS__ \"-D__attribute__"
	\ . "(_)=\" \"-D__STL_DEFAULT_ALLOCATOR(x)=alloc\""

" example:
  let gtkincludes = "-I/usr/lib/glib-2.0/include/ -I/usr/lib/"
	\ . "gtk-2.0/include/ -I/usr/include/atk-1.0/ -I/usr/"
	\ . "include/pango-1.0/ -I/usr/include/glib-2.0/ -I/u"
	\ . "sr/include/gtk-2.0/"

  let g:cguessCFLAGS = gccincludes . gppincludes . macros
	\ . " -I/usr/include -I/usr/local/include -I./include"
	\ . " -I. -I../include " . gtkincludes
endif

"---
" script variables

"---
" Queries for the scope information about the last
" identifier typed and displays the list of choices
" TODO: inhibit any action when pasting with right
" mouse button (e.g when user seems to be typing
" very fast)
function! s:TriggerList(lang)
" Don't do anything if the cursor is inside a comment,
" a constant or a preprocessor directive
" TODO: improve, use the names
  let at = synID(line("."), col("."), 0)
  let pp = match(getline("."), "^[ \t]*#")
  if at == 70 || at == 88 || at == 89 || at == 62 ||
	\ at == 66 || at == 76 || at == 100 ||
	\ at == 102 || at == 109 || at == 110 ||
	\ at == 111 || pp > -1
    if col(".") == col("$") - 1
      star!
    el
      norm l
      star
    en
    return
  en

" Preprocessor invocation
  let cpp = ""
  if g:cguessPreprocess == 1
    let cpp = "cpp " . g:cguessCFLAGS . "|"
  en

" The parser invocation
  let params = ""
  if g:cguessVertical != 1
    let params = " --types --lang=" . a:lang
  en

  let parser = "cguess" . params

" Save the current line in a variable cause we need to modify it
" temporarily
  let ids = tempname()
  let lin = getline(".")
  let re2 = " 2>/dev/null"
  let cmd = "1,.w !" . cpp . parser . ">" . ids . re2
  let s:ids = "r" . ids

  if col(".") < col("$") - 1
    norm ld$
  en

" Parse the file
" TODO: check if grep "No such file or" and if so echo "Fix includes for CG"
  sil! exe cmd

" Restore
  cal setline(line("."), lin)

  if v:shell_error
    if col(".") == col("$") - 1
      star!
    el
      norm l
      star
    en
  el
"   Restore the statusline so that it is not displayed for the new window
    cal s:HideTip()
    cal s:OpenList("Choose-one")
  en
  unl s:ids
endfunction

"---
" Queries for the scope information about the function
" that is being called and displays a tip about its
" parameters.
" TODO: inhibit any action when pasting with right
" mouse button (e.g when user seems to be typing
" very fast)
function! s:TriggerTip(lang)
" Don't do anything if the cursor is inside a comment,
" a constant or a preprocessor directive
" TODO: improve
  let at = synID(line("."), col("."), 0)
  if at != 94 && at != 93
    if col(".") == col("$") - 1
      star!
    el
      norm l
      star
    en
    return
  en

" Preprocessor invocation
  let cpp = ""
  if g:cguessPreprocess == 1
    let cpp = "cpp " . g:cguessCFLAGS . "|"
  en

" The parser invocation
  let parser = "cguess --lang=" . a:lang

" Save the current line in a variable cause we need to modify it
" temporarily
  let ids = tempname()
  let lin = getline(".")
  let re2 = " 2>/dev/null"
  let cmd = "1,.w !" . cpp . parser . ">" . ids . re2

  if col(".") < col("$") - 1
    norm ld$
  en

" Parse the file
" TODO: check if grep "No such file or" and if so echo "Fix includes for CG"
  sil! exe cmd

" Restore
  cal setline(line("."), lin)

  if !v:shell_error
    let tip = system("cat " . ids)
    cal s:ShowTip(tip)
  en

  if col(".") == col("$") - 1
    star!
  el
    norm l
    star
  en
endfunction

"---
" Shows the list of identifiers correct at current cursor
" position for C/C++
"
function! s:OpenList(namespace)
" Create a variable to use if splitting vertically
  let splitMode = ""
  let cguessWinSize = g:cguessWinSizeHoriz
  if g:cguessVertical == 1
    let splitMode = "vertical"
    let cguessWinSize = g:cguessWinSizeVert
  endif

" Save the user's settings for splitbelow and splitright
  let savesplitbelow = &splitbelow
  let savesplitright = &splitright

  let startcmd = splitMode . " " . cguessWinSize . "new " . a:namespace
  let &splitbelow = g:cguessSplitBelow
  let &splitright = g:cguessSplitRight
  silent execute startcmd
  let &splitbelow = savesplitbelow
  let &splitright = savesplitright

" Turn off the swapfile, set the buffer type so that it won't get
" written, and so that it will get deleted when it gets hidden.
  setlocal noreadonly modifiable
  setlocal noswapfile
  setlocal buftype=nofile
  setlocal bufhidden=delete
" Don't wrap around long lines
  setlocal nowrap

" No need for any insertmode abbreviations, since we don't allow
" insertions anyway!
  iabc <buffer>

" Set up some syntax highlighting
  syn match browseIdentifier	"[a-zA-Z0-9_$]+"
  syn match browseFunction	"[a-zA-Z0-9_$]*("he=e-1
  syn keyword browseType	int long short char void wchar ...
  syn keyword browseType	signed unsigned float double bool
  syn keyword browseSClass	static register auto operator
  syn keyword browseSClass	volatile extern const
  syn keyword browseStruct	class struct union enum namespace
  syn match browseOperator	"[\*,~+\\/=!\\^&|<>\[\]\?-]"
  syn keyword browseOperator	new delete

  hi def link browseIdentifier	Statement
  hi def link browseFunction	Macro
  hi def link browseOperator	String
  hi def link browseSClass	Special
  hi def link browseStruct	Structure
  hi def link browseType	Keyword

" Fill the list
  call s:ShowList()

" Set up mappings for this buffer
  let cpo_save = &cpo
  se cpo&vim

" TODO: fix "::", "->", "."
  no <buffer> <cr> :call <SID>Selected("")<cr>a
  no <buffer> <silent> <space> :call <SID>Selected(" ")<cr>a
  no <buffer> <silent> ( :call <SID>Selected("(")<cr>a
  no <buffer> <silent> ) :call <SID>Selected(")")<cr>a
  no <buffer> <silent> ; :call <SID>Selected(";")<cr>a
  no <buffer> <silent> : :call <SID>Selected(":")<cr>a
  no <buffer> <silent> , :call <SID>Selected(",")<cr>a
  no <buffer> <silent> . :call <SID>Selected(".")<cr>a
  no <buffer> <silent> = :call <SID>Selected("=")<cr>a
  no <buffer> <silent> - :call <SID>Selected("-")<cr>a
  no <buffer> <silent> * :q<cr>a*
  no <buffer> <silent> <esc><esc> :q<cr>a
  let key = char2nr('a')
  wh key <= char2nr('z')
    exe "no <buffer> <silent> " . nr2char(key)
    \ . " :call <SID>Search(\"" . nr2char(key) . "\")<cr>"
    let key = key + 1
  endw

  let &cpo = cpo_save

" prevent the buffer from being modified
  setlocal readonly nomodifiable nomodified
endfunction

"---
" Removes type info from an identifier's description
" and leaves only the identifier name.
"
function! s:Strip(text)
  retu substitute(a:text, "[ (].*", "", "")
endfunction

"---
" Called when an item has been selected on a list,
" inserts the given text in to the editing buffer
"
function! s:Selected(text)
  let ln = getline(".")
  let wd = s:Strip(ln)
  let cm = "norm a" . wd . a:text
  clo
" TODO: before calling this disable the key mappings
" set by the script.
  exe cm
" star
endfunction

""---
" Called when a user types a letter while in the
" choice box, finds the first line that matches
"
" Note: This needs to be improved
"
function! s:Search(char)
  if search("^" . a:char, 'w') == 0
    echo "Not found"
"   beep()
  endif
endfunction

"---
" Output the list of identifiers into the current buffer
"
function! s:ShowList()
" Delete all lines
  0,$d _

" Prevent a report of our actions from showing up
  let oldRep = &report
  let save_sc = &sc
  set report=10000 nosc

" Insert ids
  sil exe s:ids
" sil! %s/\.//g

" Jump to top
  0
  d

" Restore
  let &report = oldRep
  let &sc = save_sc
endfunction

"---
" Displays a tip about the prototype of a function whose
" name was typed most recently.
" 
function! s:ShowTip(tipstring)
  let g:cguessTip = substitute(a:tipstring, "\n", "", "g")

  if !exists("s:tipBeingShown")
    let s:tipBeingShown = 1
    let s:oldStatusline = &statusline
    let s:oldLaststatus = &laststatus
"   TODO: combine the user's statusline and the tip
    set statusline=prototype:\ %{g:cguessTip}
    set laststatus=2

"   TODO: ignore ')', ';' or '}' in a string literal
    ino <buffer> <silent> <esc> <esc>:call <SID>HideTip()<cr>
    ino <buffer> <silent> ) <esc>:call <SID>HideTip()<cr>a)
    ino <buffer> <silent> ; <esc>:call <SID>HideTip()<cr>a;
    ino <buffer> <silent> } <esc>:call <SID>HideTip()<cr>a}
  endif
endfunction

"---
" Hides the previously displayed tip and removes mappings.
"
function! s:HideTip()
  if exists("s:tipBeingShown")
    let cmd = "set statusline=" . escape(s:oldStatusline, "\\ ")
    exe cmd
    let cmd = "set laststatus=" . s:oldLaststatus
    exe cmd

    unl s:oldStatusline
    unl s:oldLaststatus
    unl s:tipBeingShown

    iu <buffer> <silent> <esc>
    iu <buffer> <silent> )
    iu <buffer> <silent> ;
    iu <buffer> <silent> }
  end
endfunction

"---
" Makes key mappings respectively to the programming
" language given
"
function! s:SetMappings(filetype)
" We can use exactly the same function for all six cases
" because of the similarity between C and Java(tm)

  if a:filetype == "c" || a:filetype == "cpp"
"   C dot operator
    exe "inoremap <buffer> <silent> <unique> . .<esc>:call "
	  \ . "<SID>TriggerList(\"" . a:filetype . "\")<cr>"
"   C dereference member operator
    exe "inoremap <buffer> <silent> <unique> -> -><esc>:call "
	  \ . "<SID>TriggerList(\"" . a:filetype . "\")<cr>"
"   C++ scope operator
    exe "inoremap <buffer> <silent> <unique> :: ::<esc>:call "
	  \ . "<SID>TriggerList(\"" . a:filetype . "\")<cr>"
"   C left parenthesis
    exe "inoremap <buffer> <silent> <unique> ( (<esc>:call "
	  \ . "<SID>TriggerTip(\"" . a:filetype . "\")<cr>"
"   C equal equal operator
    exe "inoremap <buffer> <silent> <unique> == == <esc>:call "
	  \ . "<SID>TriggerList(\"" . a:filetype . "\")<cr>"
"   C not equal operator
    exe "inoremap <buffer> <silent> <unique> != != <esc>:call "
	  \ . "<SID>TriggerList(\"" . a:filetype . "\")<cr>"
  endif

  if a:filetype == "java"
"   Java(tm) dot operator
    inoremap <buffer> <silent> <unique> . .<esc>:call <SID>TriggerList("java")<cr>
"   Java(tm) left parenthesis
    inoremap <buffer> <silent> <unique> ( (<esc>:call <SID>TriggerTip("java")<cr>
  endif
endfunction

"---
" Set up the autocommand to allow the key mappings to be made
" only for files in supported languages
"
augroup cguess
  autocmd!
  autocmd FileType c,cpp,java call s:SetMappings(expand("<amatch>"))
augroup end

" restore 'cpo'
let &cpo = s:cpo_save
unlet s:cpo_save

" vim: set sw=2 :
