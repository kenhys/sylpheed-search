#include <glib.h>
#include <glib/gprintf.h>
#include <gtk/gtk.h>

#include "sylpf_utility.h"
#include "sylmain.h"
#include "plugin.h"
#include "folder.h"
#include "procmsg.h"

#include "sylsearch.h"

#define TABLE_MAIL "Mail"

int main(int argc, char *argv[])
{
  grn_ctx ctx;
  grn_obj obj;
  grn_obj *db;
  grn_db_create_optarg optarg;
  grn_obj *table;

  grn_obj *shorttext_type;
  grn_obj_flags body_flags;

  grn_init();

  grn_ctx_init(&ctx, GRN_CTX_USE_QL);

  GRN_DB_OPEN_OR_CREATE(&ctx, "sylsearch.db", NULL, db);
  grn_set_default_encoding(GRN_ENC_UTF8);

  shorttext_type = grn_ctx_at(&ctx, GRN_DB_SHORT_TEXT);
  GRN_TABLE_OPEN_OR_CREATE(&ctx,
                           TABLE_MAIL, strlen(TABLE_MAIL),
                           NULL,
                           GRN_OBJ_PERSISTENT|GRN_OBJ_TABLE_PAT_KEY|GRN_OBJ_KEY_NORMALIZE,
                           shorttext_type, NULL, table);

  body_flags = GRN_OBJ_PERSISTENT|GRN_OBJ_COLUMN_INDEX|GRN_OBJ_WITH_POSITION;
  grn_column_create(&ctx, table, "body", 4, NULL,
                    body_flags, shorttext_type);
  grn_obj_close(&ctx, table);

  grn_ctx_fin(&ctx);

  grn_fin();

  return 0;
}
