#ifndef CHATABSTRACTSERVERMESSAGE_H
#define CHATABSTRACTSERVERMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ChatAbstractServerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChatAbstractServerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChatAbstractServerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChatAbstractServerMessage(FuncTree tree);
  ChatAbstractServerMessage();

  uint channel;
  QString content;
  uint timestamp;
  QString fingerprint;

private:
  void _channelFunc(Reader *input);
  void _contentFunc(Reader *input);
  void _timestampFunc(Reader *input);
  void _fingerprintFunc(Reader *input);
};

#endif // CHATABSTRACTSERVERMESSAGE_H