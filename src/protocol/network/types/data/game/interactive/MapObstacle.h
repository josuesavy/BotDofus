#ifndef MAPOBSTACLE_H
#define MAPOBSTACLE_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class MapObstacle : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapObstacle(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapObstacle(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapObstacle(FuncTree tree);
  MapObstacle();
  bool operator==(const MapObstacle &compared);

  uint obstacleCellId;
  uint state;

private:
  void _obstacleCellIdFunc(Reader *input);
  void _stateFunc(Reader *input);
};

#endif // MAPOBSTACLE_H