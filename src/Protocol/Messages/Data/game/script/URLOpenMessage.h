#ifndef URLOPENMESSAGE_H
#define URLOPENMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class URLOpenMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_URLOpenMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_URLOpenMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_URLOpenMessage(FuncTree tree);
  URLOpenMessage();

  uint urlId;

private:
  void _urlIdFunc(Reader *input);
};

#endif // URLOPENMESSAGE_H