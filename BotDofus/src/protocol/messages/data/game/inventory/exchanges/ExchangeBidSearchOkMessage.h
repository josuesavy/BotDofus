#ifndef EXCHANGEBIDSEARCHOKMESSAGE_H
#define EXCHANGEBIDSEARCHOKMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeBidSearchOkMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeBidSearchOkMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeBidSearchOkMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeBidSearchOkMessage(FuncTree tree);
  ExchangeBidSearchOkMessage();
};

#endif // EXCHANGEBIDSEARCHOKMESSAGE_H