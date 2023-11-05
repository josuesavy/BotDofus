#ifndef ALLIANCERECRUITMENTINFORMATION_H
#define ALLIANCERECRUITMENTINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/social/recruitment/SocialRecruitmentInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

class AllianceRecruitmentInformation : public SocialRecruitmentInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceRecruitmentInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceRecruitmentInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceRecruitmentInformation(FuncTree tree);
  AllianceRecruitmentInformation();
  bool operator==(const AllianceRecruitmentInformation &compared);
};

#endif // ALLIANCERECRUITMENTINFORMATION_H