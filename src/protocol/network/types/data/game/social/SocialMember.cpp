#include "SocialMember.h"

void SocialMember::serialize(Writer *output)
{
  this->serializeAs_SocialMember(output);
}

void SocialMember::serializeAs_SocialMember(Writer *output)
{
  CharacterMinimalInformations::serializeAs_CharacterMinimalInformations(output);
  output->writeByte(this->breed);
  output->writeBool(this->sex);
  output->writeByte(this->connected);
  if(this->hoursSinceLastConnection < 0 || this->hoursSinceLastConnection > 65535)
  {
    qDebug()<<"ERREUR - SocialMember -"<<"Forbidden value (" << this->hoursSinceLastConnection << ") on element hoursSinceLastConnection.";
  }
  output->writeShort((short)this->hoursSinceLastConnection);
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - SocialMember -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  output->writeInt((int)this->accountId);
  output->writeShort((short)this->status->getTypes().last());
  this->status->serialize(output);
  output->writeInt((int)this->rankId);
  if(this->enrollmentDate < -9007199254740992 || this->enrollmentDate > 9007199254740992)
  {
    qDebug()<<"ERREUR - SocialMember -"<<"Forbidden value (" << this->enrollmentDate << ") on element enrollmentDate.";
  }
  output->writeDouble(this->enrollmentDate);
}

void SocialMember::deserialize(Reader *input)
{
  this->deserializeAs_SocialMember(input);
}

void SocialMember::deserializeAs_SocialMember(Reader *input)
{
  CharacterMinimalInformations::deserialize(input);
  this->_breedFunc(input);
  this->_sexFunc(input);
  this->_connectedFunc(input);
  this->_hoursSinceLastConnectionFunc(input);
  this->_accountIdFunc(input);
  uint _id6 = uint(input->readUShort());
  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_id6));
  this->status->deserialize(input);
  this->_rankIdFunc(input);
  this->_enrollmentDateFunc(input);
}

void SocialMember::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SocialMember(tree);
}

void SocialMember::deserializeAsyncAs_SocialMember(FuncTree tree)
{
  CharacterMinimalInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&SocialMember::_breedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialMember::_sexFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialMember::_connectedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialMember::_hoursSinceLastConnectionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialMember::_accountIdFunc, this, std::placeholders::_1));
  this->_statustree = tree.addChild(std::bind(&SocialMember::_statustreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialMember::_rankIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialMember::_enrollmentDateFunc, this, std::placeholders::_1));
}

void SocialMember::_breedFunc(Reader *input)
{
  this->breed = input->readByte();
}

void SocialMember::_sexFunc(Reader *input)
{
  this->sex = input->readBool();
}

void SocialMember::_connectedFunc(Reader *input)
{
  this->connected = input->readByte();
  if(this->connected < 0)
  {
    qDebug()<<"ERREUR - SocialMember -"<<"Forbidden value (" << this->connected << ") on element of SocialMember.connected.";
  }
}

void SocialMember::_hoursSinceLastConnectionFunc(Reader *input)
{
  this->hoursSinceLastConnection = input->readUShort();
  if(this->hoursSinceLastConnection < 0 || this->hoursSinceLastConnection > 65535)
  {
    qDebug()<<"ERREUR - SocialMember -"<<"Forbidden value (" << this->hoursSinceLastConnection << ") on element of SocialMember.hoursSinceLastConnection.";
  }
}

void SocialMember::_accountIdFunc(Reader *input)
{
  this->accountId = input->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - SocialMember -"<<"Forbidden value (" << this->accountId << ") on element of SocialMember.accountId.";
  }
}

void SocialMember::_statustreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_id));
  this->status->deserializeAsync(this->_statustree);
}

void SocialMember::_rankIdFunc(Reader *input)
{
  this->rankId = input->readInt();
}

void SocialMember::_enrollmentDateFunc(Reader *input)
{
  this->enrollmentDate = input->readDouble();
  if(this->enrollmentDate < -9007199254740992 || this->enrollmentDate > 9007199254740992)
  {
    qDebug()<<"ERREUR - SocialMember -"<<"Forbidden value (" << this->enrollmentDate << ") on element of SocialMember.enrollmentDate.";
  }
}

SocialMember::SocialMember()
{
  m_types<<ClassEnum::SOCIALMEMBER;
}

bool SocialMember::operator==(const SocialMember &compared)
{
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(connected == compared.connected)
  if(hoursSinceLastConnection == compared.hoursSinceLastConnection)
  if(accountId == compared.accountId)
  if(status == compared.status)
  if(rankId == compared.rankId)
  if(enrollmentDate == compared.enrollmentDate)
  if(_statustree == compared._statustree)
  return true;
  
  return false;
}

