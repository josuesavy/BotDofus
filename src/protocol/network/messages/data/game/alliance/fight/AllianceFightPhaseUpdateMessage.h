#ifndef ALLIANCEFIGHTPHASEUPDATEMESSAGE_H
#define ALLIANCEFIGHTPHASEUPDATEMESSAGE_H

#include "src/protocol/network/types/data/game/context/fight/FightPhase.h"
#include "src/protocol/network/types/data/game/social/fight/SocialFightInfo.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceFightPhaseUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceFightPhaseUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceFightPhaseUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceFightPhaseUpdateMessage(FuncTree tree);
  AllianceFightPhaseUpdateMessage();

  SocialFightInfo allianceFightInfo;
  FightPhase newPhase;

private:
  void _allianceFightInfotreeFunc(Reader *input);
  void _newPhasetreeFunc(Reader *input);

  FuncTree _allianceFightInfotree;
  FuncTree _newPhasetree;
};

#endif // ALLIANCEFIGHTPHASEUPDATEMESSAGE_H