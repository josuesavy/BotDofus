#ifndef EXCHANGEOBJECTTRANSFERTEXISTINGFROMINVMESSAGE_H
#define EXCHANGEOBJECTTRANSFERTEXISTINGFROMINVMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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