#ifndef EMOTEPLAYABSTRACTMESSAGE_H
#define EMOTEPLAYABSTRACTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class EmotePlayAbstractMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EmotePlayAbstractMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EmotePlayAbstractMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EmotePlayAbstractMessage(FuncTree tree);
  EmotePlayAbstractMessage();

  uint emoteId;
  double emoteStartTime;

private:
  void _emoteIdFunc(Reader *input);
  void _emoteStartTimeFunc(Reader *input);
};

#endif // EMOTEPLAYABSTRACTMESSAGE_H