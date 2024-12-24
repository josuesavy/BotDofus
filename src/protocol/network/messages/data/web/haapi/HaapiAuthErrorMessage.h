#ifndef HAAPIAUTHERRORMESSAGE_H
#define HAAPIAUTHERRORMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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