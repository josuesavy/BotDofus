#ifndef EXCHANGEBIDHOUSELISTMESSAGE_H
#define EXCHANGEBIDHOUSELISTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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

  uint objectGID;
  bool follow;

private:
  void _objectGIDFunc(Reader *input);
  void _followFunc(Reader *input);
};

#endif // EXCHANGEBIDHOUSELISTMESSAGE_H