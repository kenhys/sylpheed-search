libdir = $(plugindir)

lib_LTLIBRARIES = sylsearch.la

sylpf_dir = $(top_srcdir)/plugin/sylplugin_factory

sylsearch_la_SOURCES = sylsearch.c sylsearch.h
sylsearch_la_LDFLAGS = -module -no-undefined -avoid-version -lgroonga


INCLUDES = \
	$(GTK_CFLAGS) \
	-I$(includedir) \
	-I$(top_srcdir) \
	-I$(top_srcdir)/libsylph \
	-I$(top_srcdir)/src \
	-I$(sylpf_dir)/src

sylsearch_la_LIBADD = \
	$(GTK_LIBS) \
        $(top_builddir)/src/libsylpheed-plugin-0.la \
	$(top_builddir)/libsylph/libsylph-0.la

install:
install-plugin: install-am
