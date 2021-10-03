#ifndef EMOTEREMOVEMESSAGE_H
#define EMOTEREMOVEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class EmoteRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EmoteRemoveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EmoteRemoveMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EmoteRemoveMessage(FuncTree tree);
  EmoteRemoveMessage();

  uint emoteId;

private:
  void _emoteIdFunc(Reader *input);
};

#endif // EMOTEREMOVEMESSAGE_H