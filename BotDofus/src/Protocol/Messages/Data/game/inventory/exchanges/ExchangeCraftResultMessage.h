#ifndef EXCHANGECRAFTRESULTMESSAGE_H
#define EXCHANGECRAFTRESULTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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