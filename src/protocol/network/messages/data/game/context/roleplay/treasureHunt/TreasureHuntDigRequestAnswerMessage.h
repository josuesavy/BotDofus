#ifndef TREASUREHUNTDIGREQUESTANSWERMESSAGE_H
#define TREASUREHUNTDIGREQUESTANSWERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TreasureHuntDigRequestAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntDigRequestAnswerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntDigRequestAnswerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntDigRequestAnswerMessage(FuncTree tree);
  TreasureHuntDigRequestAnswerMessage();

  uint questType;
  uint result;

private:
  void _questTypeFunc(Reader *input);
  void _resultFunc(Reader *input);
};

#endif // TREASUREHUNTDIGREQUESTANSWERMESSAGE_H