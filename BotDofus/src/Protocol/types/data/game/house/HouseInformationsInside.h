#ifndef HOUSEINFORMATIONSINSIDE_H
#define HOUSEINFORMATIONSINSIDE_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/house/HouseInstanceInformations.h"
#include "src/protocol/types/data/game/house/HouseInformations.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

class HouseInformationsInside : public HouseInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseInformationsInside(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseInformationsInside(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseInformationsInside(FuncTree tree);
  HouseInformationsInside();
  bool operator==(const HouseInformationsInside &compared);

  QSharedPointer<HouseInstanceInformations> houseInfos;
  int worldX;
  int worldY;

private:
  void _houseInfostreeFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);

  FuncTree _houseInfostree;
};

#endif // HOUSEINFORMATIONSINSIDE_H