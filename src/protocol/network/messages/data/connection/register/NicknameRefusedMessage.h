#ifndef NICKNAMEREFUSEDMESSAGE_H
#define NICKNAMEREFUSEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class NicknameRefusedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NicknameRefusedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NicknameRefusedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NicknameRefusedMessage(FuncTree tree);
  NicknameRefusedMessage();

  uint reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // NICKNAMEREFUSEDMESSAGE_H