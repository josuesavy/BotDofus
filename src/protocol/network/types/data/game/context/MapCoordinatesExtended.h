#ifndef MAPCOORDINATESEXTENDED_H
#define MAPCOORDINATESEXTENDED_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/MapCoordinatesAndId.h"
#include "src/utils/io/type/FuncTree.h"

class MapCoordinatesExtended : public MapCoordinatesAndId
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapCoordinatesExtended(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapCoordinatesExtended(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapCoordinatesExtended(FuncTree tree);
  MapCoordinatesExtended();
  bool operator==(const MapCoordinatesExtended &compared);

  uint subAreaId;

private:
  void _subAreaIdFunc(Reader *input);
};

#endif // MAPCOORDINATESEXTENDED_H