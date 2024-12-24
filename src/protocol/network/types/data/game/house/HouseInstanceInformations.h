#ifndef HOUSEINSTANCEINFORMATIONS_H
#define HOUSEINSTANCEINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/common/AccountTagInformation.h"
#include "src/utils/io/type/BooleanByteWrapper.h"
#include "src/utils/io/type/FuncTree.h"

class HouseInstanceInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseInstanceInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseInstanceInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseInstanceInformations(FuncTree tree);
  HouseInstanceInformations();
  bool operator==(const HouseInstanceInformations &compared);

  uint instanceId;
  bool secondHand;
  bool isLocked;
  AccountTagInformation ownerTag;
  bool hasOwner;
  double price;
  bool isSaleLocked;
  bool isAdminLocked;

private:
  void deserializeByteBoxes(Reader *input);
  void _instanceIdFunc(Reader *input);
  void _ownerTagtreeFunc(Reader *input);
  void _priceFunc(Reader *input);

  FuncTree _ownerTagtree;
};

#endif // HOUSEINSTANCEINFORMATIONS_H