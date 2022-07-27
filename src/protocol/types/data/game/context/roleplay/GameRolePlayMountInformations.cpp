#include "GameRolePlayMountInformations.h"

void GameRolePlayMountInformations::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayMountInformations(output);
}

void GameRolePlayMountInformations::serializeAs_GameRolePlayMountInformations(Writer *output)
{
  GameRolePlayNamedActorInformations::serializeAs_GameRolePlayNamedActorInformations(output);
  output->writeUTF(this->ownerName);
  if(this->level < 0 || this->level > 255)
  {
    qDebug()<<"ERREUR - GameRolePlayMountInformations -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeByte(this->level);
}

void GameRolePlayMountInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayMountInformations(input);
}

void GameRolePlayMountInformations::deserializeAs_GameRolePlayMountInformations(Reader *input)
{
  GameRolePlayNamedActorInformations::deserialize(input);
  this->_ownerNameFunc(input);
  this->_levelFunc(input);
}

void GameRolePlayMountInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayMountInformations(tree);
}

void GameRolePlayMountInformations::deserializeAsyncAs_GameRolePlayMountInformations(FuncTree tree)
{
  GameRolePlayNamedActorInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GameRolePlayMountInformations::_ownerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayMountInformations::_levelFunc, this, std::placeholders::_1));
}

void GameRolePlayMountInformations::_ownerNameFunc(Reader *input)
{
  this->ownerName = input->readUTF();
}

void GameRolePlayMountInformations::_levelFunc(Reader *input)
{
  this->level = input->readUByte();
  if(this->level < 0 || this->level > 255)
  {
    qDebug()<<"ERREUR - GameRolePlayMountInformations -"<<"Forbidden value (" << this->level << ") on element of GameRolePlayMountInformations.level.";
  }
}

GameRolePlayMountInformations::GameRolePlayMountInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYMOUNTINFORMATIONS;
}

bool GameRolePlayMountInformations::operator==(const GameRolePlayMountInformations &compared)
{
  if(ownerName == compared.ownerName)
  if(level == compared.level)
  return true;
  
  return false;
}

