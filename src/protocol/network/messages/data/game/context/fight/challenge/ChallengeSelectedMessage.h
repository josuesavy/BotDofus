#ifndef CHALLENGESELECTEDMESSAGE_H
#define CHALLENGESELECTEDMESSAGE_H

#include "src/protocol/network/types/data/game/context/fight/challenge/ChallengeInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ChallengeSelectedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeSelectedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeSelectedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeSelectedMessage(FuncTree tree);
  ChallengeSelectedMessage();

  QSharedPointer<ChallengeInformation> challengeInformation;

private:
  void _challengeInformationtreeFunc(Reader *input);

  FuncTree _challengeInformationtree;
};

#endif // CHALLENGESELECTEDMESSAGE_H