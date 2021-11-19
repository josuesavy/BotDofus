#include "GameFightCharacterInformations.h"

void GameFightCharacterInformations::serialize(Writer *output)
{
  this->serializeAs_GameFightCharacterInformations(output);
}

void GameFightCharacterInformations::serializeAs_GameFightCharacterInformations(Writer *output)
{
  GameFightFighterNamedInformations::serializeAs_GameFightFighterNamedInformations(output);
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - GameFightCharacterInformations -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeVarShort((int)this->level);
  this->alignmentInfos.serializeAs_ActorAlignmentInformations(output);
  output->writeByte(this->breed);
  output->writeBool(this->sex);
}

void GameFightCharacterInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameFightCharacterInformations(input);
}

void GameFightCharacterInformations::deserializeAs_GameFightCharacterInformations(Reader *input)
{
  GameFightFighterNamedInformations::deserialize(input);
  this->_levelFunc(input);
  this->alignmentInfos = ActorAlignmentInformations();
  this->alignmentInfos.deserialize(input);
  this->_breedFunc(input);
  this->_sexFunc(input);
}

void GameFightCharacterInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightCharacterInformations(tree);
}

void GameFightCharacterInformations::deserializeAsyncAs_GameFightCharacterInformations(FuncTree tree)
{
  GameFightFighterNamedInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GameFightCharacterInformations::_levelFunc, this, std::placeholders::_1));
  this->_alignmentInfostree = tree.addChild(std::bind(&GameFightCharacterInformations::_alignmentInfostreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightCharacterInformations::_breedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightCharacterInformations::_sexFunc, this, std::placeholders::_1));
}

void GameFightCharacterInformations::_levelFunc(Reader *input)
{
  this->level = input->readVarUhShort();
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - GameFightCharacterInformations -"<<"Forbidden value (" << this->level << ") on element of GameFightCharacterInformations.level.";
  }
}

void GameFightCharacterInformations::_alignmentInfostreeFunc(Reader *input)
{
  this->alignmentInfos = ActorAlignmentInformations();
  this->alignmentInfos.deserializeAsync(this->_alignmentInfostree);
}

void GameFightCharacterInformations::_breedFunc(Reader *input)
{
  this->breed = input->readByte();
}

void GameFightCharacterInformations::_sexFunc(Reader *input)
{
  this->sex = input->readBool();
}

GameFightCharacterInformations::GameFightCharacterInformations()
{
  m_types<<ClassEnum::GAMEFIGHTCHARACTERINFORMATIONS;
}

bool GameFightCharacterInformations::operator==(const GameFightCharacterInformations &compared)
{
  if(level == compared.level)
  if(alignmentInfos == compared.alignmentInfos)
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(_alignmentInfostree == compared._alignmentInfostree)
  return true;
  
  return false;
}

