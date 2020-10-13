#ifndef OBJECTGROUNDLISTADDEDMESSAGE_H
#define OBJECTGROUNDLISTADDEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ObjectGroundListAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectGroundListAddedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectGroundListAddedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectGroundListAddedMessage(FuncTree tree);
  ObjectGroundListAddedMessage();

  QList<uint> cells;
  QList<uint> referenceIds;

private:
  void _cellstreeFunc(Reader *input);
  void _cellsFunc(Reader *input);
  void _referenceIdstreeFunc(Reader *input);
  void _referenceIdsFunc(Reader *input);

  FuncTree _cellstree;
  FuncTree _referenceIdstree;
};

#endif // OBJECTGROUNDLISTADDEDMESSAGE_H