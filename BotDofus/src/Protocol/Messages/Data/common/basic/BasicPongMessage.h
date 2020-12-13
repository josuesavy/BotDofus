#ifndef BASICPONGMESSAGE_H
#define BASICPONGMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class BasicPongMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicPongMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicPongMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicPongMessage(FuncTree tree);
  BasicPongMessage();

  bool quiet;

private:
  void _quietFunc(Reader *input);
};

#endif // BASICPONGMESSAGE_H