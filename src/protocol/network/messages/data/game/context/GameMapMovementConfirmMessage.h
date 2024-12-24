#ifndef GAMEMAPMOVEMENTCONFIRMMESSAGE_H
#define GAMEMAPMOVEMENTCONFIRMMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameMapMovementConfirmMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameMapMovementConfirmMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameMapMovementConfirmMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameMapMovementConfirmMessage(FuncTree tree);
  GameMapMovementConfirmMessage();
};

#endif // GAMEMAPMOVEMENTCONFIRMMESSAGE_H