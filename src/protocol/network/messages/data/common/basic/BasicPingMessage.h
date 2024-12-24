#ifndef BASICPINGMESSAGE_H
#define BASICPINGMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class BasicPingMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicPingMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicPingMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicPingMessage(FuncTree tree);
  BasicPingMessage();

  bool quiet;

private:
  void _quietFunc(Reader *input);
};

#endif // BASICPINGMESSAGE_H