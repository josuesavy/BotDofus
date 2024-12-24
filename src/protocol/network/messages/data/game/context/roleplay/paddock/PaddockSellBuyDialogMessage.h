#ifndef PADDOCKSELLBUYDIALOGMESSAGE_H
#define PADDOCKSELLBUYDIALOGMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class PaddockSellBuyDialogMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PaddockSellBuyDialogMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PaddockSellBuyDialogMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PaddockSellBuyDialogMessage(FuncTree tree);
  PaddockSellBuyDialogMessage();

  bool bsell;
  uint ownerId;
  double price;

private:
  void _bsellFunc(Reader *input);
  void _ownerIdFunc(Reader *input);
  void _priceFunc(Reader *input);
};

#endif // PADDOCKSELLBUYDIALOGMESSAGE_H