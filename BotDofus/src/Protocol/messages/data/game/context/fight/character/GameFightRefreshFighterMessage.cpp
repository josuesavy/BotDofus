#include "GameFightRefreshFighterMessage.h"

void GameFightRefreshFighterMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightRefreshFighterMessage(output);
}

void GameFightRefreshFighterMessage::serializeAs_GameFightRefreshFighterMessage(Writer *output)
{
  output->writeShort((short)this->informations->getTypes().last());
  this->informations->serialize(output);
}

void GameFightRefreshFighterMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightRefreshFighterMessage(input);
}

void GameFightRefreshFighterMessage::deserializeAs_GameFightRefreshFighterMessage(Reader *input)
{
  uint _id1 = input->readUShort();
  this->informations = qSharedPointerCast<GameContextActorInformations>(ClassManagerSingleton::get()->getClass(_id1));
  this->informations->deserialize(input);
}

void GameFightRefreshFighterMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightRefreshFighterMessage(tree);
}

void GameFightRefreshFighterMessage::deserializeAsyncAs_GameFightRefreshFighterMessage(FuncTree tree)
{
  this->_informationstree = tree.addChild(std::bind(&GameFightRefreshFighterMessage::_informationstreeFunc, this, std::placeholders::_1));
}

void GameFightRefreshFighterMessage::_informationstreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->informations = qSharedPointerCast<GameContextActorInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->informations->deserializeAsync(this->_informationstree);
}

GameFightRefreshFighterMessage::GameFightRefreshFighterMessage()
{
  m_type = MessageEnum::GAMEFIGHTREFRESHFIGHTERMESSAGE;
}

