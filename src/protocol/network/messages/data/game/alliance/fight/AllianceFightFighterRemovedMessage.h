#ifndef ALLIANCEFIGHTFIGHTERREMOVEDMESSAGE_H
#define ALLIANCEFIGHTFIGHTERREMOVEDMESSAGE_H

#include "src/protocol/types/data/game/social/fight/SocialFightInfo.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceFightFighterRemovedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceFightFighterRemovedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceFightFighterRemovedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceFightFighterRemovedMessage(FuncTree tree);
  AllianceFightFighterRemovedMessage();

  SocialFightInfo allianceFightInfo;
  double fighterId;

private:
  void _allianceFightInfotreeFunc(Reader *input);
  void _fighterIdFunc(Reader *input);

  FuncTree _allianceFightInfotree;
};

#endif // ALLIANCEFIGHTFIGHTERREMOVEDMESSAGE_H