#ifndef ALREADYCONNECTEDMESSAGE_H
#define ALREADYCONNECTEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AlreadyConnectedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlreadyConnectedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlreadyConnectedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlreadyConnectedMessage(FuncTree tree);
  AlreadyConnectedMessage();
};

#endif // ALREADYCONNECTEDMESSAGE_H