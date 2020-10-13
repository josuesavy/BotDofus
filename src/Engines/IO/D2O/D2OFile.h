#pragma once

#include "D2OFileAccessor.h"
#include "src/Engines/IO/I18n/I18nFile.h"
#include "GameDataTypeDeclarator.h"
#include "AbstractGameData.h"

class D2OFile
{
public:
    D2OFile(const QString &path, I18nFile *I18n, GameDataTypeEnum D2O);
    ~D2OFile();

    QSharedPointer<AbstractGameData> readIndex(int index);

    QList<int> getIndexes();

private:
    D2OFileAccessor *m_accessor;
    I18nFile *m_I18nFile;
    QString m_path;
    GameDataTypeEnum m_D2OFile;
};
