#ifndef GAMECONTEXTREMOVEMULTIPLEELEMENTSWITHEVENTSMESSAGE_H
#define GAMECONTEXTREMOVEMULTIPLEELEMENTSWITHEVENTSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/GameContextRemoveMultipleElementsMessage.h"

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