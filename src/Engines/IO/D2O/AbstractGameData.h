#ifndef ABSTRACTGAMEDATA_H
#define ABSTRACTGAMEDATA_H

#include <QSharedPointer>
#include <QList>
#include <QRect>

#include "src/Engines/IO/Network/Reader.h"
#include "src/Engines/IO/D2O/GameDataTypeDeclarator.h"
#include "src/Engines/IO/I18n/I18nFile.h"
#include "src/Engines/IO/D2O/D2OField.h"

class AbstractGameData
{
public:
    AbstractGameData();
    virtual ~AbstractGameData();

    virtual void loadData(const QList<D2OField*> &D2OFields, I18nFile *I18n) = 0;

protected:
    QSharedPointer<AbstractGameData> readObject(const QByteArray &data, D2OField *D2OField);
    QList<QByteArray> readVector(const QByteArray &data);
    uint readUInt(const QByteArray &data);
    int readInt(const QByteArray &data);
    bool readBool(const QByteArray &data);
    QString readUTF(const QByteArray &data);
    double readDouble(const QByteArray &data);
    QRect readRect(const QByteArray &data);

    I18nFile *m_I18n;
};

#endif // ABSTRACTGAMEDATA_H
