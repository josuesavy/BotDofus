#pragma once

#include <iostream>
#include <sstream>

#include <QDebug>

#include "src/Engines/IO/Network/Reader.h"
#include "src/Public.h"


class CompressedMap
{
public:
    CompressedMap(Reader *reader, const QString &path);

    QString getPath() const;
    QString getIndexName() const;
    bool isInvalidMap() const;
    bool isImage() const;
    bool isMap() const;
    uint getOffset() const;
    uint getByteCount() const;
    uint getMapId() const;
    QString getImageId() const;
    QByteArray getData() const;

private:
    QString m_path;
    QString m_indexName;
    uint m_offset;
    uint m_byteCount;
    bool m_isInvalidMap;
    bool m_isImage;
    bool m_isMap;
    QByteArray data;

};

