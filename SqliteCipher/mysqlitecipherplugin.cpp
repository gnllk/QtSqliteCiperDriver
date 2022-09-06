#include "mysqlitecipherplugin.h"
#ifdef OS_WIN
#include "qsql_sqliteex_p.h"
#else
#include "qsql_sqliteex_p_qt5.6.0.h"
#endif

MySqliteCipherPlugin::MySqliteCipherPlugin(QObject *parent)
    : QSqlDriverPlugin(parent)
{
}

QSqlDriver *MySqliteCipherPlugin::create(const QString &key)
{
    if (key == QLatin1String("QSQLITEEX")) {
        QSQLiteExDriver* driver = new QSQLiteExDriver();
        return driver;
    }
    return 0;
}
