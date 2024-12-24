#ifndef GAMEACTIONFIGHTTACKLEDMESSAGE_H
#define GAMEACTIONFIGHTTACKLEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightTackledMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightTackledMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightTackledMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightTackledMessage(FuncTree tree);
  GameActionFightTackledMessage();

  QList<double> tacklersIds;

private:
  void _tacklersIdstreeFunc(Reader *input);
  void _tacklersIdsFunc(Reader *input);

  FuncTree _tacklersIdstree;
};

#endif // GAMEACTIONFIGHTTACKLEDMESSAGE_H