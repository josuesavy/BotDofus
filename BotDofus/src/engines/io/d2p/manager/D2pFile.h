#pragma once

#include "src/engines/io/network/Reader.h"
#include "CompressedMap.h"


class D2PFile
{
private:


public:
    D2PFile(const QString &path);
    ~D2PFile();

    const QString &getPath() const;
    const QMap<uint, CompressedMap*> &getContentMap() const;
    const QMap<QString, CompressedMap*> &getContentImage() const;

private:
    void initializeInstanceD2OFields();
    void getFileContent();

    QString m_path;
    QMap<uint, CompressedMap*> m_contentMap;
    QMap<QString, CompressedMap*> m_contentImage;
};
