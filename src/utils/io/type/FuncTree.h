#ifndef FUNCTREE_H
#define FUNCTREE_H

#include <QtGlobal>
#include <QDebug>

#include <functional>

#include "src/utils/io/Reader.h"

class FuncTree
{
public:
    FuncTree(FuncTree *parent = NULL, std::function<void (Reader*)> func = NULL);
    void setRoot(Reader *input);
    FuncTree addChild(std::function<void (Reader*)> func);
    FuncTree *getChild(uint index);
    bool next();
    bool goUp();
    bool goDown();

    bool operator==(const FuncTree &rhs);

private:
    std::function<void (Reader*)> _func;
    FuncTree *_parent;
    QList<FuncTree*> *_children;
    Reader *_input;
    FuncTree *_current;
    uint _index;
};


#endif // FUNCTREE_H
