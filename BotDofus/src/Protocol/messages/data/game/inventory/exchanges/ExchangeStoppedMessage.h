#ifndef EXCHANGESTOPPEDMESSAGE_H
#define EXCHANGESTOPPEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeStoppedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStoppedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStoppedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStoppedMessage(FuncTree tree);
  ExchangeStoppedMessage();

  double id;

private:
  void _idFunc(Reader *input);
};

#endif // EXCHANGESTOPPEDMESSAGE_H