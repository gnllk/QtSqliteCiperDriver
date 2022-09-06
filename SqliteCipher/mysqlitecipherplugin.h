#ifndef MYSQLITECIPHERPLUGIN_H
#define MYSQLITECIPHERPLUGIN_H

#include <QSqlDriverPlugin>

class MySqliteCipherPlugin : public QSqlDriverPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QSqlDriverFactoryInterface_iid FILE "MySqliteCipher.json")

public:
    explicit MySqliteCipherPlugin(QObject *parent = nullptr);

private:
    QSqlDriver *create(const QString &key) override;
};

#endif // MYSQLITECIPHERPLUGIN_H
