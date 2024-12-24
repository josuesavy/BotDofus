#ifndef HOUSESELLINGUPDATEMESSAGE_H
#define HOUSESELLINGUPDATEMESSAGE_H

#include "src/protocol/network/types/data/common/AccountTagInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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
  AccountTagInformation buyerTag;

private:
  void _houseIdFunc(Reader *input);
  void _instanceIdFunc(Reader *input);
  void _secondHandFunc(Reader *input);
  void _realPriceFunc(Reader *input);
  void _buyerTagtreeFunc(Reader *input);

  FuncTree _buyerTagtree;
};

#endif // HOUSESELLINGUPDATEMESSAGE_H