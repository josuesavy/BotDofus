#ifndef EXCHANGEBIDHOUSEBUYRESULTMESSAGE_H
#define EXCHANGEBIDHOUSEBUYRESULTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeBidHouseBuyResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeBidHouseBuyResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeBidHouseBuyResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeBidHouseBuyResultMessage(FuncTree tree);
  ExchangeBidHouseBuyResultMessage();

  uint uid;
  bool bought;

private:
  void _uidFunc(Reader *input);
  void _boughtFunc(Reader *input);
};

#endif // EXCHANGEBIDHOUSEBUYRESULTMESSAGE_H