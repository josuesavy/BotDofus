#ifndef MAPRUNNINGFIGHTLISTREQUESTMESSAGE_H
#define MAPRUNNINGFIGHTLISTREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MapRunningFightListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapRunningFightListRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapRunningFightListRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapRunningFightListRequestMessage(FuncTree tree);
  MapRunningFightListRequestMessage();
};

#endif // MAPRUNNINGFIGHTLISTREQUESTMESSAGE_H