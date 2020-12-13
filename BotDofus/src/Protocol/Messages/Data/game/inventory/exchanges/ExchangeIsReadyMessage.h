#ifndef EXCHANGEISREADYMESSAGE_H
#define EXCHANGEISREADYMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeIsReadyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeIsReadyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeIsReadyMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeIsReadyMessage(FuncTree tree);
  ExchangeIsReadyMessage();

  double id;
  bool ready;

private:
  void _idFunc(Reader *input);
  void _readyFunc(Reader *input);
};

#endif // EXCHANGEISREADYMESSAGE_H