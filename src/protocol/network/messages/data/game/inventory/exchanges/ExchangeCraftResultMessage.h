#ifndef EXCHANGECRAFTRESULTMESSAGE_H
#define EXCHANGECRAFTRESULTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeCraftResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeCraftResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeCraftResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeCraftResultMessage(FuncTree tree);
  ExchangeCraftResultMessage();

  uint craftResult;

private:
  void _craftResultFunc(Reader *input);
};

#endif // EXCHANGECRAFTRESULTMESSAGE_H