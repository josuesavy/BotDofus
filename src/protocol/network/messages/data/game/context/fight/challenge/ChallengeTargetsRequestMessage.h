#ifndef CHALLENGETARGETSREQUESTMESSAGE_H
#define CHALLENGETARGETSREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ChallengeTargetsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeTargetsRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeTargetsRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeTargetsRequestMessage(FuncTree tree);
  ChallengeTargetsRequestMessage();

  uint challengeId;

private:
  void _challengeIdFunc(Reader *input);
};

#endif // CHALLENGETARGETSREQUESTMESSAGE_H