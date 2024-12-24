#ifndef OBJECTMODIFIEDMESSAGE_H
#define OBJECTMODIFIEDMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/ObjectItem.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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