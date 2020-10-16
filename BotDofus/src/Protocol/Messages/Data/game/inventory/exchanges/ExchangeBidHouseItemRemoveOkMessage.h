#ifndef EXCHANGEBIDHOUSEITEMREMOVEOKMESSAGE_H
#define EXCHANGEBIDHOUSEITEMREMOVEOKMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeBidHouseItemRemoveOkMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeBidHouseItemRemoveOkMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeBidHouseItemRemoveOkMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeBidHouseItemRemoveOkMessage(FuncTree tree);
  ExchangeBidHouseItemRemoveOkMessage();

  int sellerId;

private:
  void _sellerIdFunc(Reader *input);
};

#endif // EXCHANGEBIDHOUSEITEMREMOVEOKMESSAGE_H