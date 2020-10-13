#ifndef HOUSEINSTANCEINFORMATIONS_H
#define HOUSEINSTANCEINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/BooleanByteWrapper.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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
  QString ownerName;
  double price;
  bool isSaleLocked;

private:
  void deserializeByteBoxes(Reader *input);
  void _instanceIdFunc(Reader *input);
  void _ownerNameFunc(Reader *input);
  void _priceFunc(Reader *input);
};

#endif // HOUSEINSTANCEINFORMATIONS_H