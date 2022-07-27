#ifndef GAMEFIGHTSTARTINGMESSAGE_H
#define GAMEFIGHTSTARTINGMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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
  QList<int> monsters;

private:
  void _fightTypeFunc(Reader *input);
  void _fightIdFunc(Reader *input);
  void _attackerIdFunc(Reader *input);
  void _defenderIdFunc(Reader *input);
  void _containsBossFunc(Reader *input);
  void _monsterstreeFunc(Reader *input);
  void _monstersFunc(Reader *input);

  FuncTree _monsterstree;
};

#endif // GAMEFIGHTSTARTINGMESSAGE_H