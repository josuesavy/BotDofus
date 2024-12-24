#ifndef CHALLENGEPROPOSALMESSAGE_H
#define CHALLENGEPROPOSALMESSAGE_H

#include "src/protocol/network/types/data/game/context/fight/challenge/ChallengeInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ChallengeProposalMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeProposalMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeProposalMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeProposalMessage(FuncTree tree);
  ChallengeProposalMessage();

  QList<QSharedPointer<ChallengeInformation>> challengeProposals;
  double timer;

private:
  void _challengeProposalstreeFunc(Reader *input);
  void _challengeProposalsFunc(Reader *input);
  void _timerFunc(Reader *input);

  FuncTree _challengeProposalstree;
};

#endif // CHALLENGEPROPOSALMESSAGE_H