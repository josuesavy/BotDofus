#ifndef NORMALGRAPHICALELEMENTDATA_H
#define NORMALGRAPHICALELEMENTDATA_H

#include <QPoint>

#include "src/engines/io/network/Reader.h"
#include "src/engines/io/ele/GraphicalElementData.h"

class NormalGraphicalElementData : public GraphicalElementData
{
public:
    NormalGraphicalElementData(int elementId, int elementType);

    void fromRaw(Reader *reader, int version);

protected:
    int m_gfxId;
    uint m_height;
    bool m_horizontalSymmetry;
    QPoint m_origin;
    QPoint m_size;
};

#endif // NORMALGRAPHICALELEMENTDATA_H
