#ifndef POPUPWARNINGCLOSEDMESSAGE_H
#define POPUPWARNINGCLOSEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class PopupWarningClosedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PopupWarningClosedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PopupWarningClosedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PopupWarningClosedMessage(FuncTree tree);
  PopupWarningClosedMessage();
};

#endif // POPUPWARNINGCLOSEDMESSAGE_H