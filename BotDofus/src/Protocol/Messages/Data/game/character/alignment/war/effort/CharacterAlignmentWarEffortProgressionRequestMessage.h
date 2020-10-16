#ifndef CHARACTERALIGNMENTWAREFFORTPROGRESSIONREQUESTMESSAGE_H
#define CHARACTERALIGNMENTWAREFFORTPROGRESSIONREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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