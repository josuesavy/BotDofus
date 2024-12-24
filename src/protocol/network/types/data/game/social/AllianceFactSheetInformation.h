#ifndef ALLIANCEFACTSHEETINFORMATION_H
#define ALLIANCEFACTSHEETINFORMATION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/alliance/recruitment/AllianceRecruitmentInformation.h"
#include "src/protocol/network/types/data/game/context/roleplay/AllianceInformation.h"
#include "src/utils/io/type/FuncTree.h"

class AllianceFactSheetInformation : public AllianceInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceFactSheetInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceFactSheetInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceFactSheetInformation(FuncTree tree);
  AllianceFactSheetInformation();
  bool operator==(const AllianceFactSheetInformation &compared);

  uint creationDate;
  uint nbMembers;
  uint nbSubarea;
  uint nbTaxCollectors;
  AllianceRecruitmentInformation recruitment;

private:
  void _creationDateFunc(Reader *input);
  void _nbMembersFunc(Reader *input);
  void _nbSubareaFunc(Reader *input);
  void _nbTaxCollectorsFunc(Reader *input);
  void _recruitmenttreeFunc(Reader *input);

  FuncTree _recruitmenttree;
};

#endif // ALLIANCEFACTSHEETINFORMATION_H