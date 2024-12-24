#ifndef NICKNAMEREGISTRATIONMESSAGE_H
#define NICKNAMEREGISTRATIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class NicknameRegistrationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NicknameRegistrationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NicknameRegistrationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NicknameRegistrationMessage(FuncTree tree);
  NicknameRegistrationMessage();
};

#endif // NICKNAMEREGISTRATIONMESSAGE_H