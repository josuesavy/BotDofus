#ifndef HOUSEONMAPINFORMATIONS_H
#define HOUSEONMAPINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/house/HouseInstanceInformations.h"
#include "src/Protocol/Types/Data/game/house/HouseInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class HouseOnMapInformations : public HouseInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseOnMapInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseOnMapInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseOnMapInformations(FuncTree tree);
  HouseOnMapInformations();
  bool operator==(const HouseOnMapInformations &compared);

  QList<uint> doorsOnMap;
  QList<QSharedPointer<HouseInstanceInformations>> houseInstances;

private:
  void _doorsOnMaptreeFunc(Reader *input);
  void _doorsOnMapFunc(Reader *input);
  void _houseInstancestreeFunc(Reader *input);
  void _houseInstancesFunc(Reader *input);

  FuncTree _doorsOnMaptree;
  FuncTree _houseInstancestree;
};

#endif // HOUSEONMAPINFORMATIONS_H