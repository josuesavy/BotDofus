#ifndef EXCHANGEOBJECTTRANSFERTALLFROMINVMESSAGE_H
#define EXCHANGEOBJECTTRANSFERTALLFROMINVMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeObjectTransfertAllFromInvMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectTransfertAllFromInvMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectTransfertAllFromInvMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectTransfertAllFromInvMessage(FuncTree tree);
  ExchangeObjectTransfertAllFromInvMessage();
};

#endif // EXCHANGEOBJECTTRANSFERTALLFROMINVMESSAGE_H