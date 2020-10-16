#ifndef EMOTEPLAYMESSAGE_H
#define EMOTEPLAYMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/emote/EmotePlayAbstractMessage.h"

class EmotePlayMessage : public EmotePlayAbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EmotePlayMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EmotePlayMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EmotePlayMessage(FuncTree tree);
  EmotePlayMessage();

  double actorId;
  uint accountId;

private:
  void _actorIdFunc(Reader *input);
  void _accountIdFunc(Reader *input);
};

#endif // EMOTEPLAYMESSAGE_H