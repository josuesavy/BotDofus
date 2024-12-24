#include "FightResultExperienceData.h"

void FightResultExperienceData::serialize(Writer *output)
{
  this->serializeAs_FightResultExperienceData(output);
}

void FightResultExperienceData::serializeAs_FightResultExperienceData(Writer *output)
{
  FightResultAdditionalData::serializeAs_FightResultAdditionalData(output);
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->showExperience);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->showExperienceLevelFloor);
  _box0 = BooleanByteWrapper::setFlag(_box0, 2, this->showExperienceNextLevelFloor);
  _box0 = BooleanByteWrapper::setFlag(_box0, 3, this->showExperienceFightDelta);
  _box0 = BooleanByteWrapper::setFlag(_box0, 4, this->showExperienceForGuild);
  _box0 = BooleanByteWrapper::setFlag(_box0, 5, this->showExperienceForMount);
  _box0 = BooleanByteWrapper::setFlag(_box0, 6, this->isIncarnationExperience);
  output->writeByte(_box0);
  if(this->experience < 0 || this->experience > 9007199254740992)
  {
    qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experience << ") on element experience.";
  }
  output->writeVarLong((double)this->experience);
  if(this->experienceLevelFloor < 0 || this->experienceLevelFloor > 9007199254740992)
  {
    qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceLevelFloor << ") on element experienceLevelFloor.";
  }
  output->writeVarLong((double)this->experienceLevelFloor);
  if(this->experienceNextLevelFloor < 0 || this->experienceNextLevelFloor > 9007199254740992)
  {
    qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceNextLevelFloor << ") on element experienceNextLevelFloor.";
  }
  output->writeVarLong((double)this->experienceNextLevelFloor);
  if(this->experienceFightDelta < 0 || this->experienceFightDelta > 9007199254740992)
  {
    qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceFightDelta << ") on element experienceFightDelta.";
  }
  output->writeVarLong((double)this->experienceFightDelta);
  if(this->experienceForGuild < 0 || this->experienceForGuild > 9007199254740992)
  {
    qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceForGuild << ") on element experienceForGuild.";
  }
  output->writeVarLong((double)this->experienceForGuild);
  if(this->experienceForMount < 0 || this->experienceForMount > 9007199254740992)
  {
    qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceForMount << ") on element experienceForMount.";
  }
  output->writeVarLong((double)this->experienceForMount);
  if(this->rerollExperienceMul < 0)
  {
    qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->rerollExperienceMul << ") on element rerollExperienceMul.";
  }
  output->writeByte(this->rerollExperienceMul);
}

void FightResultExperienceData::deserialize(Reader *input)
{
  this->deserializeAs_FightResultExperienceData(input);
}

void FightResultExperienceData::deserializeAs_FightResultExperienceData(Reader *input)
{
  FightResultAdditionalData::deserialize(input);
  this->deserializeByteBoxes(input);
  this->_experienceFunc(input);
  this->_experienceLevelFloorFunc(input);
  this->_experienceNextLevelFloorFunc(input);
  this->_experienceFightDeltaFunc(input);
  this->_experienceForGuildFunc(input);
  this->_experienceForMountFunc(input);
  this->_rerollExperienceMulFunc(input);
}

void FightResultExperienceData::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightResultExperienceData(tree);
}

void FightResultExperienceData::deserializeAsyncAs_FightResultExperienceData(FuncTree tree)
{
  FightResultAdditionalData::deserializeAsync(tree);
  tree.addChild(std::bind(&FightResultExperienceData::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightResultExperienceData::_experienceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightResultExperienceData::_experienceLevelFloorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightResultExperienceData::_experienceNextLevelFloorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightResultExperienceData::_experienceFightDeltaFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightResultExperienceData::_experienceForGuildFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightResultExperienceData::_experienceForMountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightResultExperienceData::_rerollExperienceMulFunc, this, std::placeholders::_1));
}

void FightResultExperienceData::deserializeByteBoxes(Reader *input)
{
  uint _box0 = uint(input->readByte());
  this->showExperience = BooleanByteWrapper::getFlag(_box0, 0);
  this->showExperienceLevelFloor = BooleanByteWrapper::getFlag(_box0, 1);
  this->showExperienceNextLevelFloor = BooleanByteWrapper::getFlag(_box0, 2);
  this->showExperienceFightDelta = BooleanByteWrapper::getFlag(_box0, 3);
  this->showExperienceForGuild = BooleanByteWrapper::getFlag(_box0, 4);
  this->showExperienceForMount = BooleanByteWrapper::getFlag(_box0, 5);
  this->isIncarnationExperience = BooleanByteWrapper::getFlag(_box0, 6);
}

void FightResultExperienceData::_experienceFunc(Reader *input)
{
  this->experience = input->readVarUhLong();
  if(this->experience < 0 || this->experience > 9007199254740992)
  {
    qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experience << ") on element of FightResultExperienceData.experience.";
  }
}

void FightResultExperienceData::_experienceLevelFloorFunc(Reader *input)
{
  this->experienceLevelFloor = input->readVarUhLong();
  if(this->experienceLevelFloor < 0 || this->experienceLevelFloor > 9007199254740992)
  {
    qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceLevelFloor << ") on element of FightResultExperienceData.experienceLevelFloor.";
  }
}

void FightResultExperienceData::_experienceNextLevelFloorFunc(Reader *input)
{
  this->experienceNextLevelFloor = input->readVarUhLong();
  if(this->experienceNextLevelFloor < 0 || this->experienceNextLevelFloor > 9007199254740992)
  {
    qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceNextLevelFloor << ") on element of FightResultExperienceData.experienceNextLevelFloor.";
  }
}

void FightResultExperienceData::_experienceFightDeltaFunc(Reader *input)
{
  this->experienceFightDelta = input->readVarUhLong();
  if(this->experienceFightDelta < 0 || this->experienceFightDelta > 9007199254740992)
  {
    qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceFightDelta << ") on element of FightResultExperienceData.experienceFightDelta.";
  }
}

void FightResultExperienceData::_experienceForGuildFunc(Reader *input)
{
  this->experienceForGuild = input->readVarUhLong();
  if(this->experienceForGuild < 0 || this->experienceForGuild > 9007199254740992)
  {
    qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceForGuild << ") on element of FightResultExperienceData.experienceForGuild.";
  }
}

void FightResultExperienceData::_experienceForMountFunc(Reader *input)
{
  this->experienceForMount = input->readVarUhLong();
  if(this->experienceForMount < 0 || this->experienceForMount > 9007199254740992)
  {
    qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceForMount << ") on element of FightResultExperienceData.experienceForMount.";
  }
}

void FightResultExperienceData::_rerollExperienceMulFunc(Reader *input)
{
  this->rerollExperienceMul = input->readByte();
  if(this->rerollExperienceMul < 0)
  {
    qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->rerollExperienceMul << ") on element of FightResultExperienceData.rerollExperienceMul.";
  }
}

FightResultExperienceData::FightResultExperienceData()
{
  m_types<<ClassEnum::FIGHTRESULTEXPERIENCEDATA;
}

bool FightResultExperienceData::operator==(const FightResultExperienceData &compared)
{
  if(experience == compared.experience)
  if(showExperience == compared.showExperience)
  if(experienceLevelFloor == compared.experienceLevelFloor)
  if(showExperienceLevelFloor == compared.showExperienceLevelFloor)
  if(experienceNextLevelFloor == compared.experienceNextLevelFloor)
  if(showExperienceNextLevelFloor == compared.showExperienceNextLevelFloor)
  if(experienceFightDelta == compared.experienceFightDelta)
  if(showExperienceFightDelta == compared.showExperienceFightDelta)
  if(experienceForGuild == compared.experienceForGuild)
  if(showExperienceForGuild == compared.showExperienceForGuild)
  if(experienceForMount == compared.experienceForMount)
  if(showExperienceForMount == compared.showExperienceForMount)
  if(isIncarnationExperience == compared.isIncarnationExperience)
  if(rerollExperienceMul == compared.rerollExperienceMul)
  return true;
  
  return false;
}

