#ifndef SHORTCUTBARSWAPREQUESTMESSAGE_H
#define SHORTCUTBARSWAPREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ShortcutBarSwapRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShortcutBarSwapRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShortcutBarSwapRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShortcutBarSwapRequestMessage(FuncTree tree);
  ShortcutBarSwapRequestMessage();

  uint barType;
  uint firstSlot;
  uint secondSlot;

private:
  void _barTypeFunc(Reader *input);
  void _firstSlotFunc(Reader *input);
  void _secondSlotFunc(Reader *input);
};

#endif // SHORTCUTBARSWAPREQUESTMESSAGE_H