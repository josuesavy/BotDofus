#pragma once

#include "src/engines/io/network/Reader.h"

class D2OField;
class I18nFile;
class AbstractGameData;

class D2OClassDefinition
{
public:
    D2OClassDefinition(const QString &className);
    ~D2OClassDefinition();

    void addD2OField(const QString &D2OFieldName, Reader *reader);

    void setD2OField(QMap<int, D2OClassDefinition *> &classes, I18nFile *I18n);

    QSharedPointer<AbstractGameData> read(Reader *reader, I18nFile *I18n);


private:    
    QString m_className;
    QList<D2OField*> m_D2OFields;
};
