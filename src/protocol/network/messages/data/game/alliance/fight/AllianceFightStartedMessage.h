#ifndef ALLIANCEFIGHTSTARTEDMESSAGE_H
#define ALLIANCEFIGHTSTARTEDMESSAGE_H

#include "src/protocol/network/types/data/game/context/fight/FightPhase.h"
#include "src/protocol/network/types/data/game/social/fight/SocialFightInfo.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceFightStartedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceFightStartedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceFightStartedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceFightStartedMessage(FuncTree tree);
  AllianceFightStartedMessage();

  SocialFightInfo allianceFightInfo;
  FightPhase phase;

private:
  void _allianceFightInfotreeFunc(Reader *input);
  void _phasetreeFunc(Reader *input);

  FuncTree _allianceFightInfotree;
  FuncTree _phasetree;
};

#endif // ALLIANCEFIGHTSTARTEDMESSAGE_H