#ifndef HAAPITOKENMESSAGE_H
#define HAAPITOKENMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class HaapiTokenMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HaapiTokenMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HaapiTokenMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HaapiTokenMessage(FuncTree tree);
  HaapiTokenMessage();

  QString token;

private:
  void _tokenFunc(Reader *input);
};

#endif // HAAPITOKENMESSAGE_H