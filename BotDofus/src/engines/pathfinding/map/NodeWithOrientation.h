#ifndef NODEWITHORIENTATION_H
#define NODEWITHORIENTATION_H

#include <QSharedPointer>

class NodeWithOrientation
{
public:
    NodeWithOrientation(int id, int x, int y);

    int getId();
    int getOrientation();
    int getX();
    int getY();
    int getCompressedValue() const;
    void setCompressedValue();

    void setOrientation(int orientation);
    void setOrientation(QSharedPointer<NodeWithOrientation> nextNode);

private:
    int m_id;
    int m_orientation;
    int m_x;
    int m_y;
    int m_compressedValue;
};

#endif // NODEWITHORIENTATION_H
