#ifndef GAMECONTEXTREMOVEMULTIPLEELEMENTSWITHEVENTSMESSAGE_H
#define GAMECONTEXTREMOVEMULTIPLEELEMENTSWITHEVENTSMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/GameContextRemoveMultipleElementsMessage.h"

class GameContextRemoveMultipleElementsWithEventsMessage : public GameContextRemoveMultipleElementsMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameContextRemoveMultipleElementsWithEventsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameContextRemoveMultipleElementsWithEventsMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameContextRemoveMultipleElementsWithEventsMessage(FuncTree tree);
  GameContextRemoveMultipleElementsWithEventsMessage();

  QList<uint> elementEventIds;

private:
  void _elementEventIdstreeFunc(Reader *input);
  void _elementEventIdsFunc(Reader *input);

  FuncTree _elementEventIdstree;
};

#endif // GAMECONTEXTREMOVEMULTIPLEELEMENTSWITHEVENTSMESSAGE_H