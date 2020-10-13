#ifndef SHORTCUTBARREMOVEERRORMESSAGE_H
#define SHORTCUTBARREMOVEERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ShortcutBarRemoveErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShortcutBarRemoveErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShortcutBarRemoveErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShortcutBarRemoveErrorMessage(FuncTree tree);
  ShortcutBarRemoveErrorMessage();

  uint error;

private:
  void _errorFunc(Reader *input);
};

#endif // SHORTCUTBARREMOVEERRORMESSAGE_H