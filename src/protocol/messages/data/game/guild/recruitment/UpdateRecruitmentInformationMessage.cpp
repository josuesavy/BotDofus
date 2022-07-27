#include "UpdateRecruitmentInformationMessage.h"

void UpdateRecruitmentInformationMessage::serialize(Writer *output)
{
  this->serializeAs_UpdateRecruitmentInformationMessage(output);
}

void UpdateRecruitmentInformationMessage::serializeAs_UpdateRecruitmentInformationMessage(Writer *output)
{
  this->recruitmentData.serializeAs_GuildRecruitmentInformation(output);
}

void UpdateRecruitmentInformationMessage::deserialize(Reader *input)
{
  this->deserializeAs_UpdateRecruitmentInformationMessage(input);
}

void UpdateRecruitmentInformationMessage::deserializeAs_UpdateRecruitmentInformationMessage(Reader *input)
{
  this->recruitmentData = GuildRecruitmentInformation();
  this->recruitmentData.deserialize(input);
}

void UpdateRecruitmentInformationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_UpdateRecruitmentInformationMessage(tree);
}

void UpdateRecruitmentInformationMessage::deserializeAsyncAs_UpdateRecruitmentInformationMessage(FuncTree tree)
{
  this->_recruitmentDatatree = tree.addChild(std::bind(&UpdateRecruitmentInformationMessage::_recruitmentDatatreeFunc, this, std::placeholders::_1));
}

void UpdateRecruitmentInformationMessage::_recruitmentDatatreeFunc(Reader *input)
{
  this->recruitmentData = GuildRecruitmentInformation();
  this->recruitmentData.deserializeAsync(this->_recruitmentDatatree);
}

UpdateRecruitmentInformationMessage::UpdateRecruitmentInformationMessage()
{
  m_type = MessageEnum::UPDATERECRUITMENTINFORMATIONMESSAGE;
}

