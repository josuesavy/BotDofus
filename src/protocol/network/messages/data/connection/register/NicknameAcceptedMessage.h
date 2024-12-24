#ifndef NICKNAMEACCEPTEDMESSAGE_H
#define NICKNAMEACCEPTEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class NicknameAcceptedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NicknameAcceptedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NicknameAcceptedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NicknameAcceptedMessage(FuncTree tree);
  NicknameAcceptedMessage();
};

#endif // NICKNAMEACCEPTEDMESSAGE_H