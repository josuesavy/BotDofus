#ifndef ALLIANCEDGUILDFACTSHEETINFORMATIONS_H
#define ALLIANCEDGUILDFACTSHEETINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GuildInformations.h"
#include "src/Protocol/Types/Data/game/guild/GuildEmblem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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