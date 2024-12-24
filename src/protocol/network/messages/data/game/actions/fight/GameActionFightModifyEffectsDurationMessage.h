#ifndef GAMEACTIONFIGHTMODIFYEFFECTSDURATIONMESSAGE_H
#define GAMEACTIONFIGHTMODIFYEFFECTSDURATIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightModifyEffectsDurationMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightModifyEffectsDurationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightModifyEffectsDurationMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightModifyEffectsDurationMessage(FuncTree tree);
  GameActionFightModifyEffectsDurationMessage();

  double targetId;
  int delta;

private:
  void _targetIdFunc(Reader *input);
  void _deltaFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTMODIFYEFFECTSDURATIONMESSAGE_H