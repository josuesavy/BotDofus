#ifndef EXCHANGEOBJECTTRANSFERTALLTOINVMESSAGE_H
#define EXCHANGEOBJECTTRANSFERTALLTOINVMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeObjectTransfertAllToInvMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectTransfertAllToInvMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectTransfertAllToInvMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectTransfertAllToInvMessage(FuncTree tree);
  ExchangeObjectTransfertAllToInvMessage();
};

#endif // EXCHANGEOBJECTTRANSFERTALLTOINVMESSAGE_H