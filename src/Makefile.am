
lib_LTLIBRARIES = sylsearch.la

sylpf_dir = $(top_srcdir)/../sylplugin_factory

sylsearch_la_SOURCES = sylsearch.c sylsearch.h
sylsearch_la_LDFLAGS = -module -no-undefined -avoid-version -lgroonga


INCLUDES = \
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

install:
install-plugin: install-am
