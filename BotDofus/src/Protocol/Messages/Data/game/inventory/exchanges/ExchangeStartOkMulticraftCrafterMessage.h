#ifndef EXCHANGESTARTOKMULTICRAFTCRAFTERMESSAGE_H
#define EXCHANGESTARTOKMULTICRAFTCRAFTERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeStartOkMulticraftCrafterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartOkMulticraftCrafterMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartOkMulticraftCrafterMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartOkMulticraftCrafterMessage(FuncTree tree);
  ExchangeStartOkMulticraftCrafterMessage();

  uint skillId;

private:
  void _skillIdFunc(Reader *input);
};

#endif // EXCHANGESTARTOKMULTICRAFTCRAFTERMESSAGE_H