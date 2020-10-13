#ifndef HAAPIAUTHERRORMESSAGE_H
#define HAAPIAUTHERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class HaapiAuthErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HaapiAuthErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HaapiAuthErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HaapiAuthErrorMessage(FuncTree tree);
  HaapiAuthErrorMessage();

  uint type;

private:
  void _typeFunc(Reader *input);
};

#endif // HAAPIAUTHERRORMESSAGE_H