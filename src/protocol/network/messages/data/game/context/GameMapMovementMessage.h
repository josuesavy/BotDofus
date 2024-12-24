#ifndef GAMEMAPMOVEMENTMESSAGE_H
#define GAMEMAPMOVEMENTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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