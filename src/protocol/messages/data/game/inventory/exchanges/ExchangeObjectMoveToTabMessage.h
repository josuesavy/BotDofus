#ifndef EXCHANGEOBJECTMOVETOTABMESSAGE_H
#define EXCHANGEOBJECTMOVETOTABMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeObjectMoveToTabMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectMoveToTabMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectMoveToTabMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectMoveToTabMessage(FuncTree tree);
  ExchangeObjectMoveToTabMessage();

  uint objectUID;
  int quantity;
  uint tabNumber;

private:
  void _objectUIDFunc(Reader *input);
  void _quantityFunc(Reader *input);
  void _tabNumberFunc(Reader *input);
};

#endif // EXCHANGEOBJECTMOVETOTABMESSAGE_H