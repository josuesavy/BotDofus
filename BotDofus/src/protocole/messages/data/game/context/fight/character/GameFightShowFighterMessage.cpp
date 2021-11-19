#include "GameFightShowFighterMessage.h"

void GameFightShowFighterMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightShowFighterMessage(output);
}

void GameFightShowFighterMessage::serializeAs_GameFightShowFighterMessage(Writer *output)
{
  output->writeShort((short)this->informations->getTypes().last());
  this->informations->serialize(output);
}

void GameFightShowFighterMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightShowFighterMessage(input);
}

void GameFightShowFighterMessage::deserializeAs_GameFightShowFighterMessage(Reader *input)
{
  uint _id1 = input->readUShort();
  this->informations = qSharedPointerCast<GameFightFighterInformations>(ClassManagerSingleton::get()->getClass(_id1));
  this->informations->deserialize(input);
}

void GameFightShowFighterMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightShowFighterMessage(tree);
}

void GameFightShowFighterMessage::deserializeAsyncAs_GameFightShowFighterMessage(FuncTree tree)
{
  this->_informationstree = tree.addChild(std::bind(&GameFightShowFighterMessage::_informationstreeFunc, this, std::placeholders::_1));
}

void GameFightShowFighterMessage::_informationstreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->informations = qSharedPointerCast<GameFightFighterInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->informations->deserializeAsync(this->_informationstree);
}

GameFightShowFighterMessage::GameFightShowFighterMessage()
{
  m_type = MessageEnum::GAMEFIGHTSHOWFIGHTERMESSAGE;
}

