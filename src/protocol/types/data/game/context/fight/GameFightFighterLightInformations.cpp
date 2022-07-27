#include "GameFightFighterLightInformations.h"

void GameFightFighterLightInformations::serialize(Writer *output)
{
  this->serializeAs_GameFightFighterLightInformations(output);
}

void GameFightFighterLightInformations::serializeAs_GameFightFighterLightInformations(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->sex);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->alive);
  output->writeByte(_box0);
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightFighterLightInformations -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeDouble(this->id);
  if(this->wave < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterLightInformations -"<<"Forbidden value (" << this->wave << ") on element wave.";
  }
  output->writeByte(this->wave);
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterLightInformations -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeVarShort((int)this->level);
  output->writeByte(this->breed);
}

void GameFightFighterLightInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameFightFighterLightInformations(input);
}

void GameFightFighterLightInformations::deserializeAs_GameFightFighterLightInformations(Reader *input)
{
  this->deserializeByteBoxes(input);
  this->_idFunc(input);
  this->_waveFunc(input);
  this->_levelFunc(input);
  this->_breedFunc(input);
}

void GameFightFighterLightInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightFighterLightInformations(tree);
}

void GameFightFighterLightInformations::deserializeAsyncAs_GameFightFighterLightInformations(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightFighterLightInformations::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightFighterLightInformations::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightFighterLightInformations::_waveFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightFighterLightInformations::_levelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightFighterLightInformations::_breedFunc, this, std::placeholders::_1));
}

void GameFightFighterLightInformations::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->sex = BooleanByteWrapper::getFlag(_box0, 0);
  this->alive = BooleanByteWrapper::getFlag(_box0, 1);
}

void GameFightFighterLightInformations::_idFunc(Reader *input)
{
  this->id = input->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightFighterLightInformations -"<<"Forbidden value (" << this->id << ") on element of GameFightFighterLightInformations.id.";
  }
}

void GameFightFighterLightInformations::_waveFunc(Reader *input)
{
  this->wave = input->readByte();
  if(this->wave < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterLightInformations -"<<"Forbidden value (" << this->wave << ") on element of GameFightFighterLightInformations.wave.";
  }
}

void GameFightFighterLightInformations::_levelFunc(Reader *input)
{
  this->level = input->readVarUhShort();
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterLightInformations -"<<"Forbidden value (" << this->level << ") on element of GameFightFighterLightInformations.level.";
  }
}

void GameFightFighterLightInformations::_breedFunc(Reader *input)
{
  this->breed = input->readByte();
}

GameFightFighterLightInformations::GameFightFighterLightInformations()
{
  m_types<<ClassEnum::GAMEFIGHTFIGHTERLIGHTINFORMATIONS;
}

bool GameFightFighterLightInformations::operator==(const GameFightFighterLightInformations &compared)
{
  if(id == compared.id)
  if(wave == compared.wave)
  if(level == compared.level)
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(alive == compared.alive)
  return true;
  
  return false;
}

