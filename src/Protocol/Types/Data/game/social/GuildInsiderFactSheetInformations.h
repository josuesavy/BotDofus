#ifndef GUILDINSIDERFACTSHEETINFORMATIONS_H
#define GUILDINSIDERFACTSHEETINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/social/GuildFactSheetInformations.h"
#include "src/Protocol/Types/Data/game/guild/GuildEmblem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class GuildInsiderFactSheetInformations : public GuildFactSheetInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildInsiderFactSheetInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildInsiderFactSheetInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildInsiderFactSheetInformations(FuncTree tree);
  GuildInsiderFactSheetInformations();
  bool operator==(const GuildInsiderFactSheetInformations &compared);

  QString leaderName;
  uint nbConnectedMembers;
  uint nbTaxCollectors;
  uint lastActivity;

private:
  void _leaderNameFunc(Reader *input);
  void _nbConnectedMembersFunc(Reader *input);
  void _nbTaxCollectorsFunc(Reader *input);
  void _lastActivityFunc(Reader *input);
};

#endif // GUILDINSIDERFACTSHEETINFORMATIONS_H