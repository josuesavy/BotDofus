#include "DungeonPartyFinderPlayer.h"

void DungeonPartyFinderPlayer::serialize(Writer *output)
{
  this->serializeAs_DungeonPartyFinderPlayer(output);
}

void DungeonPartyFinderPlayer::serializeAs_DungeonPartyFinderPlayer(Writer *output)
{
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderPlayer -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  output->writeUTF(this->playerName);
  output->writeByte(this->breed);
  output->writeBool(this->sex);
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderPlayer -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeVarShort((int)this->level);
}

void DungeonPartyFinderPlayer::deserialize(Reader *input)
{
  this->deserializeAs_DungeonPartyFinderPlayer(input);
}

void DungeonPartyFinderPlayer::deserializeAs_DungeonPartyFinderPlayer(Reader *input)
{
  this->_playerIdFunc(input);
  this->_playerNameFunc(input);
  this->_breedFunc(input);
  this->_sexFunc(input);
  this->_levelFunc(input);
}

void DungeonPartyFinderPlayer::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DungeonPartyFinderPlayer(tree);
}

void DungeonPartyFinderPlayer::deserializeAsyncAs_DungeonPartyFinderPlayer(FuncTree tree)
{
  tree.addChild(std::bind(&DungeonPartyFinderPlayer::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&DungeonPartyFinderPlayer::_playerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&DungeonPartyFinderPlayer::_breedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&DungeonPartyFinderPlayer::_sexFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&DungeonPartyFinderPlayer::_levelFunc, this, std::placeholders::_1));
}

void DungeonPartyFinderPlayer::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderPlayer -"<<"Forbidden value (" << this->playerId << ") on element of DungeonPartyFinderPlayer.playerId.";
  }
}

void DungeonPartyFinderPlayer::_playerNameFunc(Reader *input)
{
  this->playerName = input->readUTF();
}

void DungeonPartyFinderPlayer::_breedFunc(Reader *input)
{
  this->breed = input->readByte();
  if(this->breed < (int)PlayableBreedEnum::FECA || this->breed > (int)PlayableBreedEnum::OUGINAK)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderPlayer -"<<"Forbidden value (" << this->breed << ") on element of DungeonPartyFinderPlayer.breed.";
  }
}

void DungeonPartyFinderPlayer::_sexFunc(Reader *input)
{
  this->sex = input->readBool();
}

void DungeonPartyFinderPlayer::_levelFunc(Reader *input)
{
  this->level = input->readVarUhShort();
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderPlayer -"<<"Forbidden value (" << this->level << ") on element of DungeonPartyFinderPlayer.level.";
  }
}

DungeonPartyFinderPlayer::DungeonPartyFinderPlayer()
{
  m_types<<ClassEnum::DUNGEONPARTYFINDERPLAYER;
}

bool DungeonPartyFinderPlayer::operator==(const DungeonPartyFinderPlayer &compared)
{
  if(playerId == compared.playerId)
  if(playerName == compared.playerName)
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(level == compared.level)
  return true;
  
  return false;
}

