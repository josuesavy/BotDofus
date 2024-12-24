#ifndef CHALLENGENUMBERMESSAGE_H
#define CHALLENGENUMBERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ChallengeNumberMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeNumberMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeNumberMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeNumberMessage(FuncTree tree);
  ChallengeNumberMessage();

  uint challengeNumber;

private:
  void _challengeNumberFunc(Reader *input);
};

#endif // CHALLENGENUMBERMESSAGE_H