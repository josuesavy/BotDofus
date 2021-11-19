#ifndef SHORTCUTBARSWAPERRORMESSAGE_H
#define SHORTCUTBARSWAPERRORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ShortcutBarSwapErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShortcutBarSwapErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShortcutBarSwapErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShortcutBarSwapErrorMessage(FuncTree tree);
  ShortcutBarSwapErrorMessage();

  uint error;

private:
  void _errorFunc(Reader *input);
};

#endif // SHORTCUTBARSWAPERRORMESSAGE_H