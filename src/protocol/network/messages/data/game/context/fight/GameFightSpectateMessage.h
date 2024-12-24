#ifndef GAMEFIGHTSPECTATEMESSAGE_H
#define GAMEFIGHTSPECTATEMESSAGE_H

#include "src/protocol/network/types/data/game/action/fight/FightDispellableEffectExtendedInformations.h"
#include "src/protocol/network/types/data/game/actions/fight/GameActionMark.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightEffectTriggerCount.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameFightSpectateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightSpectateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightSpectateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightSpectateMessage(FuncTree tree);
  GameFightSpectateMessage();

  QList<QSharedPointer<FightDispellableEffectExtendedInformations>> effects;
  QList<GameActionMark> marks;
  uint gameTurn;
  uint fightStart;
  QList<GameFightEffectTriggerCount> fxTriggerCounts;

private:
  void _effectstreeFunc(Reader *input);
  void _effectsFunc(Reader *input);
  void _markstreeFunc(Reader *input);
  void _marksFunc(Reader *input);
  void _gameTurnFunc(Reader *input);
  void _fightStartFunc(Reader *input);
  void _fxTriggerCountstreeFunc(Reader *input);
  void _fxTriggerCountsFunc(Reader *input);

  FuncTree _effectstree;
  FuncTree _markstree;
  FuncTree _fxTriggerCountstree;
};

#endif // GAMEFIGHTSPECTATEMESSAGE_H