#ifndef CHALLENGEMODSELECTMESSAGE_H
#define CHALLENGEMODSELECTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ChallengeModSelectMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeModSelectMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeModSelectMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeModSelectMessage(FuncTree tree);
  ChallengeModSelectMessage();

  uint challengeMod;

private:
  void _challengeModFunc(Reader *input);
};

#endif // CHALLENGEMODSELECTMESSAGE_H