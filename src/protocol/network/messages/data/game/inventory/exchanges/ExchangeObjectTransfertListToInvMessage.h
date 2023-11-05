#ifndef EXCHANGEOBJECTTRANSFERTLISTTOINVMESSAGE_H
#define EXCHANGEOBJECTTRANSFERTLISTTOINVMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeObjectTransfertListToInvMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectTransfertListToInvMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectTransfertListToInvMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectTransfertListToInvMessage(FuncTree tree);
  ExchangeObjectTransfertListToInvMessage();

  QList<uint> ids;

private:
  void _idstreeFunc(Reader *input);
  void _idsFunc(Reader *input);

  FuncTree _idstree;
};

#endif // EXCHANGEOBJECTTRANSFERTLISTTOINVMESSAGE_H