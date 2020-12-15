#include "FriendSpouseOnlineInformations.h"

void FriendSpouseOnlineInformations::serialize(Writer *output)
{
  this->serializeAs_FriendSpouseOnlineInformations(output);
}

void FriendSpouseOnlineInformations::serializeAs_FriendSpouseOnlineInformations(Writer *output)
{
  FriendSpouseInformations::serializeAs_FriendSpouseInformations(output);
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->inFight);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->followSpouse);
  output->writeByte(_box0);
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FriendSpouseOnlineInformations -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - FriendSpouseOnlineInformations -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
}

void FriendSpouseOnlineInformations::deserialize(Reader *input)
{
  this->deserializeAs_FriendSpouseOnlineInformations(input);
}

void FriendSpouseOnlineInformations::deserializeAs_FriendSpouseOnlineInformations(Reader *input)
{
  FriendSpouseInformations::deserialize(input);
  this->deserializeByteBoxes(input);
  this->_mapIdFunc(input);
  this->_subAreaIdFunc(input);
}

void FriendSpouseOnlineInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendSpouseOnlineInformations(tree);
}

void FriendSpouseOnlineInformations::deserializeAsyncAs_FriendSpouseOnlineInformations(FuncTree tree)
{
  FriendSpouseInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&FriendSpouseOnlineInformations::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&FriendSpouseOnlineInformations::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FriendSpouseOnlineInformations::_subAreaIdFunc, this, std::placeholders::_1));
}

void FriendSpouseOnlineInformations::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->inFight = BooleanByteWrapper::getFlag(_box0, 0);
  this->followSpouse = BooleanByteWrapper::getFlag(_box0, 1);
}

void FriendSpouseOnlineInformations::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FriendSpouseOnlineInformations -"<<"Forbidden value (" << this->mapId << ") on element of FriendSpouseOnlineInformations.mapId.";
  }
}

void FriendSpouseOnlineInformations::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - FriendSpouseOnlineInformations -"<<"Forbidden value (" << this->subAreaId << ") on element of FriendSpouseOnlineInformations.subAreaId.";
  }
}

FriendSpouseOnlineInformations::FriendSpouseOnlineInformations()
{
  m_types<<ClassEnum::FRIENDSPOUSEONLINEINFORMATIONS;
}

bool FriendSpouseOnlineInformations::operator==(const FriendSpouseOnlineInformations &compared)
{
  if(mapId == compared.mapId)
  if(subAreaId == compared.subAreaId)
  if(inFight == compared.inFight)
  if(followSpouse == compared.followSpouse)
  return true;
  
  return false;
}

