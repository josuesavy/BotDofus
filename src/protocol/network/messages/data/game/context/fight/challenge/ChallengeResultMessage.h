#ifndef CHALLENGERESULTMESSAGE_H
#define CHALLENGERESULTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ChallengeResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeResultMessage(FuncTree tree);
  ChallengeResultMessage();

  uint challengeId;
  bool success;

private:
  void _challengeIdFunc(Reader *input);
  void _successFunc(Reader *input);
};

#endif // CHALLENGERESULTMESSAGE_H