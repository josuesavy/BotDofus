#ifndef CHALLENGETARGETUPDATEMESSAGE_H
#define CHALLENGETARGETUPDATEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ChallengeTargetUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeTargetUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeTargetUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeTargetUpdateMessage(FuncTree tree);
  ChallengeTargetUpdateMessage();

  uint challengeId;
  double targetId;

private:
  void _challengeIdFunc(Reader *input);
  void _targetIdFunc(Reader *input);
};

#endif // CHALLENGETARGETUPDATEMESSAGE_H