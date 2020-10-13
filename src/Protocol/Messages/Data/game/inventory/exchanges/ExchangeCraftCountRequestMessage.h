#ifndef EXCHANGECRAFTCOUNTREQUESTMESSAGE_H
#define EXCHANGECRAFTCOUNTREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeCraftCountRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeCraftCountRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeCraftCountRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeCraftCountRequestMessage(FuncTree tree);
  ExchangeCraftCountRequestMessage();

  int count;

private:
  void _countFunc(Reader *input);
};

#endif // EXCHANGECRAFTCOUNTREQUESTMESSAGE_H