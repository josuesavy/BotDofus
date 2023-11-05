#ifndef ALLIANCEDELETEAPPLICATIONREQUESTMESSAGE_H
#define ALLIANCEDELETEAPPLICATIONREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceDeleteApplicationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceDeleteApplicationRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceDeleteApplicationRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceDeleteApplicationRequestMessage(FuncTree tree);
  AllianceDeleteApplicationRequestMessage();
};

#endif // ALLIANCEDELETEAPPLICATIONREQUESTMESSAGE_H