#ifndef EXCHANGEERRORMESSAGE_H
#define EXCHANGEERRORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeErrorMessage(FuncTree tree);
  ExchangeErrorMessage();

  int errorType;

private:
  void _errorTypeFunc(Reader *input);
};

#endif // EXCHANGEERRORMESSAGE_H