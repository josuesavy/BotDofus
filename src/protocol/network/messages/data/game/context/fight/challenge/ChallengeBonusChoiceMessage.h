#ifndef CHALLENGEBONUSCHOICEMESSAGE_H
#define CHALLENGEBONUSCHOICEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ChallengeBonusChoiceMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeBonusChoiceMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeBonusChoiceMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeBonusChoiceMessage(FuncTree tree);
  ChallengeBonusChoiceMessage();

  uint challengeBonus;

private:
  void _challengeBonusFunc(Reader *input);
};

#endif // CHALLENGEBONUSCHOICEMESSAGE_H