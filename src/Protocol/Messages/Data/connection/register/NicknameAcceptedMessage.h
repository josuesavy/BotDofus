#ifndef NICKNAMEACCEPTEDMESSAGE_H
#define NICKNAMEACCEPTEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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