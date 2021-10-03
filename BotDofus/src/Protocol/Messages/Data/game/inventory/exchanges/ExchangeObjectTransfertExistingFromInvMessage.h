#ifndef EXCHANGEOBJECTTRANSFERTEXISTINGFROMINVMESSAGE_H
#define EXCHANGEOBJECTTRANSFERTEXISTINGFROMINVMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeObjectTransfertExistingFromInvMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectTransfertExistingFromInvMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectTransfertExistingFromInvMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectTransfertExistingFromInvMessage(FuncTree tree);
  ExchangeObjectTransfertExistingFromInvMessage();
};

#endif // EXCHANGEOBJECTTRANSFERTEXISTINGFROMINVMESSAGE_H