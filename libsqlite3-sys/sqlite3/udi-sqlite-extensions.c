#include <stdio.h>
#include "sqlite3ext.h"
SQLITE_EXTENSION_INIT1

int sqlite3_html_init(sqlite3 *, char **, const sqlite3_api_routines *);

int udi_sqlite_init_extensions(sqlite3 *db, char **pzErrMsg,
                               const sqlite3_api_routines *pApi)
{
  (void)pzErrMsg;
  SQLITE_EXTENSION_INIT2(pApi);
  int rc = SQLITE_OK;
  sqlite3_stmt *stmt;
  char *error_message;

  rc = sqlite3_auto_extension((void (*)())sqlite3_html_init);
  if (rc != SQLITE_OK)
  {
    fprintf(stderr, "❌ udi-sqlite-extensions.c could not load sqlite3_html_init: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  return SQLITE_OK;
}
