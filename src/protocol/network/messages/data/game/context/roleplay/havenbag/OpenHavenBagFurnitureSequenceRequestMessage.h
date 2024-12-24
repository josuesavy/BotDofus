#ifndef OPENHAVENBAGFURNITURESEQUENCEREQUESTMESSAGE_H
#define OPENHAVENBAGFURNITURESEQUENCEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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