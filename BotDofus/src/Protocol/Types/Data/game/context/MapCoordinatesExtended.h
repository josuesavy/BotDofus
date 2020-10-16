#ifndef MAPCOORDINATESEXTENDED_H
#define MAPCOORDINATESEXTENDED_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/MapCoordinatesAndId.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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