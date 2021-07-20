#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QtSql/QtSql>

class DBManager
{
public:
    DBManager(QString path);
    DBManager();

    void setPath(QString path);

    bool addField(QString table, QString field, QByteArray value);
    bool addTable(QString name);

    QByteArray getField(QString table, QString field);

    void initialization();

    bool isInitialized();

private:
    QString m_path;
    QSqlDatabase m_database;

    bool m_initialized;
};

#endif // DBMANAGER_H
