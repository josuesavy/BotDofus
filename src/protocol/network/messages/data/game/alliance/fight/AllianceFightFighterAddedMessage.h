#ifndef ALLIANCEFIGHTFIGHTERADDEDMESSAGE_H
#define ALLIANCEFIGHTFIGHTERADDEDMESSAGE_H

#include "src/protocol/types/data/game/character/CharacterMinimalPlusLookInformations.h"
#include "src/protocol/types/data/game/social/fight/SocialFightInfo.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceFightFighterAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceFightFighterAddedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceFightFighterAddedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceFightFighterAddedMessage(FuncTree tree);
  AllianceFightFighterAddedMessage();

  SocialFightInfo allianceFightInfo;
  CharacterMinimalPlusLookInformations fighter;
  uint team;

private:
  void _allianceFightInfotreeFunc(Reader *input);
  void _fightertreeFunc(Reader *input);
  void _teamFunc(Reader *input);

  FuncTree _allianceFightInfotree;
  FuncTree _fightertree;
};

#endif // ALLIANCEFIGHTFIGHTERADDEDMESSAGE_H