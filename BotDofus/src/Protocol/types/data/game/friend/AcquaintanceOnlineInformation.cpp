#include "AcquaintanceOnlineInformation.h"

void AcquaintanceOnlineInformation::serialize(Writer *output)
{
  this->serializeAs_AcquaintanceOnlineInformation(output);
}

void AcquaintanceOnlineInformation::serializeAs_AcquaintanceOnlineInformation(Writer *output)
{
  AcquaintanceInformation::serializeAs_AcquaintanceInformation(output);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AcquaintanceOnlineInformation -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  output->writeUTF(this->playerName);
  if(this->moodSmileyId < 0)
  {
    qDebug()<<"ERREUR - AcquaintanceOnlineInformation -"<<"Forbidden value (" << this->moodSmileyId << ") on element moodSmileyId.";
  }
  output->writeVarShort((int)this->moodSmileyId);
  output->writeShort((short)this->status->getTypes().last());
  this->status->serialize(output);
}

void AcquaintanceOnlineInformation::deserialize(Reader *input)
{
  this->deserializeAs_AcquaintanceOnlineInformation(input);
}

void AcquaintanceOnlineInformation::deserializeAs_AcquaintanceOnlineInformation(Reader *input)
{
  AcquaintanceInformation::deserialize(input);
  this->_playerIdFunc(input);
  this->_playerNameFunc(input);
  this->_moodSmileyIdFunc(input);
  uint _id4 = input->readUShort();
  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_id4));
  this->status->deserialize(input);
}

void AcquaintanceOnlineInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AcquaintanceOnlineInformation(tree);
}

void AcquaintanceOnlineInformation::deserializeAsyncAs_AcquaintanceOnlineInformation(FuncTree tree)
{
  AcquaintanceInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&AcquaintanceOnlineInformation::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AcquaintanceOnlineInformation::_playerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AcquaintanceOnlineInformation::_moodSmileyIdFunc, this, std::placeholders::_1));
  this->_statustree = tree.addChild(std::bind(&AcquaintanceOnlineInformation::_statustreeFunc, this, std::placeholders::_1));
}

void AcquaintanceOnlineInformation::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AcquaintanceOnlineInformation -"<<"Forbidden value (" << this->playerId << ") on element of AcquaintanceOnlineInformation.playerId.";
  }
}

void AcquaintanceOnlineInformation::_playerNameFunc(Reader *input)
{
  this->playerName = input->readUTF();
}

void AcquaintanceOnlineInformation::_moodSmileyIdFunc(Reader *input)
{
  this->moodSmileyId = input->readVarUhShort();
  if(this->moodSmileyId < 0)
  {
    qDebug()<<"ERREUR - AcquaintanceOnlineInformation -"<<"Forbidden value (" << this->moodSmileyId << ") on element of AcquaintanceOnlineInformation.moodSmileyId.";
  }
}

void AcquaintanceOnlineInformation::_statustreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_id));
  this->status->deserializeAsync(this->_statustree);
}

AcquaintanceOnlineInformation::AcquaintanceOnlineInformation()
{
  m_types<<ClassEnum::ACQUAINTANCEONLINEINFORMATION;
}

bool AcquaintanceOnlineInformation::operator==(const AcquaintanceOnlineInformation &compared)
{
  if(playerId == compared.playerId)
  if(playerName == compared.playerName)
  if(moodSmileyId == compared.moodSmileyId)
  if(status == compared.status)
  if(_statustree == compared._statustree)
  return true;
  
  return false;
}

