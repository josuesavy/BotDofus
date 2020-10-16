#ifndef OPENHAVENBAGFURNITURESEQUENCEREQUESTMESSAGE_H
#define OPENHAVENBAGFURNITURESEQUENCEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class OpenHavenBagFurnitureSequenceRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_OpenHavenBagFurnitureSequenceRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_OpenHavenBagFurnitureSequenceRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_OpenHavenBagFurnitureSequenceRequestMessage(FuncTree tree);
  OpenHavenBagFurnitureSequenceRequestMessage();
};

#endif // OPENHAVENBAGFURNITURESEQUENCEREQUESTMESSAGE_H