#ifndef GAMEMAPMOVEMENTREQUESTMESSAGE_H
#define GAMEMAPMOVEMENTREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameMapMovementRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameMapMovementRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameMapMovementRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameMapMovementRequestMessage(FuncTree tree);
  GameMapMovementRequestMessage();

  QList<uint> keyMovements;
  double mapId;

private:
  void _keyMovementstreeFunc(Reader *input);
  void _keyMovementsFunc(Reader *input);
  void _mapIdFunc(Reader *input);

  FuncTree _keyMovementstree;
};

#endif // GAMEMAPMOVEMENTREQUESTMESSAGE_H