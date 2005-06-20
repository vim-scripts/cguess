# cguess - C/C++/Java(tm) auto-completion tool for VIM
# Copyright (C) 2005 Andrzej Zaborowski <balrog@zabor.org>
# All Rights Reserved
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS''
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
# PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
# OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
include config

SUBDIRS=plugin doc tests
OBJECTS=scanner.o c++.o stack.o context.o scope.o type.o list.o identifier.o symbols.o builtin.o cguess.o tree.o sstack.o operator.o language.o

all: config cguess sub-all
cguess: $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $@
scanner.o: y.tab.h
y.tab.h: c++.o
install: config all sub-install
	$(INSTALL) -s -m 00755 cguess $(PREFIX)/bin
uninstall: config sub-uninstall
	$(RM) $(PREFIX)/bin/cguess
verbose:
	$(YACC) -dr all -v -t -k c++.y
clean: sub-clean
	$(RM) *.o y.* cguess c++.c scanner.c *-dist *.core
tarball:
	$(MAKE) clean
	$(MAKE) all
	$(MAKE) clean
	$(MAKE) dist
	cd ..;	\
	tar -cvjf cguess-$(VERSION).tar.bz2 \
	--exclude=cguess-$(VERSION)/config cguess-$(VERSION)/ \
	--exclude=cguess-$(VERSION)/config.vim
dist: c++.c scanner.c
	mv -f c++.c c++.c-dist
	mv -f scanner.c scanner.c-dist
	mv -f y.tab.h y.tab.h-dist

sub-all sub-install sub-uninstall sub-clean:
	target=`echo $@ | sed s/sub-//`;	\
	for i in $(SUBDIRS); do			\
		$(MAKE) -C $$i $$target;	\
	done
