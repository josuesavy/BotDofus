#include "GameFightCharacteristics.h"

void GameFightCharacteristics::serialize(Writer *output)
{
  this->serializeAs_GameFightCharacteristics(output);
}

void GameFightCharacteristics::serializeAs_GameFightCharacteristics(Writer *output)
{
  this->characteristics->serializeAs_CharacterCharacteristics(output);
  if(this->summoner < -9.007199254740992E15 || this->summoner > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightCharacteristics -"<<"Forbidden value (" << this->summoner << ") on element summoner.";
  }
  output->writeDouble(this->summoner);
  output->writeBool(this->summoned);
  output->writeByte(this->invisibilityState);
}

void GameFightCharacteristics::deserialize(Reader *input)
{
  this->deserializeAs_GameFightCharacteristics(input);
}

void GameFightCharacteristics::deserializeAs_GameFightCharacteristics(Reader *input)
{
  this->characteristics = QSharedPointer<CharacterCharacteristics>(new CharacterCharacteristics() );
  this->characteristics->deserialize(input);
  this->_summonerFunc(input);
  this->_summonedFunc(input);
  this->_invisibilityStateFunc(input);
}

void GameFightCharacteristics::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightCharacteristics(tree);
}

void GameFightCharacteristics::deserializeAsyncAs_GameFightCharacteristics(FuncTree tree)
{
  this->_characteristicstree = tree.addChild(std::bind(&GameFightCharacteristics::_characteristicstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightCharacteristics::_summonerFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightCharacteristics::_summonedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightCharacteristics::_invisibilityStateFunc, this, std::placeholders::_1));
}

void GameFightCharacteristics::_characteristicstreeFunc(Reader *input)
{
  this->characteristics = QSharedPointer<CharacterCharacteristics>(new CharacterCharacteristics() );
  this->characteristics->deserializeAsync(this->_characteristicstree);
}

void GameFightCharacteristics::_summonerFunc(Reader *input)
{
  this->summoner = input->readDouble();
  if(this->summoner < -9.007199254740992E15 || this->summoner > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightCharacteristics -"<<"Forbidden value (" << this->summoner << ") on element of GameFightCharacteristics.summoner.";
  }
}

void GameFightCharacteristics::_summonedFunc(Reader *input)
{
  this->summoned = input->readBool();
}

void GameFightCharacteristics::_invisibilityStateFunc(Reader *input)
{
  this->invisibilityState = input->readByte();
  if(this->invisibilityState < 0)
  {
    qDebug()<<"ERREUR - GameFightCharacteristics -"<<"Forbidden value (" << this->invisibilityState << ") on element of GameFightCharacteristics.invisibilityState.";
  }
}

GameFightCharacteristics::GameFightCharacteristics()
{
  m_types<<ClassEnum::GAMEFIGHTCHARACTERISTICS;
}

bool GameFightCharacteristics::operator==(const GameFightCharacteristics &compared)
{
  if(characteristics == compared.characteristics)
  if(summoner == compared.summoner)
  if(summoned == compared.summoned)
  if(invisibilityState == compared.invisibilityState)
  if(_characteristicstree == compared._characteristicstree)
  return true;
  
  return false;
}

