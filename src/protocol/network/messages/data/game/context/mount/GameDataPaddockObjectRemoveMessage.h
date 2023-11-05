#ifndef GAMEDATAPADDOCKOBJECTREMOVEMESSAGE_H
#define GAMEDATAPADDOCKOBJECTREMOVEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameDataPaddockObjectRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameDataPaddockObjectRemoveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameDataPaddockObjectRemoveMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameDataPaddockObjectRemoveMessage(FuncTree tree);
  GameDataPaddockObjectRemoveMessage();

  uint cellId;

private:
  void _cellIdFunc(Reader *input);
};

#endif // GAMEDATAPADDOCKOBJECTREMOVEMESSAGE_H