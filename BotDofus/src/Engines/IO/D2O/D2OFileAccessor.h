#pragma once

#include "src/Engines/IO/Network/Reader.h"
#include "D2OClassDefinition.h"
#include "src/Engines/IO/I18n/I18nFile.h"
#include "src/Engines/IO/D2O/AbstractGameData.h"


class D2OFileAccessor
{
public:
    D2OFileAccessor(const QString &path, I18nFile *I18n);
    ~D2OFileAccessor();

    QList<int> getIndexes();

    QSharedPointer<AbstractGameData> read(int index);

private:
    D2OClassDefinition *readD2OClassDefinition();

    QString m_path;
    Reader *m_reader;
    QMap<int, int> m_indexes;
    QMap<int, D2OClassDefinition*> m_classes;
    I18nFile *m_I18n;
};
