#ifndef CHARACTERALIGNMENTWAREFFORTPROGRESSIONREQUESTMESSAGE_H
#define CHARACTERALIGNMENTWAREFFORTPROGRESSIONREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class CharacterAlignmentWarEffortProgressionRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterAlignmentWarEffortProgressionRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterAlignmentWarEffortProgressionRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterAlignmentWarEffortProgressionRequestMessage(FuncTree tree);
  CharacterAlignmentWarEffortProgressionRequestMessage();
};

#endif // CHARACTERALIGNMENTWAREFFORTPROGRESSIONREQUESTMESSAGE_H