#ifndef MIMICRYOBJECTPREVIEWMESSAGE_H
#define MIMICRYOBJECTPREVIEWMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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