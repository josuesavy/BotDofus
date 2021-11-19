#include "RecruitmentInformationMessage.h"

void RecruitmentInformationMessage::serialize(Writer *output)
{
  this->serializeAs_RecruitmentInformationMessage(output);
}

void RecruitmentInformationMessage::serializeAs_RecruitmentInformationMessage(Writer *output)
{
  this->recruitmentData.serializeAs_GuildRecruitmentInformation(output);
}

void RecruitmentInformationMessage::deserialize(Reader *input)
{
  this->deserializeAs_RecruitmentInformationMessage(input);
}

void RecruitmentInformationMessage::deserializeAs_RecruitmentInformationMessage(Reader *input)
{
  this->recruitmentData = GuildRecruitmentInformation();
  this->recruitmentData.deserialize(input);
}

void RecruitmentInformationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_RecruitmentInformationMessage(tree);
}

void RecruitmentInformationMessage::deserializeAsyncAs_RecruitmentInformationMessage(FuncTree tree)
{
  this->_recruitmentDatatree = tree.addChild(std::bind(&RecruitmentInformationMessage::_recruitmentDatatreeFunc, this, std::placeholders::_1));
}

void RecruitmentInformationMessage::_recruitmentDatatreeFunc(Reader *input)
{
  this->recruitmentData = GuildRecruitmentInformation();
  this->recruitmentData.deserializeAsync(this->_recruitmentDatatree);
}

RecruitmentInformationMessage::RecruitmentInformationMessage()
{
  m_type = MessageEnum::RECRUITMENTINFORMATIONMESSAGE;
}

