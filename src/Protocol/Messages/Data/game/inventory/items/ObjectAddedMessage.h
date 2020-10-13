#ifndef OBJECTADDEDMESSAGE_H
#define OBJECTADDEDMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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