#ifndef ITEMSPRESET_H
#define ITEMSPRESET_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/protocol/types/data/game/presets/Preset.h"
#include "src/engines/io/network/utils/FuncTree.h"

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

  QList<> items;
  bool mountEquipped;
  EntityLook look;

private:
  void _itemstreeFunc(Reader *input);
  void _itemsFunc(Reader *input);
  void _mountEquippedFunc(Reader *input);
  void _looktreeFunc(Reader *input);

  FuncTree _itemstree;
  FuncTree _looktree;
};

#endif // ITEMSPRESET_H