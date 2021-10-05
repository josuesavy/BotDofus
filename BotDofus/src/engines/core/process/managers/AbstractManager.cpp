#include "AbstractManager.h"

AbstractManager::AbstractManager(ManagerType type, QMap<SocketIO *, BotData> *connectionsData) :
    DataHandler(connectionsData),
    m_type(type)
{
}

AbstractManager::~AbstractManager()
{
}

ManagerType AbstractManager::getType()
{
    return m_type;
}
