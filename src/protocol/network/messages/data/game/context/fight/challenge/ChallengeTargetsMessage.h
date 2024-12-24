#ifndef CHALLENGETARGETSMESSAGE_H
#define CHALLENGETARGETSMESSAGE_H

#include "src/protocol/network/types/data/game/context/fight/challenge/ChallengeInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ChallengeTargetsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeTargetsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeTargetsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeTargetsMessage(FuncTree tree);
  ChallengeTargetsMessage();

  QSharedPointer<ChallengeInformation> challengeInformation;

private:
  void _challengeInformationtreeFunc(Reader *input);

  FuncTree _challengeInformationtree;
};

#endif // CHALLENGETARGETSMESSAGE_H