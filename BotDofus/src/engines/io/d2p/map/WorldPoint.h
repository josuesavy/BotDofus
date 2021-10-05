#pragma once

#include <QtCore/qmath.h>

class WorldPoint
{
public:
    WorldPoint();
    WorldPoint(const uint &id);

    void setId(const uint &id);

    uint getId() const;
    uint getWorldId() const;
    int getX() const;
    int getY() const;

private:
    uint m_id;
    uint m_worldid;
    int m_x;
    int m_y;
};
