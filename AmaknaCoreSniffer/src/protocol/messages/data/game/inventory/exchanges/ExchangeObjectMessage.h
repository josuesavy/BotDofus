#ifndef EXCHANGEOBJECTMESSAGE_H
#define EXCHANGEOBJECTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeObjectMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectMessage(FuncTree tree);
  ExchangeObjectMessage();

  bool remote;

private:
  void _remoteFunc(Reader *input);
};

#endif // EXCHANGEOBJECTMESSAGE_H