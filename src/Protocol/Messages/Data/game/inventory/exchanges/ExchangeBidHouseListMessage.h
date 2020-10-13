#ifndef EXCHANGEBIDHOUSELISTMESSAGE_H
#define EXCHANGEBIDHOUSELISTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeBidHouseListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeBidHouseListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeBidHouseListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeBidHouseListMessage(FuncTree tree);
  ExchangeBidHouseListMessage();

  uint id;
  bool follow;

private:
  void _idFunc(Reader *input);
  void _followFunc(Reader *input);
};

#endif // EXCHANGEBIDHOUSELISTMESSAGE_H