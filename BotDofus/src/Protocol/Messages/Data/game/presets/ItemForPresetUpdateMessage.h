#ifndef ITEMFORPRESETUPDATEMESSAGE_H
#define ITEMFORPRESETUPDATEMESSAGE_H

#include "src/protocol/types/data/game/presets/ItemForPreset.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ItemForPresetUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ItemForPresetUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ItemForPresetUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ItemForPresetUpdateMessage(FuncTree tree);
  ItemForPresetUpdateMessage();

  int presetId;
  ItemForPreset presetItem;

private:
  void _presetIdFunc(Reader *input);
  void _presetItemtreeFunc(Reader *input);

  FuncTree _presetItemtree;
};

#endif // ITEMFORPRESETUPDATEMESSAGE_H