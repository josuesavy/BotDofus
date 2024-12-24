#ifndef GAMEACTIONFIGHTDISPELLABLEEFFECTMESSAGE_H
#define GAMEACTIONFIGHTDISPELLABLEEFFECTMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/actions/fight/AbstractFightDispellableEffect.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightDispellableEffectMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightDispellableEffectMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightDispellableEffectMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightDispellableEffectMessage(FuncTree tree);
  GameActionFightDispellableEffectMessage();

  QSharedPointer<AbstractFightDispellableEffect> effect;

private:
  void _effecttreeFunc(Reader *input);

  FuncTree _effecttree;
};

#endif // GAMEACTIONFIGHTDISPELLABLEEFFECTMESSAGE_H