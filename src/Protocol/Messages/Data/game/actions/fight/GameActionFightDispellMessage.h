#ifndef GAMEACTIONFIGHTDISPELLMESSAGE_H
#define GAMEACTIONFIGHTDISPELLMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightDispellMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightDispellMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightDispellMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightDispellMessage(FuncTree tree);
  GameActionFightDispellMessage();

  double targetId;
  bool verboseCast;

private:
  void _targetIdFunc(Reader *input);
  void _verboseCastFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTDISPELLMESSAGE_H