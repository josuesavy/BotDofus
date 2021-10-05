#ifndef EXCHANGEOBJECTTRANSFERTLISTWITHQUANTITYTOINVMESSAGE_H
#define EXCHANGEOBJECTTRANSFERTLISTWITHQUANTITYTOINVMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeObjectTransfertListWithQuantityToInvMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectTransfertListWithQuantityToInvMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectTransfertListWithQuantityToInvMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectTransfertListWithQuantityToInvMessage(FuncTree tree);
  ExchangeObjectTransfertListWithQuantityToInvMessage();

  QList<uint> ids;
  QList<uint> qtys;

private:
  void _idstreeFunc(Reader *input);
  void _idsFunc(Reader *input);
  void _qtystreeFunc(Reader *input);
  void _qtysFunc(Reader *input);

  FuncTree _idstree;
  FuncTree _qtystree;
};

#endif // EXCHANGEOBJECTTRANSFERTLISTWITHQUANTITYTOINVMESSAGE_H