#ifndef OPENGUIDEBOOKMESSAGE_H
#define OPENGUIDEBOOKMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class OpenGuideBookMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_OpenGuideBookMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_OpenGuideBookMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_OpenGuideBookMessage(FuncTree tree);
  OpenGuideBookMessage();

  uint articleId;

private:
  void _articleIdFunc(Reader *input);
};

#endif // OPENGUIDEBOOKMESSAGE_H