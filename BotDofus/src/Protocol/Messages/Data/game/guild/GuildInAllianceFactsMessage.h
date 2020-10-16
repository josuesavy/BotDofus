#ifndef GUILDINALLIANCEFACTSMESSAGE_H
#define GUILDINALLIANCEFACTSMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "src/Protocol/Types/Data/game/social/GuildFactSheetInformations.h"
#include "src/Protocol/Types/Data/game/character/CharacterMinimalGuildPublicInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/guild/GuildFactsMessage.h"

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