#ifndef ALLIANCEFACTSHEETINFORMATIONS_H
#define ALLIANCEFACTSHEETINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/AllianceInformations.h"
#include "src/Protocol/Types/Data/game/guild/GuildEmblem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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

private:
  void _creationDateFunc(Reader *input);
};

#endif // ALLIANCEFACTSHEETINFORMATIONS_H