#include "GuildRecruitmentInformation.h"

void GuildRecruitmentInformation::serialize(Writer *output)
{
  this->serializeAs_GuildRecruitmentInformation(output);
}

void GuildRecruitmentInformation::serializeAs_GuildRecruitmentInformation(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->minLevelFacultative);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->minSuccessFacultative);
  _box0 = BooleanByteWrapper::setFlag(_box0, 2, this->invalidatedByModeration);
  _box0 = BooleanByteWrapper::setFlag(_box0, 3, this->recruitmentAutoLocked);
  output->writeByte(_box0);
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - GuildRecruitmentInformation -"<<"Forbidden value (" << this->guildId << ") on element guildId.";
  }
  output->writeVarInt((int)this->guildId);
  output->writeByte(this->recruitmentType);
  output->writeUTF(this->recruitmentTitle);
  output->writeUTF(this->recruitmentText);
  output->writeShort((short)this->selectedLanguages.size());
  for(uint _i5 = 0; _i5 < this->selectedLanguages.size(); _i5++)
  {
    if(this->selectedLanguages[_i5] < 0)
    {
      qDebug()<<"ERREUR - GuildRecruitmentInformation -"<<"Forbidden value (" << this->selectedLanguages[_i5] << ") on element 5 (starting at 1) of selectedLanguages.";
    }
    output->writeVarInt((int)this->selectedLanguages[_i5]);
  }
  output->writeShort((short)this->selectedCriterion.size());
  for(uint _i6 = 0; _i6 < this->selectedCriterion.size(); _i6++)
  {
    if(this->selectedCriterion[_i6] < 0)
    {
      qDebug()<<"ERREUR - GuildRecruitmentInformation -"<<"Forbidden value (" << this->selectedCriterion[_i6] << ") on element 6 (starting at 1) of selectedCriterion.";
    }
    output->writeVarInt((int)this->selectedCriterion[_i6]);
  }
  if(this->minLevel < 0)
  {
    qDebug()<<"ERREUR - GuildRecruitmentInformation -"<<"Forbidden value (" << this->minLevel << ") on element minLevel.";
  }
  output->writeShort((short)this->minLevel);
  if(this->minSuccess < 0)
  {
    qDebug()<<"ERREUR - GuildRecruitmentInformation -"<<"Forbidden value (" << this->minSuccess << ") on element minSuccess.";
  }
  output->writeVarInt((int)this->minSuccess);
  output->writeUTF(this->lastEditPlayerName);
  if(this->lastEditDate < -9.007199254740992E15 || this->lastEditDate > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildRecruitmentInformation -"<<"Forbidden value (" << this->lastEditDate << ") on element lastEditDate.";
  }
  output->writeDouble(this->lastEditDate);
}

void GuildRecruitmentInformation::deserialize(Reader *input)
{
  this->deserializeAs_GuildRecruitmentInformation(input);
}

void GuildRecruitmentInformation::deserializeAs_GuildRecruitmentInformation(Reader *input)
{
  uint _val5 = 0;
  uint _val6 = 0;
  this->deserializeByteBoxes(input);
  this->_guildIdFunc(input);
  this->_recruitmentTypeFunc(input);
  this->_recruitmentTitleFunc(input);
  this->_recruitmentTextFunc(input);
  uint _selectedLanguagesLen = input->readUShort();
  for(uint _i5 = 0; _i5 < _selectedLanguagesLen; _i5++)
  {
    _val5 = input->readVarUhInt();
    if(_val5 < 0)
    {
      qDebug()<<"ERREUR - GuildRecruitmentInformation -"<<"Forbidden value (" << _val5 << ") on elements of selectedLanguages.";
    }
    this->selectedLanguages.append(_val5);
  }
  uint _selectedCriterionLen = input->readUShort();
  for(uint _i6 = 0; _i6 < _selectedCriterionLen; _i6++)
  {
    _val6 = input->readVarUhInt();
    if(_val6 < 0)
    {
      qDebug()<<"ERREUR - GuildRecruitmentInformation -"<<"Forbidden value (" << _val6 << ") on elements of selectedCriterion.";
    }
    this->selectedCriterion.append(_val6);
  }
  this->_minLevelFunc(input);
  this->_minSuccessFunc(input);
  this->_lastEditPlayerNameFunc(input);
  this->_lastEditDateFunc(input);
}

void GuildRecruitmentInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildRecruitmentInformation(tree);
}

void GuildRecruitmentInformation::deserializeAsyncAs_GuildRecruitmentInformation(FuncTree tree)
{
  tree.addChild(std::bind(&GuildRecruitmentInformation::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildRecruitmentInformation::_guildIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildRecruitmentInformation::_recruitmentTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildRecruitmentInformation::_recruitmentTitleFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildRecruitmentInformation::_recruitmentTextFunc, this, std::placeholders::_1));
  this->_selectedLanguagestree = tree.addChild(std::bind(&GuildRecruitmentInformation::_selectedLanguagestreeFunc, this, std::placeholders::_1));
  this->_selectedCriteriontree = tree.addChild(std::bind(&GuildRecruitmentInformation::_selectedCriteriontreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildRecruitmentInformation::_minLevelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildRecruitmentInformation::_minSuccessFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildRecruitmentInformation::_lastEditPlayerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildRecruitmentInformation::_lastEditDateFunc, this, std::placeholders::_1));
}

void GuildRecruitmentInformation::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->minLevelFacultative = BooleanByteWrapper::getFlag(_box0, 0);
  this->minSuccessFacultative = BooleanByteWrapper::getFlag(_box0, 1);
  this->invalidatedByModeration = BooleanByteWrapper::getFlag(_box0, 2);
  this->recruitmentAutoLocked = BooleanByteWrapper::getFlag(_box0, 3);
}

void GuildRecruitmentInformation::_guildIdFunc(Reader *input)
{
  this->guildId = input->readVarUhInt();
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - GuildRecruitmentInformation -"<<"Forbidden value (" << this->guildId << ") on element of GuildRecruitmentInformation.guildId.";
  }
}

void GuildRecruitmentInformation::_recruitmentTypeFunc(Reader *input)
{
  this->recruitmentType = input->readByte();
  if(this->recruitmentType < 0)
  {
    qDebug()<<"ERREUR - GuildRecruitmentInformation -"<<"Forbidden value (" << this->recruitmentType << ") on element of GuildRecruitmentInformation.recruitmentType.";
  }
}

void GuildRecruitmentInformation::_recruitmentTitleFunc(Reader *input)
{
  this->recruitmentTitle = input->readUTF();
}

void GuildRecruitmentInformation::_recruitmentTextFunc(Reader *input)
{
  this->recruitmentText = input->readUTF();
}

void GuildRecruitmentInformation::_selectedLanguagestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_selectedLanguagestree.addChild(std::bind(&GuildRecruitmentInformation::_selectedLanguagesFunc, this, std::placeholders::_1));
  }
}

void GuildRecruitmentInformation::_selectedLanguagesFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - GuildRecruitmentInformation -"<<"Forbidden value (" << _val << ") on elements of selectedLanguages.";
  }
  this->selectedLanguages.append(_val);
}

void GuildRecruitmentInformation::_selectedCriteriontreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_selectedCriteriontree.addChild(std::bind(&GuildRecruitmentInformation::_selectedCriterionFunc, this, std::placeholders::_1));
  }
}

void GuildRecruitmentInformation::_selectedCriterionFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - GuildRecruitmentInformation -"<<"Forbidden value (" << _val << ") on elements of selectedCriterion.";
  }
  this->selectedCriterion.append(_val);
}

void GuildRecruitmentInformation::_minLevelFunc(Reader *input)
{
  this->minLevel = input->readShort();
  if(this->minLevel < 0)
  {
    qDebug()<<"ERREUR - GuildRecruitmentInformation -"<<"Forbidden value (" << this->minLevel << ") on element of GuildRecruitmentInformation.minLevel.";
  }
}

void GuildRecruitmentInformation::_minSuccessFunc(Reader *input)
{
  this->minSuccess = input->readVarUhInt();
  if(this->minSuccess < 0)
  {
    qDebug()<<"ERREUR - GuildRecruitmentInformation -"<<"Forbidden value (" << this->minSuccess << ") on element of GuildRecruitmentInformation.minSuccess.";
  }
}

void GuildRecruitmentInformation::_lastEditPlayerNameFunc(Reader *input)
{
  this->lastEditPlayerName = input->readUTF();
}

void GuildRecruitmentInformation::_lastEditDateFunc(Reader *input)
{
  this->lastEditDate = input->readDouble();
  if(this->lastEditDate < -9.007199254740992E15 || this->lastEditDate > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildRecruitmentInformation -"<<"Forbidden value (" << this->lastEditDate << ") on element of GuildRecruitmentInformation.lastEditDate.";
  }
}

GuildRecruitmentInformation::GuildRecruitmentInformation()
{
  m_types<<ClassEnum::GUILDRECRUITMENTINFORMATION;
}

bool GuildRecruitmentInformation::operator==(const GuildRecruitmentInformation &compared)
{
  if(guildId == compared.guildId)
  if(recruitmentType == compared.recruitmentType)
  if(recruitmentTitle == compared.recruitmentTitle)
  if(recruitmentText == compared.recruitmentText)
  if(selectedLanguages == compared.selectedLanguages)
  if(selectedCriterion == compared.selectedCriterion)
  if(minLevel == compared.minLevel)
  if(minLevelFacultative == compared.minLevelFacultative)
  if(minSuccess == compared.minSuccess)
  if(minSuccessFacultative == compared.minSuccessFacultative)
  if(invalidatedByModeration == compared.invalidatedByModeration)
  if(lastEditPlayerName == compared.lastEditPlayerName)
  if(lastEditDate == compared.lastEditDate)
  if(recruitmentAutoLocked == compared.recruitmentAutoLocked)
  if(_selectedLanguagestree == compared._selectedLanguagestree)
  if(_selectedCriteriontree == compared._selectedCriteriontree)
  return true;
  
  return false;
}

