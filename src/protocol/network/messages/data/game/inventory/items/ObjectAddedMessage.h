#ifndef OBJECTADDEDMESSAGE_H
#define OBJECTADDEDMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/ObjectItem.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ObjectAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectAddedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectAddedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectAddedMessage(FuncTree tree);
  ObjectAddedMessage();

  QSharedPointer<ObjectItem> object;
  uint origin;

private:
  void _objecttreeFunc(Reader *input);
  void _originFunc(Reader *input);

  FuncTree _objecttree;
};

#endif // OBJECTADDEDMESSAGE_H