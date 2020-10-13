#ifndef CHALLENGEINFOMESSAGE_H
#define CHALLENGEINFOMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ChallengeInfoMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeInfoMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeInfoMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeInfoMessage(FuncTree tree);
  ChallengeInfoMessage();

  uint challengeId;
  double targetId;
  uint xpBonus;
  uint dropBonus;

private:
  void _challengeIdFunc(Reader *input);
  void _targetIdFunc(Reader *input);
  void _xpBonusFunc(Reader *input);
  void _dropBonusFunc(Reader *input);
};

#endif // CHALLENGEINFOMESSAGE_H