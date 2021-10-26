#ifndef CRAFT_H
#define CRAFT_H

#include "src/engines/core/CoreEngine.h"

class Craft: public CoreEngine
{
public:
    void putItem(SocketIO *sender, int id, int quantity)
    {
        QSharedPointer<ItemData> item = D2OManagerSingleton::get()->getItem(id);
        getCraftManager().addItemToCraftList(sender, item->getName());
        getCraftManager().updateQuantity(sender, id, quantity);
    }

    void changeQuantityToCraft(SocketIO *sender, int id, int quantity)
    {
        getCraftManager().updateQuantity(sender, id, quantity);
    }

    void ready(SocketIO *sender)
    {
        getCraftManager().processCraft(sender);
    }

    void leaveDialog(SocketIO *sender)
    {

    }
};

#endif // CRAFT_H
