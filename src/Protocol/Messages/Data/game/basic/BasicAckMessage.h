#ifndef BASICACKMESSAGE_H
#define BASICACKMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class BasicAckMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicAckMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicAckMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicAckMessage(FuncTree tree);
  BasicAckMessage();

  uint seq;
  uint lastPacketId;

private:
  void _seqFunc(Reader *input);
  void _lastPacketIdFunc(Reader *input);
};

#endif // BASICACKMESSAGE_H