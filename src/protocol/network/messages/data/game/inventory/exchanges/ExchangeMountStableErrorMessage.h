#ifndef EXCHANGEMOUNTSTABLEERRORMESSAGE_H
#define EXCHANGEMOUNTSTABLEERRORMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeMountStableErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeMountStableErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeMountStableErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeMountStableErrorMessage(FuncTree tree);
  ExchangeMountStableErrorMessage();
};

#endif // EXCHANGEMOUNTSTABLEERRORMESSAGE_H