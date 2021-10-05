#ifndef ABSTRACTPARTYEVENTMESSAGE_H
#define ABSTRACTPARTYEVENTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

class AbstractPartyEventMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AbstractPartyEventMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AbstractPartyEventMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AbstractPartyEventMessage(FuncTree tree);
  AbstractPartyEventMessage();
};

#endif // ABSTRACTPARTYEVENTMESSAGE_H