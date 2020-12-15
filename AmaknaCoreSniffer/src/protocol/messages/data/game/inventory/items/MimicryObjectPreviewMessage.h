#ifndef MIMICRYOBJECTPREVIEWMESSAGE_H
#define MIMICRYOBJECTPREVIEWMESSAGE_H

#include "src/protocol/types/data/game/data/items/ObjectItem.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MimicryObjectPreviewMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MimicryObjectPreviewMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MimicryObjectPreviewMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MimicryObjectPreviewMessage(FuncTree tree);
  MimicryObjectPreviewMessage();

  QSharedPointer<ObjectItem> result;

private:
  void _resulttreeFunc(Reader *input);

  FuncTree _resulttree;
};

#endif // MIMICRYOBJECTPREVIEWMESSAGE_H