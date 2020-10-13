#ifndef GAMEMAPMOVEMENTMESSAGE_H
#define GAMEMAPMOVEMENTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameMapMovementMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameMapMovementMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameMapMovementMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameMapMovementMessage(FuncTree tree);
  GameMapMovementMessage();

  QList<uint> keyMovements;
  int forcedDirection;
  double actorId;

private:
  void _keyMovementstreeFunc(Reader *input);
  void _keyMovementsFunc(Reader *input);
  void _forcedDirectionFunc(Reader *input);
  void _actorIdFunc(Reader *input);

  FuncTree _keyMovementstree;
};

#endif // GAMEMAPMOVEMENTMESSAGE_H