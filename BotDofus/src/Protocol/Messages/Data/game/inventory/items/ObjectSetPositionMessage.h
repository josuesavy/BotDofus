#ifndef OBJECTSETPOSITIONMESSAGE_H
#define OBJECTSETPOSITIONMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ObjectSetPositionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectSetPositionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectSetPositionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectSetPositionMessage(FuncTree tree);
  ObjectSetPositionMessage();

  uint objectUID;
  uint position;
  uint quantity;

private:
  void _objectUIDFunc(Reader *input);
  void _positionFunc(Reader *input);
  void _quantityFunc(Reader *input);
};

#endif // OBJECTSETPOSITIONMESSAGE_H