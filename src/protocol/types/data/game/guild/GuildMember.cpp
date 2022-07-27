#include "GuildMember.h"

void GuildMember::serialize(Writer *output)
{
  this->serializeAs_GuildMember(output);
}

void GuildMember::serializeAs_GuildMember(Writer *output)
{
  CharacterMinimalInformations::serializeAs_CharacterMinimalInformations(output);
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->sex);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->havenBagShared);
  output->writeByte(_box0);
  output->writeByte(this->breed);
  if(this->rankId < 0)
  {
    qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->rankId << ") on element rankId.";
  }
  output->writeVarInt((int)this->rankId);
  if(this->enrollmentDate < -9.007199254740992E15 || this->enrollmentDate > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->enrollmentDate << ") on element enrollmentDate.";
  }
  output->writeDouble(this->enrollmentDate);
  if(this->givenExperience < 0 || this->givenExperience > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->givenExperience << ") on element givenExperience.";
  }
  output->writeVarLong((double)this->givenExperience);
  if(this->experienceGivenPercent < 0 || this->experienceGivenPercent > 100)
  {
    qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->experienceGivenPercent << ") on element experienceGivenPercent.";
  }
  output->writeByte(this->experienceGivenPercent);
  output->writeByte(this->connected);
  output->writeByte(this->alignmentSide);
  if(this->hoursSinceLastConnection < 0 || this->hoursSinceLastConnection > 65535)
  {
    qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->hoursSinceLastConnection << ") on element hoursSinceLastConnection.";
  }
  output->writeShort((short)this->hoursSinceLastConnection);
  if(this->moodSmileyId < 0)
  {
    qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->moodSmileyId << ") on element moodSmileyId.";
  }
  output->writeVarShort((int)this->moodSmileyId);
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  output->writeInt((int)this->accountId);
  output->writeInt((int)this->achievementPoints);
  output->writeShort((short)this->status->getTypes().last());
  this->status->serialize(output);
  this->note.serializeAs_PlayerNote(output);
}

void GuildMember::deserialize(Reader *input)
{
  this->deserializeAs_GuildMember(input);
}

void GuildMember::deserializeAs_GuildMember(Reader *input)
{
  CharacterMinimalInformations::deserialize(input);
  this->deserializeByteBoxes(input);
  this->_breedFunc(input);
  this->_rankIdFunc(input);
  this->_enrollmentDateFunc(input);
  this->_givenExperienceFunc(input);
  this->_experienceGivenPercentFunc(input);
  this->_connectedFunc(input);
  this->_alignmentSideFunc(input);
  this->_hoursSinceLastConnectionFunc(input);
  this->_moodSmileyIdFunc(input);
  this->_accountIdFunc(input);
  this->_achievementPointsFunc(input);
  uint _id13 = input->readUShort();
  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_id13));
  this->status->deserialize(input);
  this->note = PlayerNote();
  this->note.deserialize(input);
}

void GuildMember::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildMember(tree);
}

void GuildMember::deserializeAsyncAs_GuildMember(FuncTree tree)
{
  CharacterMinimalInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GuildMember::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildMember::_breedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildMember::_rankIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildMember::_enrollmentDateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildMember::_givenExperienceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildMember::_experienceGivenPercentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildMember::_connectedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildMember::_alignmentSideFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildMember::_hoursSinceLastConnectionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildMember::_moodSmileyIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildMember::_accountIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildMember::_achievementPointsFunc, this, std::placeholders::_1));
  this->_statustree = tree.addChild(std::bind(&GuildMember::_statustreeFunc, this, std::placeholders::_1));
  this->_notetree = tree.addChild(std::bind(&GuildMember::_notetreeFunc, this, std::placeholders::_1));
}

void GuildMember::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->sex = BooleanByteWrapper::getFlag(_box0, 0);
  this->havenBagShared = BooleanByteWrapper::getFlag(_box0, 1);
}

void GuildMember::_breedFunc(Reader *input)
{
  this->breed = input->readByte();
}

void GuildMember::_rankIdFunc(Reader *input)
{
  this->rankId = input->readVarUhInt();
  if(this->rankId < 0)
  {
    qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->rankId << ") on element of GuildMember.rankId.";
  }
}

void GuildMember::_enrollmentDateFunc(Reader *input)
{
  this->enrollmentDate = input->readDouble();
  if(this->enrollmentDate < -9.007199254740992E15 || this->enrollmentDate > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->enrollmentDate << ") on element of GuildMember.enrollmentDate.";
  }
}

void GuildMember::_givenExperienceFunc(Reader *input)
{
  this->givenExperience = input->readVarUhLong();
  if(this->givenExperience < 0 || this->givenExperience > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->givenExperience << ") on element of GuildMember.givenExperience.";
  }
}

void GuildMember::_experienceGivenPercentFunc(Reader *input)
{
  this->experienceGivenPercent = input->readByte();
  if(this->experienceGivenPercent < 0 || this->experienceGivenPercent > 100)
  {
    qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->experienceGivenPercent << ") on element of GuildMember.experienceGivenPercent.";
  }
}

void GuildMember::_connectedFunc(Reader *input)
{
  this->connected = input->readByte();
  if(this->connected < 0)
  {
    qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->connected << ") on element of GuildMember.connected.";
  }
}

void GuildMember::_alignmentSideFunc(Reader *input)
{
  this->alignmentSide = input->readByte();
}

void GuildMember::_hoursSinceLastConnectionFunc(Reader *input)
{
  this->hoursSinceLastConnection = input->readUShort();
  if(this->hoursSinceLastConnection < 0 || this->hoursSinceLastConnection > 65535)
  {
    qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->hoursSinceLastConnection << ") on element of GuildMember.hoursSinceLastConnection.";
  }
}

void GuildMember::_moodSmileyIdFunc(Reader *input)
{
  this->moodSmileyId = input->readVarUhShort();
  if(this->moodSmileyId < 0)
  {
    qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->moodSmileyId << ") on element of GuildMember.moodSmileyId.";
  }
}

void GuildMember::_accountIdFunc(Reader *input)
{
  this->accountId = input->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->accountId << ") on element of GuildMember.accountId.";
  }
}

void GuildMember::_achievementPointsFunc(Reader *input)
{
  this->achievementPoints = input->readInt();
}

void GuildMember::_statustreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_id));
  this->status->deserializeAsync(this->_statustree);
}

void GuildMember::_notetreeFunc(Reader *input)
{
  this->note = PlayerNote();
  this->note.deserializeAsync(this->_notetree);
}

GuildMember::GuildMember()
{
  m_types<<ClassEnum::GUILDMEMBER;
}

bool GuildMember::operator==(const GuildMember &compared)
{
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(rankId == compared.rankId)
  if(enrollmentDate == compared.enrollmentDate)
  if(givenExperience == compared.givenExperience)
  if(experienceGivenPercent == compared.experienceGivenPercent)
  if(connected == compared.connected)
  if(alignmentSide == compared.alignmentSide)
  if(hoursSinceLastConnection == compared.hoursSinceLastConnection)
  if(moodSmileyId == compared.moodSmileyId)
  if(accountId == compared.accountId)
  if(achievementPoints == compared.achievementPoints)
  if(status == compared.status)
  if(havenBagShared == compared.havenBagShared)
  if(note == compared.note)
  if(_statustree == compared._statustree)
  if(_notetree == compared._notetree)
  return true;
  
  return false;
}

