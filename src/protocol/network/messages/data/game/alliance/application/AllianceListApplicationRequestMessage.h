#ifndef ALLIANCELISTAPPLICATIONREQUESTMESSAGE_H
#define ALLIANCELISTAPPLICATIONREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/PaginationRequestAbstractMessage.h"

class AllianceListApplicationRequestMessage : public PaginationRequestAbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceListApplicationRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceListApplicationRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceListApplicationRequestMessage(FuncTree tree);
  AllianceListApplicationRequestMessage();
};

#endif // ALLIANCELISTAPPLICATIONREQUESTMESSAGE_H