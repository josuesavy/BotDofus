#ifndef EXCHANGECRAFTCOUNTMODIFIEDMESSAGE_H
#define EXCHANGECRAFTCOUNTMODIFIEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeCraftCountModifiedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeCraftCountModifiedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeCraftCountModifiedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeCraftCountModifiedMessage(FuncTree tree);
  ExchangeCraftCountModifiedMessage();

  int count;

private:
  void _countFunc(Reader *input);
};

#endif // EXCHANGECRAFTCOUNTMODIFIEDMESSAGE_H