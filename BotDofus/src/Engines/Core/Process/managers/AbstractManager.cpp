#include "AbstractManager.h"

AbstractManager::AbstractManager(ModuleType type, QMap<SocketIO *, BotData> *connectionsData) :
    DataHandler(connectionsData),
    m_type(type)
{
}

AbstractManager::~AbstractManager()
{
}

ModuleType AbstractManager::getType()
{
    return m_type;
}
