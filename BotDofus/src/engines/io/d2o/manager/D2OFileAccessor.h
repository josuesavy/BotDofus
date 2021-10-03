#pragma once

#include "src/engines/io/network/Reader.h"
#include "D2OClassDefinition.h"
#include "src/engines/io/i18n/I18nFile.h"
#include "src/engines/io/d2o/game/AbstractGameData.h"


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
