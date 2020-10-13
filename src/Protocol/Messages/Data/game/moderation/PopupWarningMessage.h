#ifndef POPUPWARNINGMESSAGE_H
#define POPUPWARNINGMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PopupWarningMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PopupWarningMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PopupWarningMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PopupWarningMessage(FuncTree tree);
  PopupWarningMessage();

  uint lockDuration;
  QString author;
  QString content;

private:
  void _lockDurationFunc(Reader *input);
  void _authorFunc(Reader *input);
  void _contentFunc(Reader *input);
};

#endif // POPUPWARNINGMESSAGE_H