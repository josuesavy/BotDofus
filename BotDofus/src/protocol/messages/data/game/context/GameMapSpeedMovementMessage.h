#ifndef GAMEMAPSPEEDMOVEMENTMESSAGE_H
#define GAMEMAPSPEEDMOVEMENTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameMapSpeedMovementMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameMapSpeedMovementMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameMapSpeedMovementMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameMapSpeedMovementMessage(FuncTree tree);
  GameMapSpeedMovementMessage();

  int speedMultiplier;

private:
  void _speedMultiplierFunc(Reader *input);
};

#endif // GAMEMAPSPEEDMOVEMENTMESSAGE_H