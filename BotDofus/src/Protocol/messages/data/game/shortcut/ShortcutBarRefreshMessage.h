#ifndef SHORTCUTBARREFRESHMESSAGE_H
#define SHORTCUTBARREFRESHMESSAGE_H

#include "src/protocol/types/data/game/shortcut/Shortcut.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class ShortcutBarRefreshMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShortcutBarRefreshMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShortcutBarRefreshMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShortcutBarRefreshMessage(FuncTree tree);
  ShortcutBarRefreshMessage();

  uint barType;
  QSharedPointer<Shortcut> shortcut;

private:
  void _barTypeFunc(Reader *input);
  void _shortcuttreeFunc(Reader *input);

  FuncTree _shortcuttree;
};

#endif // SHORTCUTBARREFRESHMESSAGE_H