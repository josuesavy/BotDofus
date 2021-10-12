#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <QMap>

#include "src/engines/io/network/Reader.h"
#include "src/engines/io/ele/GraphicalElementData.h"
#include "src/engines/io/ele/GraphicalElementFactory.h"

class Elements
{
public:
    Elements();
    Elements(Reader *reader);

    QSharedPointer<GraphicalElementData> getElementData(int elementId);

private:
    Reader *m_reader;
    uint m_fileVersion;
    uint m_elementsCount;
    QMap<int, long> m_elementsIndex;
    QMap<int, bool> m_jpegMap;
    QMap<int, QSharedPointer<GraphicalElementData>> m_elementsMap;

    QSharedPointer<GraphicalElementData> readElement(uint edId);
};

#endif // ELEMENTS_H
