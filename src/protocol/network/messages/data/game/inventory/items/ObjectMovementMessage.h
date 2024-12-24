#ifndef OBJECTMOVEMENTMESSAGE_H
#define OBJECTMOVEMENTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ObjectMovementMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectMovementMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectMovementMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectMovementMessage(FuncTree tree);
  ObjectMovementMessage();

  uint objectUID;
  uint position;

private:
  void _objectUIDFunc(Reader *input);
  void _positionFunc(Reader *input);
};

#endif // OBJECTMOVEMENTMESSAGE_H