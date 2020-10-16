#ifndef ABSTRACTPARTYEVENTMESSAGE_H
#define ABSTRACTPARTYEVENTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

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