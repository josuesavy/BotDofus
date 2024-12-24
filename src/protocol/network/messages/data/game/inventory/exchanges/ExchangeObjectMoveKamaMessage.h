#ifndef EXCHANGEOBJECTMOVEKAMAMESSAGE_H
#define EXCHANGEOBJECTMOVEKAMAMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeObjectMoveKamaMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectMoveKamaMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectMoveKamaMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectMoveKamaMessage(FuncTree tree);
  ExchangeObjectMoveKamaMessage();

  double quantity;

private:
  void _quantityFunc(Reader *input);
};

#endif // EXCHANGEOBJECTMOVEKAMAMESSAGE_H