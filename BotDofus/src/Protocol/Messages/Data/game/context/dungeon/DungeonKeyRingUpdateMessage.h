#ifndef DUNGEONKEYRINGUPDATEMESSAGE_H
#define DUNGEONKEYRINGUPDATEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class DungeonKeyRingUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DungeonKeyRingUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DungeonKeyRingUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DungeonKeyRingUpdateMessage(FuncTree tree);
  DungeonKeyRingUpdateMessage();

  uint dungeonId;
  bool available;

private:
  void _dungeonIdFunc(Reader *input);
  void _availableFunc(Reader *input);
};

#endif // DUNGEONKEYRINGUPDATEMESSAGE_H