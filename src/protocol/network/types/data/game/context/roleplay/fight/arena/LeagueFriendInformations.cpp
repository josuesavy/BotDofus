#include "LeagueFriendInformations.h"

void LeagueFriendInformations::serialize(Writer *output)
{
  this->serializeAs_LeagueFriendInformations(output);
}

void LeagueFriendInformations::serializeAs_LeagueFriendInformations(Writer *output)
{
  AbstractContactInformations::serializeAs_AbstractContactInformations(output);
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - LeagueFriendInformations -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  output->writeUTF(this->playerName);
  output->writeByte(this->breed);
  output->writeBool(this->sex);
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - LeagueFriendInformations -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeVarShort((int)this->level);
  output->writeVarShort((int)this->leagueId);
  output->writeVarShort((int)this->totalLeaguePoints);
  output->writeInt((int)this->ladderPosition);
}

void LeagueFriendInformations::deserialize(Reader *input)
{
  this->deserializeAs_LeagueFriendInformations(input);
}

void LeagueFriendInformations::deserializeAs_LeagueFriendInformations(Reader *input)
{
  AbstractContactInformations::deserialize(input);
  this->_playerIdFunc(input);
  this->_playerNameFunc(input);
  this->_breedFunc(input);
  this->_sexFunc(input);
  this->_levelFunc(input);
  this->_leagueIdFunc(input);
  this->_totalLeaguePointsFunc(input);
  this->_ladderPositionFunc(input);
}

void LeagueFriendInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_LeagueFriendInformations(tree);
}

void LeagueFriendInformations::deserializeAsyncAs_LeagueFriendInformations(FuncTree tree)
{
  AbstractContactInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&LeagueFriendInformations::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&LeagueFriendInformations::_playerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&LeagueFriendInformations::_breedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&LeagueFriendInformations::_sexFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&LeagueFriendInformations::_levelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&LeagueFriendInformations::_leagueIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&LeagueFriendInformations::_totalLeaguePointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&LeagueFriendInformations::_ladderPositionFunc, this, std::placeholders::_1));
}

void LeagueFriendInformations::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - LeagueFriendInformations -"<<"Forbidden value (" << this->playerId << ") on element of LeagueFriendInformations.playerId.";
  }
}

void LeagueFriendInformations::_playerNameFunc(Reader *input)
{
  this->playerName = input->readUTF();
}

void LeagueFriendInformations::_breedFunc(Reader *input)
{
  this->breed = input->readByte();
  if(this->breed < (int)PlayableBreedEnum::FECA || this->breed > (int)PlayableBreedEnum::FORGELANCE)
  {
    qDebug()<<"ERREUR - LeagueFriendInformations -"<<"Forbidden value (" << this->breed << ") on element of LeagueFriendInformations.breed.";
  }
}

void LeagueFriendInformations::_sexFunc(Reader *input)
{
  this->sex = input->readBool();
}

void LeagueFriendInformations::_levelFunc(Reader *input)
{
  this->level = input->readVarUhShort();
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - LeagueFriendInformations -"<<"Forbidden value (" << this->level << ") on element of LeagueFriendInformations.level.";
  }
}

void LeagueFriendInformations::_leagueIdFunc(Reader *input)
{
  this->leagueId = input->readVarShort();
}

void LeagueFriendInformations::_totalLeaguePointsFunc(Reader *input)
{
  this->totalLeaguePoints = input->readVarShort();
}

void LeagueFriendInformations::_ladderPositionFunc(Reader *input)
{
  this->ladderPosition = input->readInt();
}

LeagueFriendInformations::LeagueFriendInformations()
{
  m_types<<ClassEnum::LEAGUEFRIENDINFORMATIONS;
}

bool LeagueFriendInformations::operator==(const LeagueFriendInformations &compared)
{
  if(playerId == compared.playerId)
  if(playerName == compared.playerName)
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(level == compared.level)
  if(leagueId == compared.leagueId)
  if(totalLeaguePoints == compared.totalLeaguePoints)
  if(ladderPosition == compared.ladderPosition)
  return true;
  
  return false;
}

