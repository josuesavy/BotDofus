#ifndef MAPFIGHTSTARTPOSITIONSUPDATEMESSAGE_H
#define MAPFIGHTSTARTPOSITIONSUPDATEMESSAGE_H

#include "src/protocol/network/types/data/game/context/fight/FightStartingPositions.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class MapFightStartPositionsUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapFightStartPositionsUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapFightStartPositionsUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapFightStartPositionsUpdateMessage(FuncTree tree);
  MapFightStartPositionsUpdateMessage();

  double mapId;
  FightStartingPositions fightStartPositions;

private:
  void _mapIdFunc(Reader *input);
  void _fightStartPositionstreeFunc(Reader *input);

  FuncTree _fightStartPositionstree;
};

#endif // MAPFIGHTSTARTPOSITIONSUPDATEMESSAGE_H