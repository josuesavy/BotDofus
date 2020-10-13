#ifndef TREASUREHUNTREQUESTANSWERMESSAGE_H
#define TREASUREHUNTREQUESTANSWERMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class TreasureHuntRequestAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntRequestAnswerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntRequestAnswerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntRequestAnswerMessage(FuncTree tree);
  TreasureHuntRequestAnswerMessage();

  uint questType;
  uint result;

private:
  void _questTypeFunc(Reader *input);
  void _resultFunc(Reader *input);
};

#endif // TREASUREHUNTREQUESTANSWERMESSAGE_H