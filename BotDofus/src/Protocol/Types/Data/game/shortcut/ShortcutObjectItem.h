#ifndef SHORTCUTOBJECTITEM_H
#define SHORTCUTOBJECTITEM_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/shortcut/ShortcutObject.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ShortcutObjectItem : public ShortcutObject
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShortcutObjectItem(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShortcutObjectItem(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShortcutObjectItem(FuncTree tree);
  ShortcutObjectItem();
  bool operator==(const ShortcutObjectItem &compared);

  int itemUID;
  int itemGID;

private:
  void _itemUIDFunc(Reader *input);
  void _itemGIDFunc(Reader *input);
};

#endif // SHORTCUTOBJECTITEM_H