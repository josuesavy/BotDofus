#ifndef MAPOBSTACLEUPDATEMESSAGE_H
#define MAPOBSTACLEUPDATEMESSAGE_H

#include "src/Protocol/Types/Data/game/interactive/MapObstacle.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class MapObstacleUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapObstacleUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapObstacleUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapObstacleUpdateMessage(FuncTree tree);
  MapObstacleUpdateMessage();

  QList<MapObstacle> obstacles;

private:
  void _obstaclestreeFunc(Reader *input);
  void _obstaclesFunc(Reader *input);

  FuncTree _obstaclestree;
};

#endif // MAPOBSTACLEUPDATEMESSAGE_H