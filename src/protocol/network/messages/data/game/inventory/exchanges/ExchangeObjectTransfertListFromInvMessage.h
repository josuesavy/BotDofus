#ifndef EXCHANGEOBJECTTRANSFERTLISTFROMINVMESSAGE_H
#define EXCHANGEOBJECTTRANSFERTLISTFROMINVMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeObjectTransfertListFromInvMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectTransfertListFromInvMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectTransfertListFromInvMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectTransfertListFromInvMessage(FuncTree tree);
  ExchangeObjectTransfertListFromInvMessage();

  QList<uint> ids;

private:
  void _idstreeFunc(Reader *input);
  void _idsFunc(Reader *input);

  FuncTree _idstree;
};

#endif // EXCHANGEOBJECTTRANSFERTLISTFROMINVMESSAGE_H