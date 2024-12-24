#include "AllianceRecruitmentInformation.h"

void AllianceRecruitmentInformation::serialize(Writer *output)
{
  this->serializeAs_AllianceRecruitmentInformation(output);
}

void AllianceRecruitmentInformation::serializeAs_AllianceRecruitmentInformation(Writer *output)
{
  SocialRecruitmentInformation::serializeAs_SocialRecruitmentInformation(output);
}

void AllianceRecruitmentInformation::deserialize(Reader *input)
{
  this->deserializeAs_AllianceRecruitmentInformation(input);
}

void AllianceRecruitmentInformation::deserializeAs_AllianceRecruitmentInformation(Reader *input)
{
  SocialRecruitmentInformation::deserialize(input);
}

void AllianceRecruitmentInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceRecruitmentInformation(tree);
}

void AllianceRecruitmentInformation::deserializeAsyncAs_AllianceRecruitmentInformation(FuncTree tree)
{
  SocialRecruitmentInformation::deserializeAsync(tree);
}

AllianceRecruitmentInformation::AllianceRecruitmentInformation()
{
  m_types<<ClassEnum::ALLIANCERECRUITMENTINFORMATION;
}

bool AllianceRecruitmentInformation::operator==(const AllianceRecruitmentInformation &compared)
{
  return true;
}

