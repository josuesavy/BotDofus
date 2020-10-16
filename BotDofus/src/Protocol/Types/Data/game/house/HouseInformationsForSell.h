#ifndef HOUSEINFORMATIONSFORSELL_H
#define HOUSEINFORMATIONSFORSELL_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class HouseInformationsForSell : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseInformationsForSell(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseInformationsForSell(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseInformationsForSell(FuncTree tree);
  HouseInformationsForSell();
  bool operator==(const HouseInformationsForSell &compared);

  uint instanceId;
  bool secondHand;
  uint modelId;
  uint ownerAccountId;
  QString ownerName;
  QString ownerCharacterName;
  int worldX;
  int worldY;
  uint subAreaId;
  int nbRoom;
  int nbChest;
  QList<int> skillListIds;
  bool isLocked;
  double price;

private:
  void _instanceIdFunc(Reader *input);
  void _secondHandFunc(Reader *input);
  void _modelIdFunc(Reader *input);
  void _ownerAccountIdFunc(Reader *input);
  void _ownerNameFunc(Reader *input);
  void _ownerCharacterNameFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _subAreaIdFunc(Reader *input);
  void _nbRoomFunc(Reader *input);
  void _nbChestFunc(Reader *input);
  void _skillListIdstreeFunc(Reader *input);
  void _skillListIdsFunc(Reader *input);
  void _isLockedFunc(Reader *input);
  void _priceFunc(Reader *input);

  FuncTree _skillListIdstree;
};

#endif // HOUSEINFORMATIONSFORSELL_H