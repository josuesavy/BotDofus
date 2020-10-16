#ifndef GAMEACTIONFIGHTDISPELLABLEEFFECTMESSAGE_H
#define GAMEACTIONFIGHTDISPELLABLEEFFECTMESSAGE_H

#include "src/Protocol/Types/Data/game/actions/fight/AbstractFightDispellableEffect.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/actions/AbstractGameActionMessage.h"

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