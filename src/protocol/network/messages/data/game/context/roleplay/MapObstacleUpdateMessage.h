#ifndef MAPOBSTACLEUPDATEMESSAGE_H
#define MAPOBSTACLEUPDATEMESSAGE_H

#include "src/protocol/network/types/data/game/interactive/MapObstacle.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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