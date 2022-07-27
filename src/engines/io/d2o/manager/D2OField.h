#pragma once

#include <QBuffer>

#include "src/engines/io/network/Reader.h"
#include "D2OClassDefinition.h"
#include <functional>

class I18nFile;

enum MemoryType
{
    _INT, _UINT, _DOUBLE, _BOOL, _STRING, _OBJECT, _ARRAY,
    LIST_INT, LIST_UINT, LIST_DOUBLE, LIST_BOOL, LIST_STRING, LIST_OBJECT,
    LISTLIST_INT, LISTLIST_UINT, LISTLIST_DOUBLE, LISTLIST_BOOL, LISTLIST_STRING, LISTLIST_OBJECT
};

class D2OClassDefinition;


class D2OField
{
public:
    D2OField(const QString &name, Reader *reader);

    void setClasses(QMap<int, D2OClassDefinition*> &classes, I18nFile *I18n);

    const QByteArray &getValue() const;
    MemoryType getType() const;
    const QString getName() const;
    D2OClassDefinition &getD2OClassDefinition(int classId);

    void read(Reader *reader);

    QString toString() const;

private:
    MemoryType getType(const int &typeId);

    std::function<QByteArray (Reader*, const uint&)> getMethod(const int &methodType, Reader *reader);
    static QByteArray readObject(Reader *reader, const uint &dimention, D2OField *D2OField);
    static QByteArray readVector(Reader *reader, const uint &dimention, D2OField *D2OField);
    static QByteArray readInt(Reader *reader, const uint &dimention);
    static QByteArray readBoolean(Reader *reader, const uint &dimention);
    static QByteArray readUTF(Reader *reader, const uint &dimention);
    static QByteArray readDouble(Reader *reader, const uint &dimention);
    static QByteArray readI18nIndex(Reader *reader, const uint &dimention);
    static QByteArray readUInt(Reader *reader, const uint &dimention);

    std::function<QByteArray (Reader*, const uint&)> m_readMethod;
    QList< std::function<QByteArray (Reader*, const uint&)> > m_listMethod;
    QString m_name;
    QList<QString> m_listClasses;
    QByteArray m_value;
    MemoryType m_type;
    QList<int> m_typeId;
    QMap<int, D2OClassDefinition*> m_classes;
    I18nFile *m_I18n;
    const int m_nullId = -1431655766;
};
