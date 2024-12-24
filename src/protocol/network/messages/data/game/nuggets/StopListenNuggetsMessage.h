#ifndef STOPLISTENNUGGETSMESSAGE_H
#define STOPLISTENNUGGETSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class StopListenNuggetsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StopListenNuggetsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StopListenNuggetsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StopListenNuggetsMessage(FuncTree tree);
  StopListenNuggetsMessage();
};

#endif // STOPLISTENNUGGETSMESSAGE_H