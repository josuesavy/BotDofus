#ifndef EXCHANGEOKMULTICRAFTMESSAGE_H
#define EXCHANGEOKMULTICRAFTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeOkMultiCraftMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeOkMultiCraftMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeOkMultiCraftMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeOkMultiCraftMessage(FuncTree tree);
  ExchangeOkMultiCraftMessage();

  double initiatorId;
  double otherId;
  int role;

private:
  void _initiatorIdFunc(Reader *input);
  void _otherIdFunc(Reader *input);
  void _roleFunc(Reader *input);
};

#endif // EXCHANGEOKMULTICRAFTMESSAGE_H