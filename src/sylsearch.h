#ifndef __SYLSEARCH_H_INCLUDED__
#define __SYLSEARCH_H_INCLUDED__

#include "groonga.h"

#define SYLPF_SYLPHEEDRC "sylsearchrc"

#define SYLPF_ID "sylsearch"

typedef struct  _SylSearchOption SylSearchOption;
struct _SylSearchOption {
  gchar *rcpath;
  GKeyFile *rcfile;

  gboolean plugin_enabled;

  GtkWidget *plugin_on;
  GtkWidget *plugin_off;
  GtkWidget *plugin_switch;
  GtkTooltips *plugin_tooltip;
};


#endif
