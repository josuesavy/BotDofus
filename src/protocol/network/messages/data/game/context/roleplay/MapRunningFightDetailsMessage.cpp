#include "MapRunningFightDetailsMessage.h"

void MapRunningFightDetailsMessage::serialize(Writer *output)
{
  this->serializeAs_MapRunningFightDetailsMessage(output);
}

void MapRunningFightDetailsMessage::serializeAs_MapRunningFightDetailsMessage(Writer *output)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - MapRunningFightDetailsMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  output->writeShort((short)this->attackers.size());
  for(uint _i2 = 0; _i2 < this->attackers.size(); _i2++)
  {
    output->writeShort((short)qSharedPointerCast<GameFightFighterLightInformations>(this->attackers[_i2])->getTypes().last());
    qSharedPointerCast<GameFightFighterLightInformations>(this->attackers[_i2])->serialize(output);
  }
  output->writeShort((short)this->defenders.size());
  for(uint _i3 = 0; _i3 < this->defenders.size(); _i3++)
  {
    output->writeShort((short)qSharedPointerCast<GameFightFighterLightInformations>(this->defenders[_i3])->getTypes().last());
    qSharedPointerCast<GameFightFighterLightInformations>(this->defenders[_i3])->serialize(output);
  }
}

void MapRunningFightDetailsMessage::deserialize(Reader *input)
{
  this->deserializeAs_MapRunningFightDetailsMessage(input);
}

void MapRunningFightDetailsMessage::deserializeAs_MapRunningFightDetailsMessage(Reader *input)
{
  uint _id2 = 0;
  QSharedPointer<GameFightFighterLightInformations> _item2 ;
  uint _id3 = 0;
  QSharedPointer<GameFightFighterLightInformations> _item3 ;
  this->_fightIdFunc(input);
  uint _attackersLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _attackersLen; _i2++)
  {
    _id2 = uint(input->readUShort());
    _item2 = qSharedPointerCast<GameFightFighterLightInformations>(ClassManagerSingleton::get()->getClass(_id2));
    _item2->deserialize(input);
    this->attackers.append(_item2);
  }
  uint _defendersLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _defendersLen; _i3++)
  {
    _id3 = uint(input->readUShort());
    _item3 = qSharedPointerCast<GameFightFighterLightInformations>(ClassManagerSingleton::get()->getClass(_id3));
    _item3->deserialize(input);
    this->defenders.append(_item3);
  }
}

void MapRunningFightDetailsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapRunningFightDetailsMessage(tree);
}

void MapRunningFightDetailsMessage::deserializeAsyncAs_MapRunningFightDetailsMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MapRunningFightDetailsMessage::_fightIdFunc, this, std::placeholders::_1));
  this->_attackerstree = tree.addChild(std::bind(&MapRunningFightDetailsMessage::_attackerstreeFunc, this, std::placeholders::_1));
  this->_defenderstree = tree.addChild(std::bind(&MapRunningFightDetailsMessage::_defenderstreeFunc, this, std::placeholders::_1));
}

void MapRunningFightDetailsMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - MapRunningFightDetailsMessage -"<<"Forbidden value (" << this->fightId << ") on element of MapRunningFightDetailsMessage.fightId.";
  }
}

void MapRunningFightDetailsMessage::_attackerstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_attackerstree.addChild(std::bind(&MapRunningFightDetailsMessage::_attackersFunc, this, std::placeholders::_1));
  }
}

void MapRunningFightDetailsMessage::_attackersFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<GameFightFighterLightInformations> _item = qSharedPointerCast<GameFightFighterLightInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->attackers.append(_item);
}

void MapRunningFightDetailsMessage::_defenderstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_defenderstree.addChild(std::bind(&MapRunningFightDetailsMessage::_defendersFunc, this, std::placeholders::_1));
  }
}

void MapRunningFightDetailsMessage::_defendersFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<GameFightFighterLightInformations> _item = qSharedPointerCast<GameFightFighterLightInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->defenders.append(_item);
}

MapRunningFightDetailsMessage::MapRunningFightDetailsMessage()
{
  m_type = MessageEnum::MAPRUNNINGFIGHTDETAILSMESSAGE;
}

