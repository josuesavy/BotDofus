#ifndef NODE_H
#define NODE_H

#include <QPoint>
#include <QVector>
#include <QSharedPointer>

class Node
{
public:
    Node(bool changeMap, bool walkable, bool los, int column, int line, int id, QPoint location);
    ~Node();

    bool getPair();
    bool getChangeMap();
    bool getWalkable();
    bool getLos();
    bool getInOpenList();
    bool getInClosedList();
    bool getStart();
    bool getEnd();
    QVector<unsigned char> getPosition();
    QPoint getLocation();
    int getId();
    QSharedPointer<Node> getParent() const;
    int getF();
    int getG();
    int getH();
    int getOrientation();

    void setInOpenList(bool inOpenList);
    void setInClosedList(bool inClosedList);
    void setStart(bool start);
    void setEnd(bool end);
    void setParent(QSharedPointer<Node> parent);
    void setF(int f);
    void setG(int g);
    void setH(int h);
    void setH(QSharedPointer<Node>  endNode);

private:
    void getBorder(int column, int line);

    bool m_pair;
    bool m_changeMap;
    bool m_walkable;
    bool m_los;
    bool m_inOpenList;
    bool m_inClosedList;
    bool m_start;
    bool m_end;
    QVector<unsigned char> m_position;
    QPoint m_location;
    int m_id;
    QSharedPointer<Node>  m_parent;
    int m_f;
    int m_g;
    int m_h;
    int m_orientation;
};

#endif // NODE_H
