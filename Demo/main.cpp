#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#define DATABASE_PATH                   "./Database/"
#define DATABASE_DEFAULT_CONNECTION     "qt_sql_default_connection"
#define DATABASE_FILE                   "test.db"

bool execSql(const QString& sql, QSqlDatabase db = QSqlDatabase::database(DATABASE_DEFAULT_CONNECTION)){
    QSqlQuery query1(sql, db);
    bool ret = query1.exec();
    if(!ret){
        qDebug() << "Failed to exec sql: " + sql;
    }
    query1.finish();
    return ret;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString dataBasePath = QString(DATABASE_PATH) + QString(DATABASE_FILE);
    //create Database folder
    QDir dbDir(DATABASE_PATH);
    if(!dbDir.exists()){
        dbDir.mkdir(dbDir.absolutePath());
    }

    qDebug() << "Supported:" << QSqlDatabase::drivers();
    QSqlDatabase m_dataBase;
    if(QSqlDatabase::contains(DATABASE_DEFAULT_CONNECTION)){
        qDebug() << "use existed db";
        m_dataBase = QSqlDatabase::database(DATABASE_DEFAULT_CONNECTION);
    }else{
        qDebug() << "create new db";
        m_dataBase = QSqlDatabase::addDatabase("QSQLITEEX", DATABASE_DEFAULT_CONNECTION);
        m_dataBase.setPassword("123456");
        m_dataBase.setDatabaseName(dataBasePath);
    }
    if(!m_dataBase.isOpen()){
        m_dataBase.open();
    }

    execSql("CREATE TABLE IF NOT EXISTS Test1 (id INTEGER PRIMARY KEY AUTOINCREMENT, name text)");
    execSql("INSERT INTO Test1 VALUES (NULL, 'Jack')");

    QSqlQuery query3("SELECT * FROM Test1", QSqlDatabase::database(DATABASE_DEFAULT_CONNECTION));
    if(!query3.exec()){
        qDebug() << "Failed to execute SELECT";
    }else if(query3.next()){
        QString name = query3.value("name").toString();
        qDebug() << "Name:" << name;
    }
    query3.finish();

    qDebug() << "Completed";
    return a.exec();
}
