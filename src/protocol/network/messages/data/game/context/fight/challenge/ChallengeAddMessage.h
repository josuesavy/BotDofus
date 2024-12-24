#ifndef CHALLENGEADDMESSAGE_H
#define CHALLENGEADDMESSAGE_H

#include "src/protocol/network/types/data/game/context/fight/challenge/ChallengeInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ChallengeAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeAddMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeAddMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeAddMessage(FuncTree tree);
  ChallengeAddMessage();

  QSharedPointer<ChallengeInformation> challengeInformation;

private:
  void _challengeInformationtreeFunc(Reader *input);

  FuncTree _challengeInformationtree;
};

#endif // CHALLENGEADDMESSAGE_H