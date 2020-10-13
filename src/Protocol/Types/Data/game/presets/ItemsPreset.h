#ifndef ITEMSPRESET_H
#define ITEMSPRESET_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/presets/ItemForPreset.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Protocol/Types/Data/game/presets/Preset.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ItemsPreset : public Preset
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ItemsPreset(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ItemsPreset(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ItemsPreset(FuncTree tree);
  ItemsPreset();
  bool operator==(const ItemsPreset &compared);

  QList<ItemForPreset> items;
  bool mountEquipped;
  QSharedPointer<EntityLook> look;

private:
  void _itemstreeFunc(Reader *input);
  void _itemsFunc(Reader *input);
  void _mountEquippedFunc(Reader *input);
  void _looktreeFunc(Reader *input);

  FuncTree _itemstree;
  FuncTree _looktree;
};

#endif // ITEMSPRESET_H