#ifndef ITEMNOMOREAVAILABLEMESSAGE_H
#define ITEMNOMOREAVAILABLEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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