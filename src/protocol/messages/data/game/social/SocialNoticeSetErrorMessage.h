#ifndef SOCIALNOTICESETERRORMESSAGE_H
#define SOCIALNOTICESETERRORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class SocialNoticeSetErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SocialNoticeSetErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SocialNoticeSetErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SocialNoticeSetErrorMessage(FuncTree tree);
  SocialNoticeSetErrorMessage();

  uint reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // SOCIALNOTICESETERRORMESSAGE_H