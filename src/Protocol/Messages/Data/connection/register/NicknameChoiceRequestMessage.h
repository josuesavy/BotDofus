#ifndef NICKNAMECHOICEREQUESTMESSAGE_H
#define NICKNAMECHOICEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class NicknameChoiceRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NicknameChoiceRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NicknameChoiceRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NicknameChoiceRequestMessage(FuncTree tree);
  NicknameChoiceRequestMessage();

  QString nickname;

private:
  void _nicknameFunc(Reader *input);
};

#endif // NICKNAMECHOICEREQUESTMESSAGE_H