#ifndef MAPCOORDINATESANDID_H
#define MAPCOORDINATESANDID_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/MapCoordinates.h"
#include "src/utils/io/type/FuncTree.h"

class MapCoordinatesAndId : public MapCoordinates
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapCoordinatesAndId(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapCoordinatesAndId(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapCoordinatesAndId(FuncTree tree);
  MapCoordinatesAndId();
  bool operator==(const MapCoordinatesAndId &compared);

  double mapId;

private:
  void _mapIdFunc(Reader *input);
};

#endif // MAPCOORDINATESANDID_H