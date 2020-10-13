#ifndef NICKNAMEREGISTRATIONMESSAGE_H
#define NICKNAMEREGISTRATIONMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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