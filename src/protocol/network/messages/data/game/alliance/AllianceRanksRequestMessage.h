#ifndef ALLIANCERANKSREQUESTMESSAGE_H
#define ALLIANCERANKSREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceRanksRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceRanksRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceRanksRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceRanksRequestMessage(FuncTree tree);
  AllianceRanksRequestMessage();
};

#endif // ALLIANCERANKSREQUESTMESSAGE_H