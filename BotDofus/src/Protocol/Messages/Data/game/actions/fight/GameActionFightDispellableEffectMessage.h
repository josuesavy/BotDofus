#ifndef GAMEACTIONFIGHTDISPELLABLEEFFECTMESSAGE_H
#define GAMEACTIONFIGHTDISPELLABLEEFFECTMESSAGE_H

#include "src/protocol/types/data/game/actions/fight/AbstractFightDispellableEffect.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/actions/AbstractGameActionMessage.h"

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