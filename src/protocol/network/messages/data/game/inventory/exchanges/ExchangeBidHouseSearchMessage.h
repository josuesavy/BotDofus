#ifndef EXCHANGEBIDHOUSESEARCHMESSAGE_H
#define EXCHANGEBIDHOUSESEARCHMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeBidHouseSearchMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeBidHouseSearchMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeBidHouseSearchMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeBidHouseSearchMessage(FuncTree tree);
  ExchangeBidHouseSearchMessage();

  uint objectGID;
  bool follow;

private:
  void _objectGIDFunc(Reader *input);
  void _followFunc(Reader *input);
};

#endif // EXCHANGEBIDHOUSESEARCHMESSAGE_H