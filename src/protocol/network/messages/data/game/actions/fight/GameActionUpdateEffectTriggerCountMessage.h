#ifndef GAMEACTIONUPDATEEFFECTTRIGGERCOUNTMESSAGE_H
#define GAMEACTIONUPDATEEFFECTTRIGGERCOUNTMESSAGE_H

#include "src/protocol/network/types/data/game/context/fight/GameFightEffectTriggerCount.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameActionUpdateEffectTriggerCountMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionUpdateEffectTriggerCountMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionUpdateEffectTriggerCountMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionUpdateEffectTriggerCountMessage(FuncTree tree);
  GameActionUpdateEffectTriggerCountMessage();

  QList<GameFightEffectTriggerCount> targetIds;

private:
  void _targetIdstreeFunc(Reader *input);
  void _targetIdsFunc(Reader *input);

  FuncTree _targetIdstree;
};

#endif // GAMEACTIONUPDATEEFFECTTRIGGERCOUNTMESSAGE_H