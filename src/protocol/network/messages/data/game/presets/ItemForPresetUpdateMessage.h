#ifndef ITEMFORPRESETUPDATEMESSAGE_H
#define ITEMFORPRESETUPDATEMESSAGE_H

#include "src/protocol/network/types/data/game/presets/ItemForPreset.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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