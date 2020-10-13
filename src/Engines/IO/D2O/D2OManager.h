﻿#pragma once

#include <QMutex>
#include <QTime>
#include <QDir>
#include <QDirIterator>

#include "D2OFile.h"
#include "GameDataTypeDeclarator.h"
#include "src/Engines/IO/I18n/I18nFile.h"
#include "GameDataConverter.h"
#include "AbstractGameData.h"
#include "Data/items/ItemData.h"
#include "src/Engines/IO/Singleton.h"

class D2OManagerSingleton;

class D2OManager
{
    friend class ParamsDecoder;
    friend class Singleton<D2OManager>;

public: 
    ~D2OManager();

    void init(const QString &D2OFolderPath, const QString &I18nFilePath);
    bool isInit() const;

    I18nFile *getI18N();

    QSharedPointer<AbstractGameData> getObject(GameDataTypeEnum type, int index);

    QList<GameDataTypeEnum> getLoadedFiles() const;
    QSharedPointer<ItemData> getItem(int objectGID);
    QList<int> getIndexes(GameDataTypeEnum type);
    const QString getD2OFolderPath();
    const QString getI18nFilePath();

private:
    D2OManager();

    void loadFile(GameDataTypeEnum searchedType);

    bool m_isInit;
    QString m_D2OFolderPath;
    QString m_I18nFilePath;
    QMap<GameDataTypeEnum, D2OFile*> m_D2Os;
    I18nFile *m_I18n;
    QMutex m_mutex;
};


class D2OManagerSingleton : public Singleton<D2OManager>
{
};
