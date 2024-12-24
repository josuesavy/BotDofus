#ifndef GAMEACTIONFIGHTINVISIBLEDETECTEDMESSAGE_H
#define GAMEACTIONFIGHTINVISIBLEDETECTEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightInvisibleDetectedMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightInvisibleDetectedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightInvisibleDetectedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightInvisibleDetectedMessage(FuncTree tree);
  GameActionFightInvisibleDetectedMessage();

  double targetId;
  int cellId;

private:
  void _targetIdFunc(Reader *input);
  void _cellIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTINVISIBLEDETECTEDMESSAGE_H