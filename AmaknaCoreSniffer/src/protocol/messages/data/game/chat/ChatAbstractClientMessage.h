#ifndef CHATABSTRACTCLIENTMESSAGE_H
#define CHATABSTRACTCLIENTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ChatAbstractClientMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChatAbstractClientMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChatAbstractClientMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChatAbstractClientMessage(FuncTree tree);
  ChatAbstractClientMessage();

  QString content;

private:
  void _contentFunc(Reader *input);
};

#endif // CHATABSTRACTCLIENTMESSAGE_H