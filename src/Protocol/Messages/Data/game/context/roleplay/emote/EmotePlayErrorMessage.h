#ifndef EMOTEPLAYERRORMESSAGE_H
#define EMOTEPLAYERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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