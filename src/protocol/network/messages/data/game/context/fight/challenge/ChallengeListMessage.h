#ifndef CHALLENGELISTMESSAGE_H
#define CHALLENGELISTMESSAGE_H

#include "src/protocol/network/types/data/game/context/fight/challenge/ChallengeInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ChallengeListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeListMessage(FuncTree tree);
  ChallengeListMessage();

  QList<QSharedPointer<ChallengeInformation>> challengesInformation;

private:
  void _challengesInformationtreeFunc(Reader *input);
  void _challengesInformationFunc(Reader *input);

  FuncTree _challengesInformationtree;
};

#endif // CHALLENGELISTMESSAGE_H