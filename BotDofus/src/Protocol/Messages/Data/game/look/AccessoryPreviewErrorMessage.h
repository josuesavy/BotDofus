#ifndef ACCESSORYPREVIEWERRORMESSAGE_H
#define ACCESSORYPREVIEWERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AccessoryPreviewErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AccessoryPreviewErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AccessoryPreviewErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AccessoryPreviewErrorMessage(FuncTree tree);
  AccessoryPreviewErrorMessage();

  uint error;

private:
  void _errorFunc(Reader *input);
};

#endif // ACCESSORYPREVIEWERRORMESSAGE_H