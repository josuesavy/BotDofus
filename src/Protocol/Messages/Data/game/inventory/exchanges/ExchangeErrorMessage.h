#ifndef EXCHANGEERRORMESSAGE_H
#define EXCHANGEERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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