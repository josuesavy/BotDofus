#ifndef CHALLENGESELECTIONMESSAGE_H
#define CHALLENGESELECTIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ChallengeSelectionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeSelectionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeSelectionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeSelectionMessage(FuncTree tree);
  ChallengeSelectionMessage();

  uint challengeId;

private:
  void _challengeIdFunc(Reader *input);
};

#endif // CHALLENGESELECTIONMESSAGE_H