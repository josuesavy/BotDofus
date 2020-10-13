#ifndef EXCHANGEISREADYMESSAGE_H
#define EXCHANGEISREADYMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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