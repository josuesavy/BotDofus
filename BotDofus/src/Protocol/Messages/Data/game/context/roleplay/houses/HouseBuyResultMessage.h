#ifndef HOUSEBUYRESULTMESSAGE_H
#define HOUSEBUYRESULTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/protocol/messages/AbstractMessage.h"

class HouseBuyResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseBuyResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseBuyResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseBuyResultMessage(FuncTree tree);
  HouseBuyResultMessage();

  uint houseId;
  uint instanceId;
  bool secondHand;
  bool bought;
  double realPrice;

private:
  void deserializeByteBoxes(Reader *input);
  void _houseIdFunc(Reader *input);
  void _instanceIdFunc(Reader *input);
  void _realPriceFunc(Reader *input);
};

#endif // HOUSEBUYRESULTMESSAGE_H