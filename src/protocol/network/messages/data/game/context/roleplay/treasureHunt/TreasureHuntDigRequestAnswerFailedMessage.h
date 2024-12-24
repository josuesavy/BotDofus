#ifndef TREASUREHUNTDIGREQUESTANSWERFAILEDMESSAGE_H
#define TREASUREHUNTDIGREQUESTANSWERFAILEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/treasureHunt/TreasureHuntDigRequestAnswerMessage.h"

class TreasureHuntDigRequestAnswerFailedMessage : public TreasureHuntDigRequestAnswerMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntDigRequestAnswerFailedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntDigRequestAnswerFailedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntDigRequestAnswerFailedMessage(FuncTree tree);
  TreasureHuntDigRequestAnswerFailedMessage();

  uint wrongFlagCount;

private:
  void _wrongFlagCountFunc(Reader *input);
};

#endif // TREASUREHUNTDIGREQUESTANSWERFAILEDMESSAGE_H