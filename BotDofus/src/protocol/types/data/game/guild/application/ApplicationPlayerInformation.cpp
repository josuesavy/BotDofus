#include "ApplicationPlayerInformation.h"

void ApplicationPlayerInformation::serialize(Writer *output)
{
  this->serializeAs_ApplicationPlayerInformation(output);
}

void ApplicationPlayerInformation::serializeAs_ApplicationPlayerInformation(Writer *output)
{
  if(this->playerId < 0)
  {
    qDebug()<<"ERREUR - ApplicationPlayerInformation -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarInt((int)this->playerId);
  output->writeUTF(this->playerName);
  output->writeByte(this->breed);
  output->writeBool(this->sex);
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - ApplicationPlayerInformation -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeVarInt((int)this->level);
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - ApplicationPlayerInformation -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  output->writeVarInt((int)this->accountId);
  output->writeUTF(this->accountTag);
  output->writeUTF(this->accountNickname);
  this->status->serializeAs_PlayerStatus(output);
}

void ApplicationPlayerInformation::deserialize(Reader *input)
{
  this->deserializeAs_ApplicationPlayerInformation(input);
}

void ApplicationPlayerInformation::deserializeAs_ApplicationPlayerInformation(Reader *input)
{
  this->_playerIdFunc(input);
  this->_playerNameFunc(input);
  this->_breedFunc(input);
  this->_sexFunc(input);
  this->_levelFunc(input);
  this->_accountIdFunc(input);
  this->_accountTagFunc(input);
  this->_accountNicknameFunc(input);
  this->status = QSharedPointer<PlayerStatus>(new PlayerStatus() );
  this->status->deserialize(input);
}

void ApplicationPlayerInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ApplicationPlayerInformation(tree);
}

void ApplicationPlayerInformation::deserializeAsyncAs_ApplicationPlayerInformation(FuncTree tree)
{
  tree.addChild(std::bind(&ApplicationPlayerInformation::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ApplicationPlayerInformation::_playerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ApplicationPlayerInformation::_breedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ApplicationPlayerInformation::_sexFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ApplicationPlayerInformation::_levelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ApplicationPlayerInformation::_accountIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ApplicationPlayerInformation::_accountTagFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ApplicationPlayerInformation::_accountNicknameFunc, this, std::placeholders::_1));
  this->_statustree = tree.addChild(std::bind(&ApplicationPlayerInformation::_statustreeFunc, this, std::placeholders::_1));
}

void ApplicationPlayerInformation::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhInt();
  if(this->playerId < 0)
  {
    qDebug()<<"ERREUR - ApplicationPlayerInformation -"<<"Forbidden value (" << this->playerId << ") on element of ApplicationPlayerInformation.playerId.";
  }
}

void ApplicationPlayerInformation::_playerNameFunc(Reader *input)
{
  this->playerName = input->readUTF();
}

void ApplicationPlayerInformation::_breedFunc(Reader *input)
{
  this->breed = input->readByte();
  if(this->breed < (int)PlayableBreedEnum::FECA || this->breed > (int)PlayableBreedEnum::OUGINAK)
  {
    qDebug()<<"ERREUR - ApplicationPlayerInformation -"<<"Forbidden value (" << this->breed << ") on element of ApplicationPlayerInformation.breed.";
  }
}

void ApplicationPlayerInformation::_sexFunc(Reader *input)
{
  this->sex = input->readBool();
}

void ApplicationPlayerInformation::_levelFunc(Reader *input)
{
  this->level = input->readVarUhInt();
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - ApplicationPlayerInformation -"<<"Forbidden value (" << this->level << ") on element of ApplicationPlayerInformation.level.";
  }
}

void ApplicationPlayerInformation::_accountIdFunc(Reader *input)
{
  this->accountId = input->readVarUhInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - ApplicationPlayerInformation -"<<"Forbidden value (" << this->accountId << ") on element of ApplicationPlayerInformation.accountId.";
  }
}

void ApplicationPlayerInformation::_accountTagFunc(Reader *input)
{
  this->accountTag = input->readUTF();
}

void ApplicationPlayerInformation::_accountNicknameFunc(Reader *input)
{
  this->accountNickname = input->readUTF();
}

void ApplicationPlayerInformation::_statustreeFunc(Reader *input)
{
  this->status = QSharedPointer<PlayerStatus>(new PlayerStatus() );
  this->status->deserializeAsync(this->_statustree);
}

ApplicationPlayerInformation::ApplicationPlayerInformation()
{
  m_types<<ClassEnum::APPLICATIONPLAYERINFORMATION;
}

bool ApplicationPlayerInformation::operator==(const ApplicationPlayerInformation &compared)
{
  if(playerId == compared.playerId)
  if(playerName == compared.playerName)
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(level == compared.level)
  if(accountId == compared.accountId)
  if(accountTag == compared.accountTag)
  if(accountNickname == compared.accountNickname)
  if(status == compared.status)
  if(_statustree == compared._statustree)
  return true;
  
  return false;
}

