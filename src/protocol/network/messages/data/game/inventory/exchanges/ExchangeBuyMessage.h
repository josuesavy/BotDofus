#ifndef EXCHANGEBUYMESSAGE_H
#define EXCHANGEBUYMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeBuyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeBuyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeBuyMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeBuyMessage(FuncTree tree);
  ExchangeBuyMessage();

  uint objectToBuyId;
  uint quantity;

private:
  void _objectToBuyIdFunc(Reader *input);
  void _quantityFunc(Reader *input);
};

#endif // EXCHANGEBUYMESSAGE_H