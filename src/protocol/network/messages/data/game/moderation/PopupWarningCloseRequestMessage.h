#ifndef POPUPWARNINGCLOSEREQUESTMESSAGE_H
#define POPUPWARNINGCLOSEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class PopupWarningCloseRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PopupWarningCloseRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PopupWarningCloseRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PopupWarningCloseRequestMessage(FuncTree tree);
  PopupWarningCloseRequestMessage();
};

#endif // POPUPWARNINGCLOSEREQUESTMESSAGE_H