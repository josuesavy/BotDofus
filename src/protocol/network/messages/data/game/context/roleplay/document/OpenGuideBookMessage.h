#ifndef OPENGUIDEBOOKMESSAGE_H
#define OPENGUIDEBOOKMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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