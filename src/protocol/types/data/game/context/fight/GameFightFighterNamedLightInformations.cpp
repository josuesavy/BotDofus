#include "GameFightFighterNamedLightInformations.h"

void GameFightFighterNamedLightInformations::serialize(Writer *output)
{
  this->serializeAs_GameFightFighterNamedLightInformations(output);
}

void GameFightFighterNamedLightInformations::serializeAs_GameFightFighterNamedLightInformations(Writer *output)
{
  GameFightFighterLightInformations::serializeAs_GameFightFighterLightInformations(output);
  output->writeUTF(this->name);
}

void GameFightFighterNamedLightInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameFightFighterNamedLightInformations(input);
}

void GameFightFighterNamedLightInformations::deserializeAs_GameFightFighterNamedLightInformations(Reader *input)
{
  GameFightFighterLightInformations::deserialize(input);
  this->_nameFunc(input);
}

void GameFightFighterNamedLightInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightFighterNamedLightInformations(tree);
}

void GameFightFighterNamedLightInformations::deserializeAsyncAs_GameFightFighterNamedLightInformations(FuncTree tree)
{
  GameFightFighterLightInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GameFightFighterNamedLightInformations::_nameFunc, this, std::placeholders::_1));
}

void GameFightFighterNamedLightInformations::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

GameFightFighterNamedLightInformations::GameFightFighterNamedLightInformations()
{
  m_types<<ClassEnum::GAMEFIGHTFIGHTERNAMEDLIGHTINFORMATIONS;
}

bool GameFightFighterNamedLightInformations::operator==(const GameFightFighterNamedLightInformations &compared)
{
  if(name == compared.name)
  return true;
  
  return false;
}

