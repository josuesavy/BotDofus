#ifndef CHALLENGETARGETSLISTREQUESTMESSAGE_H
#define CHALLENGETARGETSLISTREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ChallengeTargetsListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeTargetsListRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeTargetsListRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeTargetsListRequestMessage(FuncTree tree);
  ChallengeTargetsListRequestMessage();

  uint challengeId;

private:
  void _challengeIdFunc(Reader *input);
};

#endif // CHALLENGETARGETSLISTREQUESTMESSAGE_H