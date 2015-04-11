
lib_LTLIBRARIES = sylsearch.la

sylpf_dir = $(top_srcdir)/../sylplugin_factory

sylsearch_la_SOURCES = sylsearch.c sylsearch.h
sylsearch_la_LDFLAGS = -module -no-undefined -avoid-version -lgroonga
sylsearch_la_CFLAGS = `pkg-config --cflags groonga`


AM_CPPFLAGS = \
	$(GTK_CFLAGS) \
	-I$(includedir) \
	-I$(sylpheed_build_dir) \
	-I$(sylpheed_build_dir)/libsylph \
	-I$(sylpheed_build_dir)/src \
	-I$(sylpf_dir)/src

sylsearch_la_LIBADD = \
	$(GTK_LIBS) \
	$(sylpheed_build_dir)/src/libsylpheed-plugin-0.la \
	$(sylpheed_build_dir)/libsylph/libsylph-0.la

bin_PROGRAMS = sylsearch-import

sylsearch_import_CFLAGS = \
        $(AM_CFLAGS) \
        $(GTK_CFLAGS) \
	`pkg-config --cflags groonga`

sylsearch_import_LDFLAGS = `pkg-config --libs groonga`

sylsearch_import_LDADD = \
        $(GTK_LIBS) \
        $(sylpheed_build_dir)/src/libsylpheed-plugin-0.la \
        $(sylpheed_build_dir)/libsylph/libsylph-0.la

sylsearch_import_SOURCES = \
        $(sylpf_dir)/src/sylplugin_factory.c \
        sylsearch-import.c

install:
install-plugin: install-am
