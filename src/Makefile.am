## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = interface

interface_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	login.c login.h \
	electeur.c electeur.h \
	observateur.c observateur.h \
	treeview.c treeview.h \
	lecture.c lecture.h \
	election.c election.h \
	stat.c stat.h \
	controle_saisie.c controle_saisie.h

interface_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

