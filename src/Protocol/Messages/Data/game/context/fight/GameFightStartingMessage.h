#ifndef GAMEFIGHTSTARTINGMESSAGE_H
#define GAMEFIGHTSTARTINGMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameFightStartingMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightStartingMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightStartingMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightStartingMessage(FuncTree tree);
  GameFightStartingMessage();

  uint fightType;
  uint fightId;
  double attackerId;
  double defenderId;
  bool containsBoss;

private:
  void _fightTypeFunc(Reader *input);
  void _fightIdFunc(Reader *input);
  void _attackerIdFunc(Reader *input);
  void _defenderIdFunc(Reader *input);
  void _containsBossFunc(Reader *input);
};

#endif // GAMEFIGHTSTARTINGMESSAGE_H