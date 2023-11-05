#include "GameRolePlayGroupMonsterWaveInformations.h"

void GameRolePlayGroupMonsterWaveInformations::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayGroupMonsterWaveInformations(output);
}

void GameRolePlayGroupMonsterWaveInformations::serializeAs_GameRolePlayGroupMonsterWaveInformations(Writer *output)
{
  GameRolePlayGroupMonsterInformations::serializeAs_GameRolePlayGroupMonsterInformations(output);
  if(this->nbWaves < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayGroupMonsterWaveInformations -"<<"Forbidden value (" << this->nbWaves << ") on element nbWaves.";
  }
  output->writeByte(this->nbWaves);
  output->writeShort((short)this->alternatives.size());
  for(uint _i2 = 0; _i2 < this->alternatives.size(); _i2++)
  {
    output->writeShort((short)(this->alternatives[_i2]).getTypeId());
    (this->alternatives[_i2]).serialize(output);
  }
}

void GameRolePlayGroupMonsterWaveInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayGroupMonsterWaveInformations(input);
}

void GameRolePlayGroupMonsterWaveInformations::deserializeAs_GameRolePlayGroupMonsterWaveInformations(Reader *input)
{
  uint _id2 = 0;
   _item2 ;
  GameRolePlayGroupMonsterInformations::deserialize(input);
  this->_nbWavesFunc(input);
  uint _alternativesLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _alternativesLen; _i2++)
  {
    _id2 = uint(input->readUShort());
    _item2 = qSharedPointerCast<>(ClassManagerSingleton::get()->getClass(_id2));
    _item2.deserialize(input);
    this->alternatives.append(_item2);
  }
}

void GameRolePlayGroupMonsterWaveInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayGroupMonsterWaveInformations(tree);
}

void GameRolePlayGroupMonsterWaveInformations::deserializeAsyncAs_GameRolePlayGroupMonsterWaveInformations(FuncTree tree)
{
  GameRolePlayGroupMonsterInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GameRolePlayGroupMonsterWaveInformations::_nbWavesFunc, this, std::placeholders::_1));
  this->_alternativestree = tree.addChild(std::bind(&GameRolePlayGroupMonsterWaveInformations::_alternativestreeFunc, this, std::placeholders::_1));
}

void GameRolePlayGroupMonsterWaveInformations::_nbWavesFunc(Reader *input)
{
  this->nbWaves = input->readByte();
  if(this->nbWaves < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayGroupMonsterWaveInformations -"<<"Forbidden value (" << this->nbWaves << ") on element of GameRolePlayGroupMonsterWaveInformations.nbWaves.";
  }
}

void GameRolePlayGroupMonsterWaveInformations::_alternativestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_alternativestree.addChild(std::bind(&GameRolePlayGroupMonsterWaveInformations::_alternativesFunc, this, std::placeholders::_1));
  }
}

void GameRolePlayGroupMonsterWaveInformations::_alternativesFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
   _item = qSharedPointerCast<>(ClassManagerSingleton::get()->getClass(_id));
  _item.deserialize(input);
  this->alternatives.append(_item);
}

GameRolePlayGroupMonsterWaveInformations::GameRolePlayGroupMonsterWaveInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYGROUPMONSTERWAVEINFORMATIONS;
}

bool GameRolePlayGroupMonsterWaveInformations::operator==(const GameRolePlayGroupMonsterWaveInformations &compared)
{
  if(nbWaves == compared.nbWaves)
  if(alternatives == compared.alternatives)
  if(_alternativestree == compared._alternativestree)
  return true;
  
  return false;
}

