#ifndef QSQL_SQLITEEX_P_H
#define QSQL_SQLITEEX_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtSql/qsqldriver.h>

struct sqlite3;

#ifdef QT_PLUGIN
#define Q_EXPORT_SQLDRIVER_SQLITE
#else
#define Q_EXPORT_SQLDRIVER_SQLITE Q_SQL_EXPORT
#endif

QT_BEGIN_NAMESPACE

class QSqlResult;
class QSQLiteExDriverPrivate;

class Q_EXPORT_SQLDRIVER_SQLITE QSQLiteExDriver : public QSqlDriver
{
    Q_DECLARE_PRIVATE(QSQLiteExDriver)
    Q_OBJECT
    friend class QSQLiteExResultPrivate;
public:
    explicit QSQLiteExDriver(QObject *parent = 0);
    explicit QSQLiteExDriver(sqlite3 *connection, QObject *parent = 0);
    ~QSQLiteExDriver();
    bool hasFeature(DriverFeature f) const override;
    bool open(const QString & db,
                   const QString & user,
                   const QString & password,
                   const QString & host,
                   int port,
                   const QString & connOpts) override;
    void close() override;
    QSqlResult *createResult() const override;
    bool beginTransaction() override;
    bool commitTransaction() override;
    bool rollbackTransaction() override;
    QStringList tables(QSql::TableType) const override;

    QSqlRecord record(const QString& tablename) const override;
    QSqlIndex primaryIndex(const QString &table) const override;
    QVariant handle() const override;
    QString escapeIdentifier(const QString &identifier, IdentifierType) const override;

    bool subscribeToNotification(const QString &name) override;
    bool unsubscribeFromNotification(const QString &name) override;
    QStringList subscribedToNotifications() const override;
private Q_SLOTS:
    void handleNotification(const QString &tableName, qint64 rowid);
};

QT_END_NAMESPACE

#endif // QSQL_SQLITEEX_P_H
