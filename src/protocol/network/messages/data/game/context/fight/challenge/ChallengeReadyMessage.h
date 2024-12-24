#ifndef CHALLENGEREADYMESSAGE_H
#define CHALLENGEREADYMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ChallengeReadyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeReadyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeReadyMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeReadyMessage(FuncTree tree);
  ChallengeReadyMessage();

  uint challengeMod;

private:
  void _challengeModFunc(Reader *input);
};

#endif // CHALLENGEREADYMESSAGE_H