#ifndef MAPFIGHTSTARTPOSITIONSUPDATEMESSAGE_H
#define MAPFIGHTSTARTPOSITIONSUPDATEMESSAGE_H

#include "src/Protocol/Types/Data/game/context/fight/FightStartingPositions.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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