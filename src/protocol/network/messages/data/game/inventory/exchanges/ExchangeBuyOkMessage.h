#ifndef EXCHANGEBUYOKMESSAGE_H
#define EXCHANGEBUYOKMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeBuyOkMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeBuyOkMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeBuyOkMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeBuyOkMessage(FuncTree tree);
  ExchangeBuyOkMessage();
};

#endif // EXCHANGEBUYOKMESSAGE_H