#ifndef PURCHASABLEDIALOGMESSAGE_H
#define PURCHASABLEDIALOGMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Engines/IO/Network/Utils/BooleanByteWrapper.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PurchasableDialogMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PurchasableDialogMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PurchasableDialogMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PurchasableDialogMessage(FuncTree tree);
  PurchasableDialogMessage();

  bool buyOrSell;
  double purchasableId;
  uint purchasableInstanceId;
  bool secondHand;
  double price;

private:
  void deserializeByteBoxes(Reader *input);
  void _purchasableIdFunc(Reader *input);
  void _purchasableInstanceIdFunc(Reader *input);
  void _priceFunc(Reader *input);
};

#endif // PURCHASABLEDIALOGMESSAGE_H