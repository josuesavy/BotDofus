#ifndef ACCOUNTHOUSEINFORMATIONS_H
#define ACCOUNTHOUSEINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/house/HouseInformations.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

class AccountHouseInformations : public HouseInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AccountHouseInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AccountHouseInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AccountHouseInformations(FuncTree tree);
  AccountHouseInformations();
  bool operator==(const AccountHouseInformations &compared);

   houseInfos;
  int worldX;
  int worldY;
  double mapId;
  uint subAreaId;

private:
  void _houseInfostreeFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _mapIdFunc(Reader *input);
  void _subAreaIdFunc(Reader *input);

  FuncTree _houseInfostree;
};

#endif // ACCOUNTHOUSEINFORMATIONS_H