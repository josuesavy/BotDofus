#ifndef SHORTCUTBARADDREQUESTMESSAGE_H
#define SHORTCUTBARADDREQUESTMESSAGE_H

#include "src/protocol/types/ClassManager.h"
#include "src/protocol/types/data/game/shortcut/Shortcut.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ShortcutBarAddRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShortcutBarAddRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShortcutBarAddRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShortcutBarAddRequestMessage(FuncTree tree);
  ShortcutBarAddRequestMessage();

  uint barType;
  QSharedPointer<Shortcut> shortcut;

private:
  void _barTypeFunc(Reader *input);
  void _shortcuttreeFunc(Reader *input);

  FuncTree _shortcuttree;
};

#endif // SHORTCUTBARADDREQUESTMESSAGE_H