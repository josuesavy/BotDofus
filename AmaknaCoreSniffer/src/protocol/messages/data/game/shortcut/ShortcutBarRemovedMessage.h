#ifndef SHORTCUTBARREMOVEDMESSAGE_H
#define SHORTCUTBARREMOVEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ShortcutBarRemovedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShortcutBarRemovedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShortcutBarRemovedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShortcutBarRemovedMessage(FuncTree tree);
  ShortcutBarRemovedMessage();

  uint barType;
  uint slot;

private:
  void _barTypeFunc(Reader *input);
  void _slotFunc(Reader *input);
};

#endif // SHORTCUTBARREMOVEDMESSAGE_H