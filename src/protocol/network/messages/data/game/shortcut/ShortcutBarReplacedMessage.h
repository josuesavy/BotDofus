#ifndef SHORTCUTBARREPLACEDMESSAGE_H
#define SHORTCUTBARREPLACEDMESSAGE_H

#include "src/protocol/types/ClassManager.h"
#include "src/protocol/types/data/game/shortcut/Shortcut.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ShortcutBarReplacedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShortcutBarReplacedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShortcutBarReplacedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShortcutBarReplacedMessage(FuncTree tree);
  ShortcutBarReplacedMessage();

  uint barType;
  QSharedPointer<Shortcut> shortcut;

private:
  void _barTypeFunc(Reader *input);
  void _shortcuttreeFunc(Reader *input);

  FuncTree _shortcuttree;
};

#endif // SHORTCUTBARREPLACEDMESSAGE_H