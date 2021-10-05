#ifndef ALLIANCEDGUILDFACTSHEETINFORMATIONS_H
#define ALLIANCEDGUILDFACTSHEETINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GuildInformations.h"
#include "src/protocol/types/data/game/guild/GuildEmblem.h"
#include "src/engines/io/network/utils/FuncTree.h"

class AlliancedGuildFactSheetInformations : public GuildInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlliancedGuildFactSheetInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlliancedGuildFactSheetInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlliancedGuildFactSheetInformations(FuncTree tree);
  AlliancedGuildFactSheetInformations();
  bool operator==(const AlliancedGuildFactSheetInformations &compared);

  QSharedPointer<BasicNamedAllianceInformations> allianceInfos;

private:
  void _allianceInfostreeFunc(Reader *input);

  FuncTree _allianceInfostree;
};

#endif // ALLIANCEDGUILDFACTSHEETINFORMATIONS_H