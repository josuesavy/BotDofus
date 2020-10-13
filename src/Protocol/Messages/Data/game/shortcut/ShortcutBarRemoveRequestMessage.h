#ifndef SHORTCUTBARREMOVEREQUESTMESSAGE_H
#define SHORTCUTBARREMOVEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ShortcutBarRemoveRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShortcutBarRemoveRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShortcutBarRemoveRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShortcutBarRemoveRequestMessage(FuncTree tree);
  ShortcutBarRemoveRequestMessage();

  uint barType;
  uint slot;

private:
  void _barTypeFunc(Reader *input);
  void _slotFunc(Reader *input);
};

#endif // SHORTCUTBARREMOVEREQUESTMESSAGE_H