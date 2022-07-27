#include "GameRolePlayNpcInformations.h"

void GameRolePlayNpcInformations::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayNpcInformations(output);
}

void GameRolePlayNpcInformations::serializeAs_GameRolePlayNpcInformations(Writer *output)
{
  GameRolePlayActorInformations::serializeAs_GameRolePlayActorInformations(output);
  if(this->npcId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayNpcInformations -"<<"Forbidden value (" << this->npcId << ") on element npcId.";
  }
  output->writeVarShort((int)this->npcId);
  output->writeBool(this->sex);
  if(this->specialArtworkId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayNpcInformations -"<<"Forbidden value (" << this->specialArtworkId << ") on element specialArtworkId.";
  }
  output->writeVarShort((int)this->specialArtworkId);
}

void GameRolePlayNpcInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayNpcInformations(input);
}

void GameRolePlayNpcInformations::deserializeAs_GameRolePlayNpcInformations(Reader *input)
{
  GameRolePlayActorInformations::deserialize(input);
  this->_npcIdFunc(input);
  this->_sexFunc(input);
  this->_specialArtworkIdFunc(input);
}

void GameRolePlayNpcInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayNpcInformations(tree);
}

void GameRolePlayNpcInformations::deserializeAsyncAs_GameRolePlayNpcInformations(FuncTree tree)
{
  GameRolePlayActorInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GameRolePlayNpcInformations::_npcIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayNpcInformations::_sexFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayNpcInformations::_specialArtworkIdFunc, this, std::placeholders::_1));
}

void GameRolePlayNpcInformations::_npcIdFunc(Reader *input)
{
  this->npcId = input->readVarUhShort();
  if(this->npcId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayNpcInformations -"<<"Forbidden value (" << this->npcId << ") on element of GameRolePlayNpcInformations.npcId.";
  }
}

void GameRolePlayNpcInformations::_sexFunc(Reader *input)
{
  this->sex = input->readBool();
}

void GameRolePlayNpcInformations::_specialArtworkIdFunc(Reader *input)
{
  this->specialArtworkId = input->readVarUhShort();
  if(this->specialArtworkId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayNpcInformations -"<<"Forbidden value (" << this->specialArtworkId << ") on element of GameRolePlayNpcInformations.specialArtworkId.";
  }
}

GameRolePlayNpcInformations::GameRolePlayNpcInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYNPCINFORMATIONS;
}

bool GameRolePlayNpcInformations::operator==(const GameRolePlayNpcInformations &compared)
{
  if(npcId == compared.npcId)
  if(sex == compared.sex)
  if(specialArtworkId == compared.specialArtworkId)
  return true;
  
  return false;
}

