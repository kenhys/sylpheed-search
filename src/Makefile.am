
lib_LTLIBRARIES = sylsearch.la

sylpf_dir = $(top_srcdir)/../sylplugin_factory

sylsearch_la_SOURCES = sylsearch.c sylsearch.h
sylsearch_la_LDFLAGS = -module -no-undefined -avoid-version -lgroonga
sylsearch_la_CFLAGS = `pkg-config --cflags groonga`


AM_CPPFLAGS = \
	$(GTK_CFLAGS) \
	-I$(includedir) \
	$(SYLPHEED_CFLAGS) \
	$(SYLPF_CFLAGS)

sylsearch_la_LIBADD = \
	$(GTK_LIBS) \
	$(SYLPHEED_LIBS) \
	$(SYLPF_LIBS)

bin_PROGRAMS = sylsearch-import

sylsearch_import_CFLAGS = \
        $(AM_CFLAGS) \
        $(GTK_CFLAGS) \
	`pkg-config --cflags groonga`

sylsearch_import_LDFLAGS = `pkg-config --libs groonga`

sylsearch_import_LDADD = \
	$(GTK_LIBS) \
	$(SYLPHEED_LIBS)

sylsearch_import_SOURCES = \
	sylsearch-import.c

install:
install-plugin: install-am
