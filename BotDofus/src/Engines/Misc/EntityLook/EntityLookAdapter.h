#ifndef ENTITYLOOKADAPTER_H
#define ENTITYLOOKADAPTER_H

#include "TiphonEntityLook.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"

class EntityLookAdapter
{
public:
    EntityLookAdapter();
    ~EntityLookAdapter();

    static TiphonEntityLook fromNetwork(QSharedPointer<EntityLook> el);
};

#endif // ENTITYLOOKADAPTER_H
