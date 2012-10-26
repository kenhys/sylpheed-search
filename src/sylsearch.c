/*
 * SylSearch -- The groonga based full text search plugin for Sylpheed
 * Copyright (C) 2012 HAYASHI Kentaro
 *
 */

#include <glib.h>
#include <glib/gprintf.h>
#include <gtk/gtk.h>

#include "sylpf_utility.h"
#include "sylmain.h"
#include "plugin.h"
#include "folder.h"
#include "procmsg.h"

#include "sylsearch.h"

static SylPluginInfo info = {
  N_("SylSearch Plugin"),
  "0.1.0",
  "HAYASHI Kentaro",
  N_("Full text search plug-in for Sylpheed")
};

static void init_done_cb(GObject *obj, gpointer data);
static void app_exit_cb(GObject *obj, gpointer data);

static void folderview_menu_popup_cb(GObject *obj, GtkItemFactory *ifactory,
				     gpointer data);
static void summaryview_menu_popup_cb(GObject *obj, GtkItemFactory *ifactory,
				      gpointer data);

static void textview_menu_popup_cb(GObject *obj, GtkMenu *menu,
				   GtkTextView *textview,
				   const gchar *uri,
				   const gchar *selected_text,
				   MsgInfo *msginfo);

static void menu_selected_cb(void);

static void messageview_show_cb(GObject *obj, gpointer msgview,
				MsgInfo *msginfo, gboolean all_headers);
static void inc_start_cb(GObject *obj, PrefsAccount *ac);
static void inc_finished_cb(GObject *obj, gint new_messages);

static void create_window(void);
static void create_folderview_sub_widget(void);

void plugin_load(void)
{
#define SYLPF_FUNC_NAME "plugin_load"
  SYLPF_START_FUNC;

  syl_plugin_add_menuitem("/Tools", NULL, NULL, NULL);
  syl_plugin_add_menuitem("/Tools", "SylSearch settings [sylsearch]",
                          create_window, NULL);

  g_signal_connect_after(syl_app_get(), "init-done", G_CALLBACK(init_done_cb),
			 NULL);
  syl_plugin_signal_connect("folderview-menu-popup",
                            G_CALLBACK(folderview_menu_popup_cb), NULL);
  syl_plugin_signal_connect("summaryview-menu-popup",
                            G_CALLBACK(summaryview_menu_popup_cb), NULL);
  syl_plugin_signal_connect("textview-menu-popup",
                            G_CALLBACK(textview_menu_popup_cb), NULL);
  syl_plugin_signal_connect("compose-created",
                            G_CALLBACK(compose_created_cb), NULL);
  syl_plugin_signal_connect("compose-destroy",
                            G_CALLBACK(compose_destroy_cb), NULL);
  syl_plugin_signal_connect("compose-send",
                            G_CALLBACK(compose_send_cb), NULL);
  syl_plugin_signal_connect("messageview-show",
                            G_CALLBACK(messageview_show_cb), NULL);
  syl_plugin_signal_connect("inc-mail-start",
                            G_CALLBACK(inc_start_cb), NULL);
  syl_plugin_signal_connect("inc-mail-finished",
                            G_CALLBACK(inc_finished_cb), NULL);
  
  SYLPF_END_FUNC;
#undef SYLPF_FUNC_NAME  
}

void plugin_unload(void)
{
#define SYLPF_FUNC_NAME "plugin_unload"
  SYLPF_START_FUNC;
  
  SYLPF_END_FUNC;
#undef SYLPF_FUNC_NAME
}

SylPluginInfo *plugin_info(void)
{
#define SYLPF_FUNC_NAME "plugin_info"
  SYLPF_START_FUNC;
  
  SYLPF_END_FUNC;
#undef SYLPF_FUNC_NAME
  return &info;
}

gint plugin_interface_version(void)
{
#define SYLPF_FUNC_NAME "plugin_interface_version"
  SYLPF_START_FUNC;
  
  SYLPF_END_FUNC;
#undef SYLPF_FUNC_NAME
  return SYL_PLUGIN_INTERFACE_VERSION;
}

static void init_done_cb(GObject *obj, gpointer data)
{
#define SYLPF_FUNC_NAME "init_done_cb"
  SYLPF_START_FUNC;
  
  SYLPF_END_FUNC;
#undef SYLPF_FUNC_NAME
}

static void app_exit_cb(GObject *obj, gpointer data)
{
#define SYLPF_FUNC_NAME "app_exit_cb"
  SYLPF_START_FUNC;
  
  SYLPF_END_FUNC;
#undef SYLPF_FUNC_NAME
}

static void folderview_menu_popup_cb(GObject *obj, GtkItemFactory *ifactory,
				     gpointer data)
{
#define SYLPF_FUNC_NAME "folderview_menu_popup_cb"
  SYLPF_START_FUNC;
  
  SYLPF_END_FUNC;
#undef SYLPF_FUNC_NAME
}

static void summaryview_menu_popup_cb(GObject *obj, GtkItemFactory *ifactory,
				      gpointer data)
{
#define SYLPF_FUNC_NAME "folderview_menu_popup_cb"
  SYLPF_START_FUNC;
  
  SYLPF_END_FUNC;
#undef SYLPF_FUNC_NAME
}

static void activate_menu_cb(GtkMenuItem *menuitem, gpointer data)
{
#define SYLPF_FUNC_NAME "activate_menu_cb"
  SYLPF_START_FUNC;
  
  SYLPF_END_FUNC;
#undef SYLPF_FUNC_NAME
}

static void textview_menu_popup_cb(GObject *obj, GtkMenu *menu,
				   GtkTextView *textview,
				   const gchar *uri,
				   const gchar *selected_text,
				   MsgInfo *msginfo)
{
#define SYLPF_FUNC_NAME "textview_menu_popup_cb"
  SYLPF_START_FUNC;
  
  SYLPF_END_FUNC;
#undef SYLPF_FUNC_NAME
}

static void menu_selected_cb(void)
{
#define SYLPF_FUNC_NAME "menu_selected_cb"
  SYLPF_START_FUNC;
  
  SYLPF_END_FUNC;
#undef SYLPF_FUNC_NAME
}

static void messageview_show_cb(GObject *obj, gpointer msgview,
				MsgInfo *msginfo, gboolean all_headers)
{
#define SYLPF_FUNC_NAME "messageview_show_cb"
  SYLPF_START_FUNC;
  
  SYLPF_END_FUNC;
#undef SYLPF_FUNC_NAME
}

static void inc_start_cb(GObject *obj, PrefsAccount *ac)
{
#define SYLPF_FUNC_NAME "inc_start_cb"
  SYLPF_START_FUNC;
  
  if (ac) {
    SYLPF_DEBUG_STR("account name: %s", ac->account_name);
  } else {
    SYLPF_DEBUG_MSG("all account:");
  }

  SYLPF_END_FUNC;
#undef SYLPF_FUNC_NAME
}

static void inc_finished_cb(GObject *obj, gint new_messages)
{
#define SYLPF_FUNC_NAME "inc_finished_cb"
  SYLPF_START_FUNC;
  
  SYLPF_END_FUNC;
#undef SYLPF_FUNC_NAME
}

