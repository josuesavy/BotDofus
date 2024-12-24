#ifndef CHALLENGEVALIDATEMESSAGE_H
#define CHALLENGEVALIDATEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ChallengeValidateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeValidateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeValidateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeValidateMessage(FuncTree tree);
  ChallengeValidateMessage();

  uint challengeId;

private:
  void _challengeIdFunc(Reader *input);
};

#endif // CHALLENGEVALIDATEMESSAGE_H