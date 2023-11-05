#ifndef STARTLISTENNUGGETSMESSAGE_H
#define STARTLISTENNUGGETSMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class StartListenNuggetsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StartListenNuggetsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StartListenNuggetsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StartListenNuggetsMessage(FuncTree tree);
  StartListenNuggetsMessage();
};

#endif // STARTLISTENNUGGETSMESSAGE_H