#ifndef CHALLENGEBONUSCHOICESELECTEDMESSAGE_H
#define CHALLENGEBONUSCHOICESELECTEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ChallengeBonusChoiceSelectedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeBonusChoiceSelectedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeBonusChoiceSelectedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeBonusChoiceSelectedMessage(FuncTree tree);
  ChallengeBonusChoiceSelectedMessage();

  uint challengeBonus;

private:
  void _challengeBonusFunc(Reader *input);
};

#endif // CHALLENGEBONUSCHOICESELECTEDMESSAGE_H