#ifndef MAPINFORMATIONSREQUESTMESSAGE_H
#define MAPINFORMATIONSREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class MapInformationsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapInformationsRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapInformationsRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapInformationsRequestMessage(FuncTree tree);
  MapInformationsRequestMessage();

  double mapId;

private:
  void _mapIdFunc(Reader *input);
};

#endif // MAPINFORMATIONSREQUESTMESSAGE_H