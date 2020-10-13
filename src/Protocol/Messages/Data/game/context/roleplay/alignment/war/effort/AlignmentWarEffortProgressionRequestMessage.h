#ifndef ALIGNMENTWAREFFORTPROGRESSIONREQUESTMESSAGE_H
#define ALIGNMENTWAREFFORTPROGRESSIONREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AlignmentWarEffortProgressionRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlignmentWarEffortProgressionRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlignmentWarEffortProgressionRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlignmentWarEffortProgressionRequestMessage(FuncTree tree);
  AlignmentWarEffortProgressionRequestMessage();
};

#endif // ALIGNMENTWAREFFORTPROGRESSIONREQUESTMESSAGE_H