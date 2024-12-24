#ifndef EMOTEPLAYERRORMESSAGE_H
#define EMOTEPLAYERRORMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class EmotePlayErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EmotePlayErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EmotePlayErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EmotePlayErrorMessage(FuncTree tree);
  EmotePlayErrorMessage();

  uint emoteId;

private:
  void _emoteIdFunc(Reader *input);
};

#endif // EMOTEPLAYERRORMESSAGE_H