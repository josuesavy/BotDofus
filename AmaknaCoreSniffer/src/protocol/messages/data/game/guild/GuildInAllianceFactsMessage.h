#ifndef GUILDINALLIANCEFACTSMESSAGE_H
#define GUILDINALLIANCEFACTSMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "src/protocol/types/data/game/social/GuildFactSheetInformations.h"
#include "src/protocol/types/data/game/character/CharacterMinimalGuildPublicInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/guild/GuildFactsMessage.h"

class GuildInAllianceFactsMessage : public GuildFactsMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildInAllianceFactsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildInAllianceFactsMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildInAllianceFactsMessage(FuncTree tree);
  GuildInAllianceFactsMessage();

  QSharedPointer<BasicNamedAllianceInformations> allianceInfos;

private:
  void _allianceInfostreeFunc(Reader *input);

  FuncTree _allianceInfostree;
};

#endif // GUILDINALLIANCEFACTSMESSAGE_H