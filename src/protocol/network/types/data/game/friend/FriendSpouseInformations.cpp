#include "FriendSpouseInformations.h"

void FriendSpouseInformations::serialize(Writer *output)
{
  this->serializeAs_FriendSpouseInformations(output);
}

void FriendSpouseInformations::serializeAs_FriendSpouseInformations(Writer *output)
{
  if(this->spouseAccountId < 0)
  {
    qDebug()<<"ERREUR - FriendSpouseInformations -"<<"Forbidden value (" << this->spouseAccountId << ") on element spouseAccountId.";
  }
  output->writeInt((int)this->spouseAccountId);
  if(this->spouseId < 0 || this->spouseId > 9007199254740992)
  {
    qDebug()<<"ERREUR - FriendSpouseInformations -"<<"Forbidden value (" << this->spouseId << ") on element spouseId.";
  }
  output->writeVarLong((double)this->spouseId);
  output->writeUTF(this->spouseName);
  if(this->spouseLevel < 0)
  {
    qDebug()<<"ERREUR - FriendSpouseInformations -"<<"Forbidden value (" << this->spouseLevel << ") on element spouseLevel.";
  }
  output->writeVarShort((int)this->spouseLevel);
  output->writeByte(this->breed);
  output->writeByte(this->sex);
  this->spouseEntityLook.serializeAs_EntityLook(output);
  this->guildInfo->serializeAs_GuildInformations(output);
  output->writeByte(this->alignmentSide);
}

void FriendSpouseInformations::deserialize(Reader *input)
{
  this->deserializeAs_FriendSpouseInformations(input);
}

void FriendSpouseInformations::deserializeAs_FriendSpouseInformations(Reader *input)
{
  this->_spouseAccountIdFunc(input);
  this->_spouseIdFunc(input);
  this->_spouseNameFunc(input);
  this->_spouseLevelFunc(input);
  this->_breedFunc(input);
  this->_sexFunc(input);
  this->spouseEntityLook = EntityLook();
  this->spouseEntityLook.deserialize(input);
  this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInfo->deserialize(input);
  this->_alignmentSideFunc(input);
}

void FriendSpouseInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendSpouseInformations(tree);
}

void FriendSpouseInformations::deserializeAsyncAs_FriendSpouseInformations(FuncTree tree)
{
  tree.addChild(std::bind(&FriendSpouseInformations::_spouseAccountIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FriendSpouseInformations::_spouseIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FriendSpouseInformations::_spouseNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FriendSpouseInformations::_spouseLevelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FriendSpouseInformations::_breedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FriendSpouseInformations::_sexFunc, this, std::placeholders::_1));
  this->_spouseEntityLooktree = tree.addChild(std::bind(&FriendSpouseInformations::_spouseEntityLooktreeFunc, this, std::placeholders::_1));
  this->_guildInfotree = tree.addChild(std::bind(&FriendSpouseInformations::_guildInfotreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FriendSpouseInformations::_alignmentSideFunc, this, std::placeholders::_1));
}

void FriendSpouseInformations::_spouseAccountIdFunc(Reader *input)
{
  this->spouseAccountId = input->readInt();
  if(this->spouseAccountId < 0)
  {
    qDebug()<<"ERREUR - FriendSpouseInformations -"<<"Forbidden value (" << this->spouseAccountId << ") on element of FriendSpouseInformations.spouseAccountId.";
  }
}

void FriendSpouseInformations::_spouseIdFunc(Reader *input)
{
  this->spouseId = input->readVarUhLong();
  if(this->spouseId < 0 || this->spouseId > 9007199254740992)
  {
    qDebug()<<"ERREUR - FriendSpouseInformations -"<<"Forbidden value (" << this->spouseId << ") on element of FriendSpouseInformations.spouseId.";
  }
}

void FriendSpouseInformations::_spouseNameFunc(Reader *input)
{
  this->spouseName = input->readUTF();
}

void FriendSpouseInformations::_spouseLevelFunc(Reader *input)
{
  this->spouseLevel = input->readVarUhShort();
  if(this->spouseLevel < 0)
  {
    qDebug()<<"ERREUR - FriendSpouseInformations -"<<"Forbidden value (" << this->spouseLevel << ") on element of FriendSpouseInformations.spouseLevel.";
  }
}

void FriendSpouseInformations::_breedFunc(Reader *input)
{
  this->breed = input->readByte();
}

void FriendSpouseInformations::_sexFunc(Reader *input)
{
  this->sex = input->readByte();
}

void FriendSpouseInformations::_spouseEntityLooktreeFunc(Reader *input)
{
  this->spouseEntityLook = EntityLook();
  this->spouseEntityLook.deserializeAsync(this->_spouseEntityLooktree);
}

void FriendSpouseInformations::_guildInfotreeFunc(Reader *input)
{
  this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInfo->deserializeAsync(this->_guildInfotree);
}

void FriendSpouseInformations::_alignmentSideFunc(Reader *input)
{
  this->alignmentSide = input->readByte();
}

FriendSpouseInformations::FriendSpouseInformations()
{
  m_types<<ClassEnum::FRIENDSPOUSEINFORMATIONS;
}

bool FriendSpouseInformations::operator==(const FriendSpouseInformations &compared)
{
  if(spouseAccountId == compared.spouseAccountId)
  if(spouseId == compared.spouseId)
  if(spouseName == compared.spouseName)
  if(spouseLevel == compared.spouseLevel)
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(spouseEntityLook == compared.spouseEntityLook)
  if(guildInfo == compared.guildInfo)
  if(alignmentSide == compared.alignmentSide)
  if(_spouseEntityLooktree == compared._spouseEntityLooktree)
  if(_guildInfotree == compared._guildInfotree)
  return true;
  
  return false;
}

