#ifndef SHORTCUTBARCONTENTMESSAGE_H
#define SHORTCUTBARCONTENTMESSAGE_H

#include "src/protocol/types/data/game/shortcut/Shortcut.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class ShortcutBarContentMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShortcutBarContentMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShortcutBarContentMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShortcutBarContentMessage(FuncTree tree);
  ShortcutBarContentMessage();

  uint barType;
  QList<QSharedPointer<Shortcut>> shortcuts;

private:
  void _barTypeFunc(Reader *input);
  void _shortcutstreeFunc(Reader *input);
  void _shortcutsFunc(Reader *input);

  FuncTree _shortcutstree;
};

#endif // SHORTCUTBARCONTENTMESSAGE_H