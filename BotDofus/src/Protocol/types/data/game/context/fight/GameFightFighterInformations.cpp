#include "GameFightFighterInformations.h"

void GameFightFighterInformations::serialize(Writer *output)
{
  this->serializeAs_GameFightFighterInformations(output);
}

void GameFightFighterInformations::serializeAs_GameFightFighterInformations(Writer *output)
{
  GameContextActorInformations::serializeAs_GameContextActorInformations(output);
  this->spawnInfo->serializeAs_GameContextBasicSpawnInformation(output);
  if(this->wave < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterInformations -"<<"Forbidden value (" << this->wave << ") on element wave.";
  }
  output->writeByte(this->wave);
  output->writeShort((short)this->stats->getTypes().last());
  this->stats->serialize(output);
  output->writeShort((short)this->previousPositions.size());
  for(uint _i4 = 0; _i4 < this->previousPositions.size(); _i4++)
  {
    if(this->previousPositions[_i4] < 0 || this->previousPositions[_i4] > 559)
    {
      qDebug()<<"ERREUR - GameFightFighterInformations -"<<"Forbidden value (" << this->previousPositions[_i4] << ") on element 4 (starting at 1) of previousPositions.";
    }
    output->writeVarShort((int)this->previousPositions[_i4]);
  }
}

void GameFightFighterInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameFightFighterInformations(input);
}

void GameFightFighterInformations::deserializeAs_GameFightFighterInformations(Reader *input)
{
  uint _val4 = 0;
  GameContextActorInformations::deserialize(input);
  this->spawnInfo = QSharedPointer<GameContextBasicSpawnInformation>(new GameContextBasicSpawnInformation() );
  this->spawnInfo->deserialize(input);
  this->_waveFunc(input);
  uint _id3 = input->readUShort();
  this->stats = qSharedPointerCast<GameFightCharacteristics>(ClassManagerSingleton::get()->getClass(_id3));
  this->stats->deserialize(input);
  uint _previousPositionsLen = input->readUShort();
  for(uint _i4 = 0; _i4 < _previousPositionsLen; _i4++)
  {
    _val4 = input->readVarUhShort();
    if(_val4 < 0 || _val4 > 559)
    {
      qDebug()<<"ERREUR - GameFightFighterInformations -"<<"Forbidden value (" << _val4 << ") on elements of previousPositions.";
    }
    this->previousPositions.append(_val4);
  }
}

void GameFightFighterInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightFighterInformations(tree);
}

void GameFightFighterInformations::deserializeAsyncAs_GameFightFighterInformations(FuncTree tree)
{
  GameContextActorInformations::deserializeAsync(tree);
  this->_spawnInfotree = tree.addChild(std::bind(&GameFightFighterInformations::_spawnInfotreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightFighterInformations::_waveFunc, this, std::placeholders::_1));
  this->_statstree = tree.addChild(std::bind(&GameFightFighterInformations::_statstreeFunc, this, std::placeholders::_1));
  this->_previousPositionstree = tree.addChild(std::bind(&GameFightFighterInformations::_previousPositionstreeFunc, this, std::placeholders::_1));
}

void GameFightFighterInformations::_spawnInfotreeFunc(Reader *input)
{
  this->spawnInfo = QSharedPointer<GameContextBasicSpawnInformation>(new GameContextBasicSpawnInformation() );
  this->spawnInfo->deserializeAsync(this->_spawnInfotree);
}

void GameFightFighterInformations::_waveFunc(Reader *input)
{
  this->wave = input->readByte();
  if(this->wave < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterInformations -"<<"Forbidden value (" << this->wave << ") on element of GameFightFighterInformations.wave.";
  }
}

void GameFightFighterInformations::_statstreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->stats = qSharedPointerCast<GameFightCharacteristics>(ClassManagerSingleton::get()->getClass(_id));
  this->stats->deserializeAsync(this->_statstree);
}

void GameFightFighterInformations::_previousPositionstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_previousPositionstree.addChild(std::bind(&GameFightFighterInformations::_previousPositionsFunc, this, std::placeholders::_1));
  }
}

void GameFightFighterInformations::_previousPositionsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0 || _val > 559)
  {
    qDebug()<<"ERREUR - GameFightFighterInformations -"<<"Forbidden value (" << _val << ") on elements of previousPositions.";
  }
  this->previousPositions.append(_val);
}

GameFightFighterInformations::GameFightFighterInformations()
{
  m_types<<ClassEnum::GAMEFIGHTFIGHTERINFORMATIONS;
}

bool GameFightFighterInformations::operator==(const GameFightFighterInformations &compared)
{
  if(spawnInfo == compared.spawnInfo)
  if(wave == compared.wave)
  if(stats == compared.stats)
  if(previousPositions == compared.previousPositions)
  if(_spawnInfotree == compared._spawnInfotree)
  if(_statstree == compared._statstree)
  if(_previousPositionstree == compared._previousPositionstree)
  return true;
  
  return false;
}

