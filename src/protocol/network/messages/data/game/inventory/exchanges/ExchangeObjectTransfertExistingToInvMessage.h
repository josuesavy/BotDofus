#ifndef EXCHANGEOBJECTTRANSFERTEXISTINGTOINVMESSAGE_H
#define EXCHANGEOBJECTTRANSFERTEXISTINGTOINVMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeObjectTransfertExistingToInvMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectTransfertExistingToInvMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectTransfertExistingToInvMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectTransfertExistingToInvMessage(FuncTree tree);
  ExchangeObjectTransfertExistingToInvMessage();
};

#endif // EXCHANGEOBJECTTRANSFERTEXISTINGTOINVMESSAGE_H