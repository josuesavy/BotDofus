#ifndef PLAYERSTATUSEXTENDED_H
#define PLAYERSTATUSEXTENDED_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/character/status/PlayerStatus.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class PlayerStatusExtended : public PlayerStatus
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PlayerStatusExtended(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PlayerStatusExtended(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PlayerStatusExtended(FuncTree tree);
  PlayerStatusExtended();
  bool operator==(const PlayerStatusExtended &compared);

  QString message;

private:
  void _messageFunc(Reader *input);
};

#endif // PLAYERSTATUSEXTENDED_H