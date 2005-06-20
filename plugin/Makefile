include ../config
all: cguess.vim
cguess.vim:
install: all
	for i in $(PLUGIN_DIR); do	\
		$(INSTALL) -d $$i;	\
		$(INSTALL) -m 00644 cguess.vim $$i;	\
	done
uninstall:
	for i in $(PLUGIN_DIR); do	\
		$(RM) $$i/cguess.vim;	\
	done
clean:
	$(RM) *.o
