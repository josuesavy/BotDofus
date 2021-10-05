#ifndef ALLIANCECREATIONSTARTEDMESSAGE_H
#define ALLIANCECREATIONSTARTEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceCreationStartedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceCreationStartedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceCreationStartedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceCreationStartedMessage(FuncTree tree);
  AllianceCreationStartedMessage();
};

#endif // ALLIANCECREATIONSTARTEDMESSAGE_H