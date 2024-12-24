#include "AllianceUpdateRecruitmentInformationMessage.h"

void AllianceUpdateRecruitmentInformationMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceUpdateRecruitmentInformationMessage(output);
}

void AllianceUpdateRecruitmentInformationMessage::serializeAs_AllianceUpdateRecruitmentInformationMessage(Writer *output)
{
  this->recruitmentData.serializeAs_AllianceRecruitmentInformation(output);
}

void AllianceUpdateRecruitmentInformationMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceUpdateRecruitmentInformationMessage(input);
}

void AllianceUpdateRecruitmentInformationMessage::deserializeAs_AllianceUpdateRecruitmentInformationMessage(Reader *input)
{
  this->recruitmentData = AllianceRecruitmentInformation();
  this->recruitmentData.deserialize(input);
}

void AllianceUpdateRecruitmentInformationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceUpdateRecruitmentInformationMessage(tree);
}

void AllianceUpdateRecruitmentInformationMessage::deserializeAsyncAs_AllianceUpdateRecruitmentInformationMessage(FuncTree tree)
{
  this->_recruitmentDatatree = tree.addChild(std::bind(&AllianceUpdateRecruitmentInformationMessage::_recruitmentDatatreeFunc, this, std::placeholders::_1));
}

void AllianceUpdateRecruitmentInformationMessage::_recruitmentDatatreeFunc(Reader *input)
{
  this->recruitmentData = AllianceRecruitmentInformation();
  this->recruitmentData.deserializeAsync(this->_recruitmentDatatree);
}

AllianceUpdateRecruitmentInformationMessage::AllianceUpdateRecruitmentInformationMessage()
{
  m_type = MessageEnum::ALLIANCEUPDATERECRUITMENTINFORMATIONMESSAGE;
}

