#include "AbstractFrame.h"

AbstractFrame::AbstractFrame(QMap<SocketIO *, BotData> *connectionsData) :
    DataHandler(connectionsData)
{

}

AbstractFrame::~AbstractFrame()
{

}
