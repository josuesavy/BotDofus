#include "AbstractFrame.h"

AbstractFrame::AbstractFrame(ModuleType type, QMap<SocketIO *, BotData> *connectionsData) :
    DataHandler(connectionsData),
    m_type(type)
{
}

AbstractFrame::~AbstractFrame()
{
}

ModuleType AbstractFrame::getType()
{
    return m_type;
}
