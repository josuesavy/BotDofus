#ifndef HAAPIVALIDATIONMESSAGE_H
#define HAAPIVALIDATIONMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class HaapiValidationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HaapiValidationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HaapiValidationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HaapiValidationMessage(FuncTree tree);
  HaapiValidationMessage();

  uint action;
  uint code;

private:
  void _actionFunc(Reader *input);
  void _codeFunc(Reader *input);
};

#endif // HAAPIVALIDATIONMESSAGE_H