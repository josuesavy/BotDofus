#ifndef GAMEACTIONFIGHTLIFEPOINTSLOSTMESSAGE_H
#define GAMEACTIONFIGHTLIFEPOINTSLOSTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightLifePointsLostMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightLifePointsLostMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightLifePointsLostMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightLifePointsLostMessage(FuncTree tree);
  GameActionFightLifePointsLostMessage();

  double targetId;
  uint loss;
  uint permanentDamages;
  int elementId;

private:
  void _targetIdFunc(Reader *input);
  void _lossFunc(Reader *input);
  void _permanentDamagesFunc(Reader *input);
  void _elementIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTLIFEPOINTSLOSTMESSAGE_H