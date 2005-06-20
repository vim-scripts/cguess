# 1 "main.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "main.c"



# 1 "/usr/include/stdio.h" 1 3 4
# 28 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 295 "/usr/include/features.h" 3 4
# 1 "/usr/include/sys/cdefs.h" 1 3 4
# 296 "/usr/include/features.h" 2 3 4
# 318 "/usr/include/features.h" 3 4
# 1 "/usr/include/gnu/stubs.h" 1 3 4
# 319 "/usr/include/features.h" 2 3 4
# 29 "/usr/include/stdio.h" 2 3 4





# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 213 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 3 4
typedef unsigned int size_t;
# 35 "/usr/include/stdio.h" 2 3 4

# 1 "/usr/include/bits/types.h" 1 3 4
# 28 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 29 "/usr/include/bits/types.h" 2 3 4


# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 32 "/usr/include/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
# 63 "/usr/include/bits/types.h" 3 4
typedef struct
{
  long __val[2];
} __quad_t;
typedef struct
{
  __u_long __val[2];
} __u_quad_t;
# 128 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/typesizes.h" 1 3 4
# 129 "/usr/include/bits/types.h" 2 3 4


typedef unsigned long long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned int __nlink_t;
typedef long int __off_t;
typedef long long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef long int __swblk_t;
typedef int __key_t;


typedef int __clockid_t;


typedef int __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long long int __fsfilcnt64_t;




typedef int __ssize_t;
typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


typedef int __intptr_t;


typedef unsigned int __socklen_t;
# 37 "/usr/include/stdio.h" 2 3 4









typedef struct _IO_FILE FILE;





# 62 "/usr/include/stdio.h" 3 4
typedef struct _IO_FILE __FILE;
# 72 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/libio.h" 1 3 4
# 32 "/usr/include/libio.h" 3 4
# 1 "/usr/include/_G_config.h" 1 3 4
# 14 "/usr/include/_G_config.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 325 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 3 4
typedef long int wchar_t;
# 354 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 3 4
typedef unsigned int wint_t;
# 15 "/usr/include/_G_config.h" 2 3 4
# 24 "/usr/include/_G_config.h" 3 4
# 1 "/usr/include/wchar.h" 1 3 4
# 48 "/usr/include/wchar.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 49 "/usr/include/wchar.h" 2 3 4

# 1 "/usr/include/bits/wchar.h" 1 3 4
# 51 "/usr/include/wchar.h" 2 3 4
# 76 "/usr/include/wchar.h" 3 4
typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
# 25 "/usr/include/_G_config.h" 2 3 4

typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
# 44 "/usr/include/_G_config.h" 3 4
# 1 "/usr/include/gconv.h" 1 3 4
# 28 "/usr/include/gconv.h" 3 4
# 1 "/usr/include/wchar.h" 1 3 4
# 48 "/usr/include/wchar.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 49 "/usr/include/wchar.h" 2 3 4
# 29 "/usr/include/gconv.h" 2 3 4


# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 32 "/usr/include/gconv.h" 2 3 4





enum
{
  __GCONV_OK = 0,
  __GCONV_NOCONV,
  __GCONV_NODB,
  __GCONV_NOMEM,

  __GCONV_EMPTY_INPUT,
  __GCONV_FULL_OUTPUT,
  __GCONV_ILLEGAL_INPUT,
  __GCONV_INCOMPLETE_INPUT,

  __GCONV_ILLEGAL_DESCRIPTOR,
  __GCONV_INTERNAL_ERROR
};



enum
{
  __GCONV_IS_LAST = 0x0001,
  __GCONV_IGNORE_ERRORS = 0x0002
};



struct __gconv_step;
struct __gconv_step_data;
struct __gconv_loaded_object;
struct __gconv_trans_data;



typedef int (*__gconv_fct) (struct __gconv_step *, struct __gconv_step_data *,
                            const unsigned char **, const unsigned char *,
                            unsigned char **, size_t *, int, int);


typedef wint_t (*__gconv_btowc_fct) (struct __gconv_step *, unsigned char);


typedef int (*__gconv_init_fct) (struct __gconv_step *);
typedef void (*__gconv_end_fct) (struct __gconv_step *);



typedef int (*__gconv_trans_fct) (struct __gconv_step *,
                                  struct __gconv_step_data *, void *,
                                  const unsigned char *,
                                  const unsigned char **,
                                  const unsigned char *, unsigned char **,
                                  size_t *);


typedef int (*__gconv_trans_context_fct) (void *, const unsigned char *,
                                          const unsigned char *,
                                          unsigned char *, unsigned char *);


typedef int (*__gconv_trans_query_fct) (const char *, const char ***,
                                        size_t *);


typedef int (*__gconv_trans_init_fct) (void **, const char *);
typedef void (*__gconv_trans_end_fct) (void *);

struct __gconv_trans_data
{

  __gconv_trans_fct __trans_fct;
  __gconv_trans_context_fct __trans_context_fct;
  __gconv_trans_end_fct __trans_end_fct;
  void *__data;
  struct __gconv_trans_data *__next;
};



struct __gconv_step
{
  struct __gconv_loaded_object *__shlib_handle;
  const char *__modname;

  int __counter;

  char *__from_name;
  char *__to_name;

  __gconv_fct __fct;
  __gconv_btowc_fct __btowc_fct;
  __gconv_init_fct __init_fct;
  __gconv_end_fct __end_fct;



  int __min_needed_from;
  int __max_needed_from;
  int __min_needed_to;
  int __max_needed_to;


  int __stateful;

  void *__data;
};



struct __gconv_step_data
{
  unsigned char *__outbuf;
  unsigned char *__outbufend;



  int __flags;



  int __invocation_counter;



  int __internal_use;

  __mbstate_t *__statep;
  __mbstate_t __state;



  struct __gconv_trans_data *__trans;
};



typedef struct __gconv_info
{
  size_t __nsteps;
  struct __gconv_step *__steps;
  struct __gconv_step_data __data [1];
} *__gconv_t;
# 45 "/usr/include/_G_config.h" 2 3 4
typedef union
{
  struct __gconv_info __cd;
  struct
  {
    struct __gconv_info __cd;
    struct __gconv_step_data __data;
  } __combined;
} _G_iconv_t;

typedef int _G_int16_t ;
typedef int _G_int32_t ;
typedef unsigned int _G_uint16_t ;
typedef unsigned int _G_uint32_t ;
# 33 "/usr/include/libio.h" 2 3 4
# 53 "/usr/include/libio.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stdarg.h" 1 3 4
# 43 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 54 "/usr/include/libio.h" 2 3 4
# 162 "/usr/include/libio.h" 3 4
struct _IO_jump_t; struct _IO_FILE;
# 172 "/usr/include/libio.h" 3 4
typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
# 195 "/usr/include/libio.h" 3 4
};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
# 263 "/usr/include/libio.h" 3 4
struct _IO_FILE {
  int _flags;




  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;
# 311 "/usr/include/libio.h" 3 4
  __off64_t _offset;





  void *__pad1;
  void *__pad2;

  int _mode;

  char _unused2[15 * sizeof (int) - 2 * sizeof (void *)];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
# 350 "/usr/include/libio.h" 3 4
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn (void *__cookie, const char *__buf,
                                 size_t __n);







typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn (void *__cookie);
# 402 "/usr/include/libio.h" 3 4
extern int __underflow (_IO_FILE *) ;
extern int __uflow (_IO_FILE *) ;
extern int __overflow (_IO_FILE *, int) ;
extern wint_t __wunderflow (_IO_FILE *) ;
extern wint_t __wuflow (_IO_FILE *) ;
extern wint_t __woverflow (_IO_FILE *, wint_t) ;
# 432 "/usr/include/libio.h" 3 4
extern int _IO_getc (_IO_FILE *__fp) ;
extern int _IO_putc (int __c, _IO_FILE *__fp) ;
extern int _IO_feof (_IO_FILE *__fp) ;
extern int _IO_ferror (_IO_FILE *__fp) ;

extern int _IO_peekc_locked (_IO_FILE *__fp) ;





extern void _IO_flockfile (_IO_FILE *) ;
extern void _IO_funlockfile (_IO_FILE *) ;
extern int _IO_ftrylockfile (_IO_FILE *) ;
# 462 "/usr/include/libio.h" 3 4
extern int _IO_vfscanf (_IO_FILE * , const char * ,
                        __gnuc_va_list, int *) ;
extern int _IO_vfprintf (_IO_FILE *, const char *,
                         __gnuc_va_list) ;
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t) ;
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t) ;

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int) ;
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int) ;

extern void _IO_free_backup_area (_IO_FILE *) ;
# 73 "/usr/include/stdio.h" 2 3 4
# 86 "/usr/include/stdio.h" 3 4


typedef _G_fpos_t fpos_t;




# 138 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/stdio_lim.h" 1 3 4
# 139 "/usr/include/stdio.h" 2 3 4



extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;







extern int remove (const char *__filename) ;

extern int rename (const char *__old, const char *__new) ;









extern FILE *tmpfile (void);
# 178 "/usr/include/stdio.h" 3 4
extern char *tmpnam (char *__s) ;





extern char *tmpnam_r (char *__s) ;
# 196 "/usr/include/stdio.h" 3 4
extern char *tempnam (const char *__dir, const char *__pfx)
     ;








extern int fclose (FILE *__stream);




extern int fflush (FILE *__stream);

# 221 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 235 "/usr/include/stdio.h" 3 4






extern FILE *fopen (const char * __filename,
                    const char * __modes);




extern FILE *freopen (const char * __filename,
                      const char * __modes,
                      FILE * __stream);
# 262 "/usr/include/stdio.h" 3 4

# 273 "/usr/include/stdio.h" 3 4
extern FILE *fdopen (int __fd, const char *__modes) ;
# 294 "/usr/include/stdio.h" 3 4



extern void setbuf (FILE * __stream, char * __buf) ;



extern int setvbuf (FILE * __stream, char * __buf,
                    int __modes, size_t __n) ;





extern void setbuffer (FILE * __stream, char * __buf,
                       size_t __size) ;


extern void setlinebuf (FILE *__stream) ;








extern int fprintf (FILE * __stream,
                    const char * __format, ...);




extern int printf (const char * __format, ...);

extern int sprintf (char * __s,
                    const char * __format, ...) ;





extern int vfprintf (FILE * __s, const char * __format,
                     __gnuc_va_list __arg);




extern int vprintf (const char * __format, __gnuc_va_list __arg);

extern int vsprintf (char * __s, const char * __format,
                     __gnuc_va_list __arg) ;





extern int snprintf (char * __s, size_t __maxlen,
                     const char * __format, ...)
     ;

extern int vsnprintf (char * __s, size_t __maxlen,
                      const char * __format, __gnuc_va_list __arg)
     ;

# 388 "/usr/include/stdio.h" 3 4





extern int fscanf (FILE * __stream,
                   const char * __format, ...);




extern int scanf (const char * __format, ...);

extern int sscanf (const char * __s,
                   const char * __format, ...) ;

# 430 "/usr/include/stdio.h" 3 4





extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);

# 454 "/usr/include/stdio.h" 3 4
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
# 465 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream);








extern int fputc (int __c, FILE *__stream) ;
extern int putc (int __c, FILE *__stream) ;





extern int putchar (int __c);

# 495 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream) ;


extern int putw (int __w, FILE *__stream) ;








extern char *fgets (char * __s, int __n, FILE * __stream);






extern char *gets (char *__s);

# 575 "/usr/include/stdio.h" 3 4





extern int fputs (const char * __s, FILE * __stream);





extern int puts (const char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void * __ptr, size_t __size,
                     size_t __n, FILE * __stream);




extern size_t fwrite (const void * __ptr, size_t __size,
                      size_t __n, FILE * __s);

# 628 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void * __ptr, size_t __size,
                              size_t __n, FILE * __stream) ;
extern size_t fwrite_unlocked (const void * __ptr, size_t __size,
                               size_t __n, FILE * __stream) ;








extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream);




extern void rewind (FILE *__stream);

# 683 "/usr/include/stdio.h" 3 4






extern int fgetpos (FILE * __stream, fpos_t * __pos);




extern int fsetpos (FILE *__stream, const fpos_t *__pos);
# 706 "/usr/include/stdio.h" 3 4

# 715 "/usr/include/stdio.h" 3 4


extern void clearerr (FILE *__stream) ;

extern int feof (FILE *__stream) ;

extern int ferror (FILE *__stream) ;




extern void clearerr_unlocked (FILE *__stream) ;
extern int feof_unlocked (FILE *__stream) ;
extern int ferror_unlocked (FILE *__stream) ;








extern void perror (const char *__s);






# 1 "/usr/include/bits/sys_errlist.h" 1 3 4
# 27 "/usr/include/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern const char *const sys_errlist[];
# 745 "/usr/include/stdio.h" 2 3 4




extern int fileno (FILE *__stream) ;




extern int fileno_unlocked (FILE *__stream) ;






extern FILE *popen (const char *__command, const char *__modes) ;


extern int pclose (FILE *__stream) ;





extern char *ctermid (char *__s) ;
# 798 "/usr/include/stdio.h" 3 4
extern void flockfile (FILE *__stream) ;



extern int ftrylockfile (FILE *__stream) ;


extern void funlockfile (FILE *__stream) ;
# 822 "/usr/include/stdio.h" 3 4

# 5 "main.c" 2

# 1 "parser.h" 1
# 11 "parser.h"
typedef char *token_val_t;

int parse();
void error(const char *s);
# 7 "main.c" 2
extern int line;

int main(int argc, char *argv[]) {
        printf("%i\n", parse());
        printf("%i\n", line);
        return 0;
}

void error(const char *s) {
        fprintf(stderr, "%s\n", s);
}
