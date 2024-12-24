#include "SocialRecruitmentInformation.h"

void SocialRecruitmentInformation::serialize(Writer *output)
{
  this->serializeAs_SocialRecruitmentInformation(output);
}

void SocialRecruitmentInformation::serializeAs_SocialRecruitmentInformation(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->minLevelFacultative);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->invalidatedByModeration);
  _box0 = BooleanByteWrapper::setFlag(_box0, 2, this->recruitmentAutoLocked);
  output->writeByte(_box0);
  if(this->socialId < 0)
  {
    qDebug()<<"ERREUR - SocialRecruitmentInformation -"<<"Forbidden value (" << this->socialId << ") on element socialId.";
  }
  output->writeVarInt((int)this->socialId);
  output->writeByte(this->recruitmentType);
  output->writeUTF(this->recruitmentTitle);
  output->writeUTF(this->recruitmentText);
  output->writeShort((short)this->selectedLanguages.size());
  for(uint _i5 = 0; _i5 < this->selectedLanguages.size(); _i5++)
  {
    if(this->selectedLanguages[_i5] < 0)
    {
      qDebug()<<"ERREUR - SocialRecruitmentInformation -"<<"Forbidden value (" << this->selectedLanguages[_i5] << ") on element 5 (starting at 1) of selectedLanguages.";
    }
    output->writeVarInt((int)this->selectedLanguages[_i5]);
  }
  output->writeShort((short)this->selectedCriterion.size());
  for(uint _i6 = 0; _i6 < this->selectedCriterion.size(); _i6++)
  {
    if(this->selectedCriterion[_i6] < 0)
    {
      qDebug()<<"ERREUR - SocialRecruitmentInformation -"<<"Forbidden value (" << this->selectedCriterion[_i6] << ") on element 6 (starting at 1) of selectedCriterion.";
    }
    output->writeVarInt((int)this->selectedCriterion[_i6]);
  }
  if(this->minLevel < 0)
  {
    qDebug()<<"ERREUR - SocialRecruitmentInformation -"<<"Forbidden value (" << this->minLevel << ") on element minLevel.";
  }
  output->writeShort((short)this->minLevel);
  output->writeUTF(this->lastEditPlayerName);
  if(this->lastEditDate < -9007199254740992 || this->lastEditDate > 9007199254740992)
  {
    qDebug()<<"ERREUR - SocialRecruitmentInformation -"<<"Forbidden value (" << this->lastEditDate << ") on element lastEditDate.";
  }
  output->writeDouble(this->lastEditDate);
}

void SocialRecruitmentInformation::deserialize(Reader *input)
{
  this->deserializeAs_SocialRecruitmentInformation(input);
}

void SocialRecruitmentInformation::deserializeAs_SocialRecruitmentInformation(Reader *input)
{
  uint _val5 = 0;
  uint _val6 = 0;
  this->deserializeByteBoxes(input);
  this->_socialIdFunc(input);
  this->_recruitmentTypeFunc(input);
  this->_recruitmentTitleFunc(input);
  this->_recruitmentTextFunc(input);
  uint _selectedLanguagesLen = uint(input->readUShort());
  for(uint _i5 = 0; _i5 < _selectedLanguagesLen; _i5++)
  {
    _val5 = input->readVarUhInt();
    if(_val5 < 0)
    {
      qDebug()<<"ERREUR - SocialRecruitmentInformation -"<<"Forbidden value (" << _val5 << ") on elements of selectedLanguages.";
    }
    this->selectedLanguages.append(_val5);
  }
  uint _selectedCriterionLen = uint(input->readUShort());
  for(uint _i6 = 0; _i6 < _selectedCriterionLen; _i6++)
  {
    _val6 = input->readVarUhInt();
    if(_val6 < 0)
    {
      qDebug()<<"ERREUR - SocialRecruitmentInformation -"<<"Forbidden value (" << _val6 << ") on elements of selectedCriterion.";
    }
    this->selectedCriterion.append(_val6);
  }
  this->_minLevelFunc(input);
  this->_lastEditPlayerNameFunc(input);
  this->_lastEditDateFunc(input);
}

void SocialRecruitmentInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SocialRecruitmentInformation(tree);
}

void SocialRecruitmentInformation::deserializeAsyncAs_SocialRecruitmentInformation(FuncTree tree)
{
  tree.addChild(std::bind(&SocialRecruitmentInformation::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialRecruitmentInformation::_socialIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialRecruitmentInformation::_recruitmentTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialRecruitmentInformation::_recruitmentTitleFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialRecruitmentInformation::_recruitmentTextFunc, this, std::placeholders::_1));
  this->_selectedLanguagestree = tree.addChild(std::bind(&SocialRecruitmentInformation::_selectedLanguagestreeFunc, this, std::placeholders::_1));
  this->_selectedCriteriontree = tree.addChild(std::bind(&SocialRecruitmentInformation::_selectedCriteriontreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialRecruitmentInformation::_minLevelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialRecruitmentInformation::_lastEditPlayerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialRecruitmentInformation::_lastEditDateFunc, this, std::placeholders::_1));
}

void SocialRecruitmentInformation::deserializeByteBoxes(Reader *input)
{
  uint _box0 = uint(input->readByte());
  this->minLevelFacultative = BooleanByteWrapper::getFlag(_box0, 0);
  this->invalidatedByModeration = BooleanByteWrapper::getFlag(_box0, 1);
  this->recruitmentAutoLocked = BooleanByteWrapper::getFlag(_box0, 2);
}

void SocialRecruitmentInformation::_socialIdFunc(Reader *input)
{
  this->socialId = input->readVarUhInt();
  if(this->socialId < 0)
  {
    qDebug()<<"ERREUR - SocialRecruitmentInformation -"<<"Forbidden value (" << this->socialId << ") on element of SocialRecruitmentInformation.socialId.";
  }
}

void SocialRecruitmentInformation::_recruitmentTypeFunc(Reader *input)
{
  this->recruitmentType = input->readByte();
  if(this->recruitmentType < 0)
  {
    qDebug()<<"ERREUR - SocialRecruitmentInformation -"<<"Forbidden value (" << this->recruitmentType << ") on element of SocialRecruitmentInformation.recruitmentType.";
  }
}

void SocialRecruitmentInformation::_recruitmentTitleFunc(Reader *input)
{
  this->recruitmentTitle = input->readUTF();
}

void SocialRecruitmentInformation::_recruitmentTextFunc(Reader *input)
{
  this->recruitmentText = input->readUTF();
}

void SocialRecruitmentInformation::_selectedLanguagestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_selectedLanguagestree.addChild(std::bind(&SocialRecruitmentInformation::_selectedLanguagesFunc, this, std::placeholders::_1));
  }
}

void SocialRecruitmentInformation::_selectedLanguagesFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - SocialRecruitmentInformation -"<<"Forbidden value (" << _val << ") on elements of selectedLanguages.";
  }
  this->selectedLanguages.append(_val);
}

void SocialRecruitmentInformation::_selectedCriteriontreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_selectedCriteriontree.addChild(std::bind(&SocialRecruitmentInformation::_selectedCriterionFunc, this, std::placeholders::_1));
  }
}

void SocialRecruitmentInformation::_selectedCriterionFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - SocialRecruitmentInformation -"<<"Forbidden value (" << _val << ") on elements of selectedCriterion.";
  }
  this->selectedCriterion.append(_val);
}

void SocialRecruitmentInformation::_minLevelFunc(Reader *input)
{
  this->minLevel = input->readShort();
  if(this->minLevel < 0)
  {
    qDebug()<<"ERREUR - SocialRecruitmentInformation -"<<"Forbidden value (" << this->minLevel << ") on element of SocialRecruitmentInformation.minLevel.";
  }
}

void SocialRecruitmentInformation::_lastEditPlayerNameFunc(Reader *input)
{
  this->lastEditPlayerName = input->readUTF();
}

void SocialRecruitmentInformation::_lastEditDateFunc(Reader *input)
{
  this->lastEditDate = input->readDouble();
  if(this->lastEditDate < -9007199254740992 || this->lastEditDate > 9007199254740992)
  {
    qDebug()<<"ERREUR - SocialRecruitmentInformation -"<<"Forbidden value (" << this->lastEditDate << ") on element of SocialRecruitmentInformation.lastEditDate.";
  }
}

SocialRecruitmentInformation::SocialRecruitmentInformation()
{
  m_types<<ClassEnum::SOCIALRECRUITMENTINFORMATION;
}

bool SocialRecruitmentInformation::operator==(const SocialRecruitmentInformation &compared)
{
  if(socialId == compared.socialId)
  if(recruitmentType == compared.recruitmentType)
  if(recruitmentTitle == compared.recruitmentTitle)
  if(recruitmentText == compared.recruitmentText)
  if(selectedLanguages == compared.selectedLanguages)
  if(selectedCriterion == compared.selectedCriterion)
  if(minLevel == compared.minLevel)
  if(minLevelFacultative == compared.minLevelFacultative)
  if(invalidatedByModeration == compared.invalidatedByModeration)
  if(lastEditPlayerName == compared.lastEditPlayerName)
  if(lastEditDate == compared.lastEditDate)
  if(recruitmentAutoLocked == compared.recruitmentAutoLocked)
  if(_selectedLanguagestree == compared._selectedLanguagestree)
  if(_selectedCriteriontree == compared._selectedCriteriontree)
  return true;
  
  return false;
}

