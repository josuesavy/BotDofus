#ifndef PURCHASABLEDIALOGMESSAGE_H
#define PURCHASABLEDIALOGMESSAGE_H

#include "src/utils/io/type/BooleanByteWrapper.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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