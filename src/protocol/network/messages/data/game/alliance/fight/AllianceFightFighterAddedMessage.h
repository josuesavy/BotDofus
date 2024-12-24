#ifndef ALLIANCEFIGHTFIGHTERADDEDMESSAGE_H
#define ALLIANCEFIGHTFIGHTERADDEDMESSAGE_H

#include "src/protocol/network/types/data/game/character/CharacterMinimalPlusLookInformations.h"
#include "src/protocol/network/types/data/game/social/fight/SocialFightInfo.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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
  QSharedPointer<CharacterMinimalPlusLookInformations> fighter;
  uint team;

private:
  void _allianceFightInfotreeFunc(Reader *input);
  void _fightertreeFunc(Reader *input);
  void _teamFunc(Reader *input);

  FuncTree _allianceFightInfotree;
  FuncTree _fightertree;
};

#endif // ALLIANCEFIGHTFIGHTERADDEDMESSAGE_H