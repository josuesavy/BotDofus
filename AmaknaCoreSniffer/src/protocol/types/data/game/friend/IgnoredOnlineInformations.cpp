#include "IgnoredOnlineInformations.h"

void IgnoredOnlineInformations::serialize(Writer *output)
{
  this->serializeAs_IgnoredOnlineInformations(output);
}

void IgnoredOnlineInformations::serializeAs_IgnoredOnlineInformations(Writer *output)
{
  IgnoredInformations::serializeAs_IgnoredInformations(output);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IgnoredOnlineInformations -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  output->writeUTF(this->playerName);
  output->writeByte(this->breed);
  output->writeBool(this->sex);
}

void IgnoredOnlineInformations::deserialize(Reader *input)
{
  this->deserializeAs_IgnoredOnlineInformations(input);
}

void IgnoredOnlineInformations::deserializeAs_IgnoredOnlineInformations(Reader *input)
{
  IgnoredInformations::deserialize(input);
  this->_playerIdFunc(input);
  this->_playerNameFunc(input);
  this->_breedFunc(input);
  this->_sexFunc(input);
}

void IgnoredOnlineInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IgnoredOnlineInformations(tree);
}

void IgnoredOnlineInformations::deserializeAsyncAs_IgnoredOnlineInformations(FuncTree tree)
{
  IgnoredInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&IgnoredOnlineInformations::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IgnoredOnlineInformations::_playerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IgnoredOnlineInformations::_breedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IgnoredOnlineInformations::_sexFunc, this, std::placeholders::_1));
}

void IgnoredOnlineInformations::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IgnoredOnlineInformations -"<<"Forbidden value (" << this->playerId << ") on element of IgnoredOnlineInformations.playerId.";
  }
}

void IgnoredOnlineInformations::_playerNameFunc(Reader *input)
{
  this->playerName = input->readUTF();
}

void IgnoredOnlineInformations::_breedFunc(Reader *input)
{
  this->breed = input->readByte();
  if(this->breed < (int)PlayableBreedEnum::FECA || this->breed > (int)PlayableBreedEnum::OUGINAK)
  {
    qDebug()<<"ERREUR - IgnoredOnlineInformations -"<<"Forbidden value (" << this->breed << ") on element of IgnoredOnlineInformations.breed.";
  }
}

void IgnoredOnlineInformations::_sexFunc(Reader *input)
{
  this->sex = input->readBool();
}

IgnoredOnlineInformations::IgnoredOnlineInformations()
{
  m_types<<ClassEnum::IGNOREDONLINEINFORMATIONS;
}

bool IgnoredOnlineInformations::operator==(const IgnoredOnlineInformations &compared)
{
  if(playerId == compared.playerId)
  if(playerName == compared.playerName)
  if(breed == compared.breed)
  if(sex == compared.sex)
  return true;
  
  return false;
}

