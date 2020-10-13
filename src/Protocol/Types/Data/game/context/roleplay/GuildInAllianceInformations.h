#ifndef GUILDINALLIANCEINFORMATIONS_H
#define GUILDINALLIANCEINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GuildInformations.h"
#include "src/Protocol/Types/Data/game/guild/GuildEmblem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class GuildInAllianceInformations : public GuildInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildInAllianceInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildInAllianceInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildInAllianceInformations(FuncTree tree);
  GuildInAllianceInformations();
  bool operator==(const GuildInAllianceInformations &compared);

  uint nbMembers;
  uint joinDate;

private:
  void _nbMembersFunc(Reader *input);
  void _joinDateFunc(Reader *input);
};

#endif // GUILDINALLIANCEINFORMATIONS_H