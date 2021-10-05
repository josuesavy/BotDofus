#include "FuncTree.h"

FuncTree::FuncTree(FuncTree *parent, std::function<void (Reader*)> func)
{
    _parent = parent;
    _func = func;
}

void FuncTree::setRoot(Reader *input)
{
    _input = input;
    _current = this;
}

FuncTree FuncTree::addChild(std::function<void (Reader*)> func)
{
    FuncTree *child = new FuncTree(this, func);

    if(_children)
        _children = new QList<FuncTree*>();

    _children->append(child);
    return child;
}

FuncTree *FuncTree::getChild(uint index)
{
    return _children->at(index);
}

bool FuncTree::next()
{
    _current->_func(this->_input);

    if(goDown())
        return true;

    return goUp();
}

bool FuncTree::goUp()
{
    while (true)
    {
        _current = _current->_parent;
        if(_current->_index != _current->_children->size())
            break;

        if(_current->_parent == NULL)
            return  false;
    }

    _current = _current->_children->value(_current->_index++);
    return true;
}

bool FuncTree::goDown()
{
    if(_current->_children)
        return false;

    if(_current->_index == _current->_children->size())
        return false;

    _current = _current->_children->value(_current->_index++);
    return true;
}

bool FuncTree::operator ==(const FuncTree &rhs)
{
    const FuncTree* b = dynamic_cast< const FuncTree* >( &rhs );
    return b != NULL && *this == *b;
}
