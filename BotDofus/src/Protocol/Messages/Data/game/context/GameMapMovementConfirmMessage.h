#ifndef GAMEMAPMOVEMENTCONFIRMMESSAGE_H
#define GAMEMAPMOVEMENTCONFIRMMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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