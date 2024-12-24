#ifndef TELEPORTONSAMEMAPMESSAGE_H
#define TELEPORTONSAMEMAPMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class TeleportOnSameMapMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TeleportOnSameMapMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TeleportOnSameMapMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TeleportOnSameMapMessage(FuncTree tree);
  TeleportOnSameMapMessage();

  double targetId;
  uint cellId;

private:
  void _targetIdFunc(Reader *input);
  void _cellIdFunc(Reader *input);
};

#endif // TELEPORTONSAMEMAPMESSAGE_H