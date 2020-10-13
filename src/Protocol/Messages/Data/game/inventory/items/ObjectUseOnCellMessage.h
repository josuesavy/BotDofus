#ifndef OBJECTUSEONCELLMESSAGE_H
#define OBJECTUSEONCELLMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/items/ObjectUseMessage.h"

class ObjectUseOnCellMessage : public ObjectUseMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectUseOnCellMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectUseOnCellMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectUseOnCellMessage(FuncTree tree);
  ObjectUseOnCellMessage();

  uint cells;

private:
  void _cellsFunc(Reader *input);
};

#endif // OBJECTUSEONCELLMESSAGE_H