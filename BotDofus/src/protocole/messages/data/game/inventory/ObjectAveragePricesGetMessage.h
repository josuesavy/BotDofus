#ifndef OBJECTAVERAGEPRICESGETMESSAGE_H
#define OBJECTAVERAGEPRICESGETMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ObjectAveragePricesGetMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectAveragePricesGetMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectAveragePricesGetMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectAveragePricesGetMessage(FuncTree tree);
  ObjectAveragePricesGetMessage();
};

#endif // OBJECTAVERAGEPRICESGETMESSAGE_H