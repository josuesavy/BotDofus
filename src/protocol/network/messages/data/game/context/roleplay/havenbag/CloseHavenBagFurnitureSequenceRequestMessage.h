#ifndef CLOSEHAVENBAGFURNITURESEQUENCEREQUESTMESSAGE_H
#define CLOSEHAVENBAGFURNITURESEQUENCEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class CloseHavenBagFurnitureSequenceRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CloseHavenBagFurnitureSequenceRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CloseHavenBagFurnitureSequenceRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CloseHavenBagFurnitureSequenceRequestMessage(FuncTree tree);
  CloseHavenBagFurnitureSequenceRequestMessage();
};

#endif // CLOSEHAVENBAGFURNITURESEQUENCEREQUESTMESSAGE_H