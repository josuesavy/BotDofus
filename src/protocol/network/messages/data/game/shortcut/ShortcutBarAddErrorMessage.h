#ifndef SHORTCUTBARADDERRORMESSAGE_H
#define SHORTCUTBARADDERRORMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ShortcutBarAddErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShortcutBarAddErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShortcutBarAddErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShortcutBarAddErrorMessage(FuncTree tree);
  ShortcutBarAddErrorMessage();

  uint error;

private:
  void _errorFunc(Reader *input);
};

#endif // SHORTCUTBARADDERRORMESSAGE_H