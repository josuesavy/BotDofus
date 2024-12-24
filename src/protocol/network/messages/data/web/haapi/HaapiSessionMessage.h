#ifndef HAAPISESSIONMESSAGE_H
#define HAAPISESSIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class HaapiSessionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HaapiSessionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HaapiSessionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HaapiSessionMessage(FuncTree tree);
  HaapiSessionMessage();

  QString key;
  uint type;

private:
  void _keyFunc(Reader *input);
  void _typeFunc(Reader *input);
};

#endif // HAAPISESSIONMESSAGE_H