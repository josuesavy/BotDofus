#include "GameContextSummonsInformation.h"

void GameContextSummonsInformation::serialize(Writer *output)
{
  this->serializeAs_GameContextSummonsInformation(output);
}

void GameContextSummonsInformation::serializeAs_GameContextSummonsInformation(Writer *output)
{
  output->writeShort((short)this->spawnInformation->getTypes().last());
  this->spawnInformation->serialize(output);
  if(this->wave < 0)
  {
    qDebug()<<"ERREUR - GameContextSummonsInformation -"<<"Forbidden value (" << this->wave << ") on element wave.";
  }
  output->writeByte(this->wave);
  this->look->serializeAs_EntityLook(output);
  output->writeShort((short)this->stats->getTypes().last());
  this->stats->serialize(output);
  output->writeShort((short)this->summons.size());
  for(uint _i5 = 0; _i5 < this->summons.size(); _i5++)
  {
    output->writeShort((short)qSharedPointerCast<GameContextBasicSpawnInformation>(this->summons[_i5])->getTypes().last());
    qSharedPointerCast<GameContextBasicSpawnInformation>(this->summons[_i5])->serialize(output);
  }
}

void GameContextSummonsInformation::deserialize(Reader *input)
{
  this->deserializeAs_GameContextSummonsInformation(input);
}

void GameContextSummonsInformation::deserializeAs_GameContextSummonsInformation(Reader *input)
{
  uint _id5 = 0;
  QSharedPointer<GameContextBasicSpawnInformation> _item5 ;
  uint _id1 = input->readUShort();
  this->spawnInformation = qSharedPointerCast<SpawnInformation>(ClassManagerSingleton::get()->getClass(_id1));
  this->spawnInformation->deserialize(input);
  this->_waveFunc(input);
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserialize(input);
  uint _id4 = input->readUShort();
  this->stats = qSharedPointerCast<GameFightMinimalStats>(ClassManagerSingleton::get()->getClass(_id4));
  this->stats->deserialize(input);
  uint _summonsLen = input->readUShort();
  for(uint _i5 = 0; _i5 < _summonsLen; _i5++)
  {
    _id5 = input->readUShort();
    _item5 = qSharedPointerCast<GameContextBasicSpawnInformation>(ClassManagerSingleton::get()->getClass(_id5));
    _item5->deserialize(input);
    this->summons.append(_item5);
  }
}

void GameContextSummonsInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameContextSummonsInformation(tree);
}

void GameContextSummonsInformation::deserializeAsyncAs_GameContextSummonsInformation(FuncTree tree)
{
  this->_spawnInformationtree = tree.addChild(std::bind(&GameContextSummonsInformation::_spawnInformationtreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameContextSummonsInformation::_waveFunc, this, std::placeholders::_1));
  this->_looktree = tree.addChild(std::bind(&GameContextSummonsInformation::_looktreeFunc, this, std::placeholders::_1));
  this->_statstree = tree.addChild(std::bind(&GameContextSummonsInformation::_statstreeFunc, this, std::placeholders::_1));
  this->_summonstree = tree.addChild(std::bind(&GameContextSummonsInformation::_summonstreeFunc, this, std::placeholders::_1));
}

void GameContextSummonsInformation::_spawnInformationtreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->spawnInformation = qSharedPointerCast<SpawnInformation>(ClassManagerSingleton::get()->getClass(_id));
  this->spawnInformation->deserializeAsync(this->_spawnInformationtree);
}

void GameContextSummonsInformation::_waveFunc(Reader *input)
{
  this->wave = input->readByte();
  if(this->wave < 0)
  {
    qDebug()<<"ERREUR - GameContextSummonsInformation -"<<"Forbidden value (" << this->wave << ") on element of GameContextSummonsInformation.wave.";
  }
}

void GameContextSummonsInformation::_looktreeFunc(Reader *input)
{
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserializeAsync(this->_looktree);
}

void GameContextSummonsInformation::_statstreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->stats = qSharedPointerCast<GameFightMinimalStats>(ClassManagerSingleton::get()->getClass(_id));
  this->stats->deserializeAsync(this->_statstree);
}

void GameContextSummonsInformation::_summonstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_summonstree.addChild(std::bind(&GameContextSummonsInformation::_summonsFunc, this, std::placeholders::_1));
  }
}

void GameContextSummonsInformation::_summonsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<GameContextBasicSpawnInformation> _item = qSharedPointerCast<GameContextBasicSpawnInformation>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->summons.append(_item);
}

GameContextSummonsInformation::GameContextSummonsInformation()
{
  m_types<<ClassEnum::GAMECONTEXTSUMMONSINFORMATION;
}

bool GameContextSummonsInformation::operator==(const GameContextSummonsInformation &compared)
{
  if(spawnInformation == compared.spawnInformation)
  if(wave == compared.wave)
  if(look == compared.look)
  if(stats == compared.stats)
  if(summons == compared.summons)
  if(_spawnInformationtree == compared._spawnInformationtree)
  if(_looktree == compared._looktree)
  if(_statstree == compared._statstree)
  if(_summonstree == compared._summonstree)
  return true;
  
  return false;
}

