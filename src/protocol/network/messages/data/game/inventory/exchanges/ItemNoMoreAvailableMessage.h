#ifndef ITEMNOMOREAVAILABLEMESSAGE_H
#define ITEMNOMOREAVAILABLEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ItemNoMoreAvailableMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ItemNoMoreAvailableMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ItemNoMoreAvailableMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ItemNoMoreAvailableMessage(FuncTree tree);
  ItemNoMoreAvailableMessage();
};

#endif // ITEMNOMOREAVAILABLEMESSAGE_H