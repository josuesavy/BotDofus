#ifndef TREASUREHUNTFLAGREQUESTANSWERMESSAGE_H
#define TREASUREHUNTFLAGREQUESTANSWERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TreasureHuntFlagRequestAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntFlagRequestAnswerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntFlagRequestAnswerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntFlagRequestAnswerMessage(FuncTree tree);
  TreasureHuntFlagRequestAnswerMessage();

  uint questType;
  uint result;
  uint index;

private:
  void _questTypeFunc(Reader *input);
  void _resultFunc(Reader *input);
  void _indexFunc(Reader *input);
};

#endif // TREASUREHUNTFLAGREQUESTANSWERMESSAGE_H