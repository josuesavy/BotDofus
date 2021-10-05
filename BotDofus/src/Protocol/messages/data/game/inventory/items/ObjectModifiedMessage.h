#ifndef OBJECTMODIFIEDMESSAGE_H
#define OBJECTMODIFIEDMESSAGE_H

#include "src/protocol/types/data/game/data/items/ObjectItem.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ObjectModifiedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectModifiedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectModifiedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectModifiedMessage(FuncTree tree);
  ObjectModifiedMessage();

  QSharedPointer<ObjectItem> object;

private:
  void _objecttreeFunc(Reader *input);

  FuncTree _objecttree;
};

#endif // OBJECTMODIFIEDMESSAGE_H