#ifndef ALLIANCEFIGHTINFOMESSAGE_H
#define ALLIANCEFIGHTINFOMESSAGE_H

#include "src/protocol/network/types/data/game/social/fight/SocialFight.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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

  QList<QSharedPointer<SocialFight>> allianceFights;

private:
  void _allianceFightstreeFunc(Reader *input);
  void _allianceFightsFunc(Reader *input);

  FuncTree _allianceFightstree;
};

#endif // ALLIANCEFIGHTINFOMESSAGE_H