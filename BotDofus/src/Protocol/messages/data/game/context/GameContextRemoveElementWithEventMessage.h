#ifndef GAMECONTEXTREMOVEELEMENTWITHEVENTMESSAGE_H
#define GAMECONTEXTREMOVEELEMENTWITHEVENTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/GameContextRemoveElementMessage.h"

class GameContextRemoveElementWithEventMessage : public GameContextRemoveElementMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameContextRemoveElementWithEventMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameContextRemoveElementWithEventMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameContextRemoveElementWithEventMessage(FuncTree tree);
  GameContextRemoveElementWithEventMessage();

  uint elementEventId;

private:
  void _elementEventIdFunc(Reader *input);
};

#endif // GAMECONTEXTREMOVEELEMENTWITHEVENTMESSAGE_H