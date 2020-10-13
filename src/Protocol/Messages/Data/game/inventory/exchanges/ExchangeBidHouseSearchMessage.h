#ifndef EXCHANGEBIDHOUSESEARCHMESSAGE_H
#define EXCHANGEBIDHOUSESEARCHMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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

  uint genId;
  bool follow;

private:
  void _genIdFunc(Reader *input);
  void _followFunc(Reader *input);
};

#endif // EXCHANGEBIDHOUSESEARCHMESSAGE_H