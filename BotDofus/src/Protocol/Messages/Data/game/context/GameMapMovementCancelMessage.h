#ifndef GAMEMAPMOVEMENTCANCELMESSAGE_H
#define GAMEMAPMOVEMENTCANCELMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameMapMovementCancelMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameMapMovementCancelMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameMapMovementCancelMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameMapMovementCancelMessage(FuncTree tree);
  GameMapMovementCancelMessage();

  uint cellId;

private:
  void _cellIdFunc(Reader *input);
};

#endif // GAMEMAPMOVEMENTCANCELMESSAGE_H