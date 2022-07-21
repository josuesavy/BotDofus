#ifndef ALLIANCEFACTSHEETINFORMATIONS_H
#define ALLIANCEFACTSHEETINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/AllianceInformations.h"
#include "src/protocol/types/data/game/guild/GuildEmblem.h"
#include "src/engines/io/network/utils/FuncTree.h"

class AllianceFactSheetInformations : public AllianceInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceFactSheetInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceFactSheetInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceFactSheetInformations(FuncTree tree);
  AllianceFactSheetInformations();
  bool operator==(const AllianceFactSheetInformations &compared);

  uint creationDate;
  uint nbGuilds;
  uint nbMembers;
  uint nbSubarea;

private:
  void _creationDateFunc(Reader *input);
  void _nbGuildsFunc(Reader *input);
  void _nbMembersFunc(Reader *input);
  void _nbSubareaFunc(Reader *input);
};

#endif // ALLIANCEFACTSHEETINFORMATIONS_H