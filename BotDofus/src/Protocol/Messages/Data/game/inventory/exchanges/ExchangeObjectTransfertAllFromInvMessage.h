#ifndef EXCHANGEOBJECTTRANSFERTALLFROMINVMESSAGE_H
#define EXCHANGEOBJECTTRANSFERTALLFROMINVMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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