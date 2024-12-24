#ifndef CHALLENGEMODSELECTEDMESSAGE_H
#define CHALLENGEMODSELECTEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ChallengeModSelectedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeModSelectedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeModSelectedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeModSelectedMessage(FuncTree tree);
  ChallengeModSelectedMessage();

  uint challengeMod;

private:
  void _challengeModFunc(Reader *input);
};

#endif // CHALLENGEMODSELECTEDMESSAGE_H