#include "GuildMemberInfo.h"

void GuildMemberInfo::serialize(Writer *output)
{
  this->serializeAs_GuildMemberInfo(output);
}

void GuildMemberInfo::serializeAs_GuildMemberInfo(Writer *output)
{
  SocialMember::serializeAs_SocialMember(output);
  if(this->givenExperience < 0 || this->givenExperience > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildMemberInfo -"<<"Forbidden value (" << this->givenExperience << ") on element givenExperience.";
  }
  output->writeVarLong((double)this->givenExperience);
  if(this->experienceGivenPercent < 0 || this->experienceGivenPercent > 100)
  {
    qDebug()<<"ERREUR - GuildMemberInfo -"<<"Forbidden value (" << this->experienceGivenPercent << ") on element experienceGivenPercent.";
  }
  output->writeByte(this->experienceGivenPercent);
  output->writeByte(this->alignmentSide);
  if(this->moodSmileyId < 0)
  {
    qDebug()<<"ERREUR - GuildMemberInfo -"<<"Forbidden value (" << this->moodSmileyId << ") on element moodSmileyId.";
  }
  output->writeVarShort((int)this->moodSmileyId);
  output->writeInt((int)this->achievementPoints);
  output->writeBool(this->havenBagShared);
  this->note.serializeAs_PlayerNote(output);
}

void GuildMemberInfo::deserialize(Reader *input)
{
  this->deserializeAs_GuildMemberInfo(input);
}

void GuildMemberInfo::deserializeAs_GuildMemberInfo(Reader *input)
{
  SocialMember::deserialize(input);
  this->_givenExperienceFunc(input);
  this->_experienceGivenPercentFunc(input);
  this->_alignmentSideFunc(input);
  this->_moodSmileyIdFunc(input);
  this->_achievementPointsFunc(input);
  this->_havenBagSharedFunc(input);
  this->note = PlayerNote();
  this->note.deserialize(input);
}

void GuildMemberInfo::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildMemberInfo(tree);
}

void GuildMemberInfo::deserializeAsyncAs_GuildMemberInfo(FuncTree tree)
{
  SocialMember::deserializeAsync(tree);
  tree.addChild(std::bind(&GuildMemberInfo::_givenExperienceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildMemberInfo::_experienceGivenPercentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildMemberInfo::_alignmentSideFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildMemberInfo::_moodSmileyIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildMemberInfo::_achievementPointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildMemberInfo::_havenBagSharedFunc, this, std::placeholders::_1));
  this->_notetree = tree.addChild(std::bind(&GuildMemberInfo::_notetreeFunc, this, std::placeholders::_1));
}

void GuildMemberInfo::_givenExperienceFunc(Reader *input)
{
  this->givenExperience = input->readVarUhLong();
  if(this->givenExperience < 0 || this->givenExperience > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildMemberInfo -"<<"Forbidden value (" << this->givenExperience << ") on element of GuildMemberInfo.givenExperience.";
  }
}

void GuildMemberInfo::_experienceGivenPercentFunc(Reader *input)
{
  this->experienceGivenPercent = input->readByte();
  if(this->experienceGivenPercent < 0 || this->experienceGivenPercent > 100)
  {
    qDebug()<<"ERREUR - GuildMemberInfo -"<<"Forbidden value (" << this->experienceGivenPercent << ") on element of GuildMemberInfo.experienceGivenPercent.";
  }
}

void GuildMemberInfo::_alignmentSideFunc(Reader *input)
{
  this->alignmentSide = input->readByte();
}

void GuildMemberInfo::_moodSmileyIdFunc(Reader *input)
{
  this->moodSmileyId = input->readVarUhShort();
  if(this->moodSmileyId < 0)
  {
    qDebug()<<"ERREUR - GuildMemberInfo -"<<"Forbidden value (" << this->moodSmileyId << ") on element of GuildMemberInfo.moodSmileyId.";
  }
}

void GuildMemberInfo::_achievementPointsFunc(Reader *input)
{
  this->achievementPoints = input->readInt();
}

void GuildMemberInfo::_havenBagSharedFunc(Reader *input)
{
  this->havenBagShared = input->readBool();
}

void GuildMemberInfo::_notetreeFunc(Reader *input)
{
  this->note = PlayerNote();
  this->note.deserializeAsync(this->_notetree);
}

GuildMemberInfo::GuildMemberInfo()
{
  m_types<<ClassEnum::GUILDMEMBERINFO;
}

bool GuildMemberInfo::operator==(const GuildMemberInfo &compared)
{
  if(givenExperience == compared.givenExperience)
  if(experienceGivenPercent == compared.experienceGivenPercent)
  if(alignmentSide == compared.alignmentSide)
  if(moodSmileyId == compared.moodSmileyId)
  if(achievementPoints == compared.achievementPoints)
  if(havenBagShared == compared.havenBagShared)
  if(note == compared.note)
  if(_notetree == compared._notetree)
  return true;
  
  return false;
}

