#ifndef ABSTRACTCLASS_H
#define ABSTRACTCLASS_H

#include "src/utils/Public.h"
#include "ClassEnum.h"
#include "src/utils/io/Reader.h"
#include "src/utils/io/Writer.h"

class AbstractClass
{
public:
    virtual void serialize(Writer *writer) = 0;
    virtual void deserialize(Reader *reader) = 0;
    QList<ClassEnum> getTypes() const
    {return m_types;}
    virtual ~AbstractClass()
    {}

protected:
    QList<ClassEnum> m_types;
};

#endif // ABSTRACTCLASS_H
