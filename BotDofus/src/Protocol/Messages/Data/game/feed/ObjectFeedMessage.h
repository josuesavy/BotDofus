#ifndef OBJECTFEEDMESSAGE_H
#define OBJECTFEEDMESSAGE_H

#include "src/protocol/types/data/game/data/items/ObjectItemQuantity.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ObjectFeedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectFeedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectFeedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectFeedMessage(FuncTree tree);
  ObjectFeedMessage();

  uint objectUID;
  QList<ObjectItemQuantity> meal;

private:
  void _objectUIDFunc(Reader *input);
  void _mealtreeFunc(Reader *input);
  void _mealFunc(Reader *input);

  FuncTree _mealtree;
};

#endif // OBJECTFEEDMESSAGE_H