#include "AllianceRecruitmentInformationMessage.h"

void AllianceRecruitmentInformationMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceRecruitmentInformationMessage(output);
}

void AllianceRecruitmentInformationMessage::serializeAs_AllianceRecruitmentInformationMessage(Writer *output)
{
  this->recruitmentData.serializeAs_AllianceRecruitmentInformation(output);
}

void AllianceRecruitmentInformationMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceRecruitmentInformationMessage(input);
}

void AllianceRecruitmentInformationMessage::deserializeAs_AllianceRecruitmentInformationMessage(Reader *input)
{
  this->recruitmentData = AllianceRecruitmentInformation();
  this->recruitmentData.deserialize(input);
}

void AllianceRecruitmentInformationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceRecruitmentInformationMessage(tree);
}

void AllianceRecruitmentInformationMessage::deserializeAsyncAs_AllianceRecruitmentInformationMessage(FuncTree tree)
{
  this->_recruitmentDatatree = tree.addChild(std::bind(&AllianceRecruitmentInformationMessage::_recruitmentDatatreeFunc, this, std::placeholders::_1));
}

void AllianceRecruitmentInformationMessage::_recruitmentDatatreeFunc(Reader *input)
{
  this->recruitmentData = AllianceRecruitmentInformation();
  this->recruitmentData.deserializeAsync(this->_recruitmentDatatree);
}

AllianceRecruitmentInformationMessage::AllianceRecruitmentInformationMessage()
{
  m_type = MessageEnum::ALLIANCERECRUITMENTINFORMATIONMESSAGE;
}

