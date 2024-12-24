#include "GameFightSynchronizeMessage.h"

void GameFightSynchronizeMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightSynchronizeMessage(output);
}

void GameFightSynchronizeMessage::serializeAs_GameFightSynchronizeMessage(Writer *output)
{
  output->writeShort((short)this->fighters.size());
  for(uint _i1 = 0; _i1 < this->fighters.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<GameFightFighterInformations>(this->fighters[_i1])->getTypes().last());
    qSharedPointerCast<GameFightFighterInformations>(this->fighters[_i1])->serialize(output);
  }
}

void GameFightSynchronizeMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightSynchronizeMessage(input);
}

void GameFightSynchronizeMessage::deserializeAs_GameFightSynchronizeMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<GameFightFighterInformations> _item1 ;
  uint _fightersLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _fightersLen; _i1++)
  {
    _id1 = uint(input->readUShort());
    _item1 = qSharedPointerCast<GameFightFighterInformations>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->fighters.append(_item1);
  }
}

void GameFightSynchronizeMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightSynchronizeMessage(tree);
}

void GameFightSynchronizeMessage::deserializeAsyncAs_GameFightSynchronizeMessage(FuncTree tree)
{
  this->_fighterstree = tree.addChild(std::bind(&GameFightSynchronizeMessage::_fighterstreeFunc, this, std::placeholders::_1));
}

void GameFightSynchronizeMessage::_fighterstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_fighterstree.addChild(std::bind(&GameFightSynchronizeMessage::_fightersFunc, this, std::placeholders::_1));
  }
}

void GameFightSynchronizeMessage::_fightersFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<GameFightFighterInformations> _item = qSharedPointerCast<GameFightFighterInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->fighters.append(_item);
}

GameFightSynchronizeMessage::GameFightSynchronizeMessage()
{
  m_type = MessageEnum::GAMEFIGHTSYNCHRONIZEMESSAGE;
}

