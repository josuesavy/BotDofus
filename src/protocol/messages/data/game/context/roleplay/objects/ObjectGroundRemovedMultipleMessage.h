#ifndef OBJECTGROUNDREMOVEDMULTIPLEMESSAGE_H
#define OBJECTGROUNDREMOVEDMULTIPLEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ObjectGroundRemovedMultipleMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectGroundRemovedMultipleMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectGroundRemovedMultipleMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectGroundRemovedMultipleMessage(FuncTree tree);
  ObjectGroundRemovedMultipleMessage();

  QList<uint> cells;

private:
  void _cellstreeFunc(Reader *input);
  void _cellsFunc(Reader *input);

  FuncTree _cellstree;
};

#endif // OBJECTGROUNDREMOVEDMULTIPLEMESSAGE_H