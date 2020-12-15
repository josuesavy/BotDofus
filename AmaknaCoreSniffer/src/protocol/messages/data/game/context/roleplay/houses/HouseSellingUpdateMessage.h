#ifndef HOUSESELLINGUPDATEMESSAGE_H
#define HOUSESELLINGUPDATEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class HouseSellingUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseSellingUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseSellingUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseSellingUpdateMessage(FuncTree tree);
  HouseSellingUpdateMessage();

  uint houseId;
  uint instanceId;
  bool secondHand;
  double realPrice;
  QString buyerName;

private:
  void _houseIdFunc(Reader *input);
  void _instanceIdFunc(Reader *input);
  void _secondHandFunc(Reader *input);
  void _realPriceFunc(Reader *input);
  void _buyerNameFunc(Reader *input);
};

#endif // HOUSESELLINGUPDATEMESSAGE_H