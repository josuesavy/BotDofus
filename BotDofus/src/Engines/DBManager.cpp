#include "DBManager.h"

DBManager::DBManager(QString path)
{
    m_path = path;
    m_initialized = false;

    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName(m_path);

    initialization();
}

DBManager::DBManager()
{
    m_initialized = false;

    m_database = QSqlDatabase::addDatabase("QSQLITE");
}

void DBManager::setPath(QString path)
{
    m_path = path;
    m_database.setDatabaseName(m_path);
}

bool DBManager::addField(QString table, QString field, QByteArray value)
{
    QString request = "INSERT INTO "+table+" (field, value)"
                      "SELECT :field, :value "
                      "WHERE NOT EXISTS ("
                      "SELECT field "
                      "FROM "+table+" "
                      "WHERE field = :field"
                      ")";

    QSqlQuery query;
    query.prepare(request);
    query.bindValue(":field", field);
    query.bindValue(":value", value);

    if(query.exec())
        return true;
    else
    {
        request = "UPDATE "+table+" SET value=:value WHERE field=:field";
        query.bindValue(":field", field);
        query.bindValue(":value", value);
        if(query.exec())
            return true;
    }

    return false;
}

bool DBManager::addTable(QString name)
{
    QString request = "CREATE TABLE IF NOT EXISTS "+name+" ("
                        "id	    INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
                        "field	TEXT NOT NULL UNIQUE,"
                        "value	BLOB NOT NULL"
                      ")";

    QSqlQuery query;
    query.prepare(request);
    if (!query.exec())
    {
        qDebug() << "'"+name+"' table was not created!";
        return false;
    }

    return true;
}

QByteArray DBManager::getField(QString table, QString field)
{
    QByteArray byteArray;

    QString request = "SELECT value FROM "+table+" WHERE field = :field";

    QSqlQuery query;
    query.prepare(request);
    query.bindValue(":field", field);
    if (query.exec())
    {
        while(query.next())
            byteArray = query.value(0).toByteArray();
    }

    return byteArray;
}

void DBManager::initialization()
{
    if(m_database.open())
    {
        QTime t;
        t.start();

        addTable("Configuration");

        if (addTable("Account_Creation"))
        {
            if (addTable("Account_Configuration"))
            {
                if (addTable("Account"))
                {
                    m_initialized = true;
                    qDebug() << "[DBManager] Initialized ! ("<<t.elapsed()<<"ms)";
                }
            }
        }

    }
    else
        qDebug()<<"The"<<m_path<<" file cannot be opened / created";
}

bool DBManager::isInitialized()
{
    return m_initialized;
}
