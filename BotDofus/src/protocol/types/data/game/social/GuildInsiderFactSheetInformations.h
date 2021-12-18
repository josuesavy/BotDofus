#ifndef GUILDINSIDERFACTSHEETINFORMATIONS_H
#define GUILDINSIDERFACTSHEETINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/social/GuildFactSheetInformations.h"
#include "src/protocol/types/data/game/guild/GuildEmblem.h"
#include "src/protocol/types/data/game/guild/recruitment/GuildRecruitmentInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

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

private:
  void _leaderNameFunc(Reader *input);
  void _nbConnectedMembersFunc(Reader *input);
  void _nbTaxCollectorsFunc(Reader *input);
};

#endif // GUILDINSIDERFACTSHEETINFORMATIONS_H