#ifndef ALLIANCEFIGHTINFOMESSAGE_H
#define ALLIANCEFIGHTINFOMESSAGE_H

#include "src/protocol/types/data/game/social/fight/SocialFight.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceFightInfoMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceFightInfoMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceFightInfoMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceFightInfoMessage(FuncTree tree);
  AllianceFightInfoMessage();

  QList<SocialFight> allianceFights;

private:
  void _allianceFightstreeFunc(Reader *input);
  void _allianceFightsFunc(Reader *input);

  FuncTree _allianceFightstree;
};

#endif // ALLIANCEFIGHTINFOMESSAGE_H