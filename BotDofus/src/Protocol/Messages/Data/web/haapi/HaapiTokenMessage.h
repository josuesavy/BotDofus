#ifndef HAAPITOKENMESSAGE_H
#define HAAPITOKENMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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