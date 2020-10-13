#ifndef ENTITYLOOKPARSER_H
#define ENTITYLOOKPARSER_H

#include <QString>
#include <QSharedPointer>
#include <QDebug>

#include "TiphonEntityLook.h"
#include "EntityLookAdapter.h"
#include "src/Engines/Storage/DataHandler.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"

class EntityLookParser
{
public:
    EntityLookParser();
    ~EntityLookParser();

    static QString getUrl(QSharedPointer<EntityLook> entity, EntityRendererType t, EntityRendererOrientation o);
    static QString toString(TiphonEntityLook el);
};

#endif // ENTITYLOOKPARSER_H
