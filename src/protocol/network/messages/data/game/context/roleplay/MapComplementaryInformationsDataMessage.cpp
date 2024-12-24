#include "MapComplementaryInformationsDataMessage.h"

void MapComplementaryInformationsDataMessage::serialize(Writer *output)
{
  this->serializeAs_MapComplementaryInformationsDataMessage(output);
}

void MapComplementaryInformationsDataMessage::serializeAs_MapComplementaryInformationsDataMessage(Writer *output)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsDataMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsDataMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  output->writeShort((short)this->houses.size());
  for(uint _i3 = 0; _i3 < this->houses.size(); _i3++)
  {
    output->writeShort((short)qSharedPointerCast<HouseInformations>(this->houses[_i3])->getTypes().last());
    qSharedPointerCast<HouseInformations>(this->houses[_i3])->serialize(output);
  }
  output->writeShort((short)this->actors.size());
  for(uint _i4 = 0; _i4 < this->actors.size(); _i4++)
  {
    output->writeShort((short)qSharedPointerCast<GameRolePlayActorInformations>(this->actors[_i4])->getTypes().last());
    qSharedPointerCast<GameRolePlayActorInformations>(this->actors[_i4])->serialize(output);
  }
  output->writeShort((short)this->interactiveElements.size());
  for(uint _i5 = 0; _i5 < this->interactiveElements.size(); _i5++)
  {
    output->writeShort((short)qSharedPointerCast<InteractiveElement>(this->interactiveElements[_i5])->getTypes().last());
    qSharedPointerCast<InteractiveElement>(this->interactiveElements[_i5])->serialize(output);
  }
  output->writeShort((short)this->statedElements.size());
  for(uint _i6 = 0; _i6 < this->statedElements.size(); _i6++)
  {
    (this->statedElements[_i6]).serializeAs_StatedElement(output);
  }
  output->writeShort((short)this->obstacles.size());
  for(uint _i7 = 0; _i7 < this->obstacles.size(); _i7++)
  {
    (this->obstacles[_i7]).serializeAs_MapObstacle(output);
  }
  output->writeShort((short)this->fights.size());
  for(uint _i8 = 0; _i8 < this->fights.size(); _i8++)
  {
    qSharedPointerCast<FightCommonInformations>(this->fights[_i8])->serializeAs_FightCommonInformations(output);
  }
  output->writeBool(this->hasAggressiveMonsters);
  this->fightStartPositions.serializeAs_FightStartingPositions(output);
}

void MapComplementaryInformationsDataMessage::deserialize(Reader *input)
{
  this->deserializeAs_MapComplementaryInformationsDataMessage(input);
}

void MapComplementaryInformationsDataMessage::deserializeAs_MapComplementaryInformationsDataMessage(Reader *input)
{
  uint _id3 = 0;
  QSharedPointer<HouseInformations> _item3 ;
  uint _id4 = 0;
  QSharedPointer<GameRolePlayActorInformations> _item4 ;
  uint _id5 = 0;
  QSharedPointer<InteractiveElement> _item5 ;
  StatedElement _item6 ;
  MapObstacle _item7 ;
  QSharedPointer<FightCommonInformations> _item8 ;
  this->_subAreaIdFunc(input);
  this->_mapIdFunc(input);
  uint _housesLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _housesLen; _i3++)
  {
    _id3 = uint(input->readUShort());
    _item3 = qSharedPointerCast<HouseInformations>(ClassManagerSingleton::get()->getClass(_id3));
    _item3->deserialize(input);
    this->houses.append(_item3);
  }
  uint _actorsLen = uint(input->readUShort());
  for(uint _i4 = 0; _i4 < _actorsLen; _i4++)
  {
    _id4 = uint(input->readUShort());
    _item4 = qSharedPointerCast<GameRolePlayActorInformations>(ClassManagerSingleton::get()->getClass(_id4));
    _item4->deserialize(input);
    this->actors.append(_item4);
  }
  uint _interactiveElementsLen = uint(input->readUShort());
  for(uint _i5 = 0; _i5 < _interactiveElementsLen; _i5++)
  {
    _id5 = uint(input->readUShort());
    _item5 = qSharedPointerCast<InteractiveElement>(ClassManagerSingleton::get()->getClass(_id5));
    _item5->deserialize(input);
    this->interactiveElements.append(_item5);
  }
  uint _statedElementsLen = uint(input->readUShort());
  for(uint _i6 = 0; _i6 < _statedElementsLen; _i6++)
  {
    _item6 = StatedElement();
    _item6.deserialize(input);
    this->statedElements.append(_item6);
  }
  uint _obstaclesLen = uint(input->readUShort());
  for(uint _i7 = 0; _i7 < _obstaclesLen; _i7++)
  {
    _item7 = MapObstacle();
    _item7.deserialize(input);
    this->obstacles.append(_item7);
  }
  uint _fightsLen = uint(input->readUShort());
  for(uint _i8 = 0; _i8 < _fightsLen; _i8++)
  {
    _item8 = QSharedPointer<FightCommonInformations>(new FightCommonInformations() );
    _item8->deserialize(input);
    this->fights.append(_item8);
  }
  this->_hasAggressiveMonstersFunc(input);
  this->fightStartPositions = FightStartingPositions();
  this->fightStartPositions.deserialize(input);
}

void MapComplementaryInformationsDataMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapComplementaryInformationsDataMessage(tree);
}

void MapComplementaryInformationsDataMessage::deserializeAsyncAs_MapComplementaryInformationsDataMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MapComplementaryInformationsDataMessage::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MapComplementaryInformationsDataMessage::_mapIdFunc, this, std::placeholders::_1));
  this->_housestree = tree.addChild(std::bind(&MapComplementaryInformationsDataMessage::_housestreeFunc, this, std::placeholders::_1));
  this->_actorstree = tree.addChild(std::bind(&MapComplementaryInformationsDataMessage::_actorstreeFunc, this, std::placeholders::_1));
  this->_interactiveElementstree = tree.addChild(std::bind(&MapComplementaryInformationsDataMessage::_interactiveElementstreeFunc, this, std::placeholders::_1));
  this->_statedElementstree = tree.addChild(std::bind(&MapComplementaryInformationsDataMessage::_statedElementstreeFunc, this, std::placeholders::_1));
  this->_obstaclestree = tree.addChild(std::bind(&MapComplementaryInformationsDataMessage::_obstaclestreeFunc, this, std::placeholders::_1));
  this->_fightstree = tree.addChild(std::bind(&MapComplementaryInformationsDataMessage::_fightstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MapComplementaryInformationsDataMessage::_hasAggressiveMonstersFunc, this, std::placeholders::_1));
  this->_fightStartPositionstree = tree.addChild(std::bind(&MapComplementaryInformationsDataMessage::_fightStartPositionstreeFunc, this, std::placeholders::_1));
}

void MapComplementaryInformationsDataMessage::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsDataMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of MapComplementaryInformationsDataMessage.subAreaId.";
  }
}

void MapComplementaryInformationsDataMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsDataMessage -"<<"Forbidden value (" << this->mapId << ") on element of MapComplementaryInformationsDataMessage.mapId.";
  }
}

void MapComplementaryInformationsDataMessage::_housestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_housestree.addChild(std::bind(&MapComplementaryInformationsDataMessage::_housesFunc, this, std::placeholders::_1));
  }
}

void MapComplementaryInformationsDataMessage::_housesFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<HouseInformations> _item = qSharedPointerCast<HouseInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->houses.append(_item);
}

void MapComplementaryInformationsDataMessage::_actorstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_actorstree.addChild(std::bind(&MapComplementaryInformationsDataMessage::_actorsFunc, this, std::placeholders::_1));
  }
}

void MapComplementaryInformationsDataMessage::_actorsFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<GameRolePlayActorInformations> _item = qSharedPointerCast<GameRolePlayActorInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->actors.append(_item);
}

void MapComplementaryInformationsDataMessage::_interactiveElementstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_interactiveElementstree.addChild(std::bind(&MapComplementaryInformationsDataMessage::_interactiveElementsFunc, this, std::placeholders::_1));
  }
}

void MapComplementaryInformationsDataMessage::_interactiveElementsFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<InteractiveElement> _item = qSharedPointerCast<InteractiveElement>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->interactiveElements.append(_item);
}

void MapComplementaryInformationsDataMessage::_statedElementstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_statedElementstree.addChild(std::bind(&MapComplementaryInformationsDataMessage::_statedElementsFunc, this, std::placeholders::_1));
  }
}

void MapComplementaryInformationsDataMessage::_statedElementsFunc(Reader *input)
{
  StatedElement _item = StatedElement();
  _item.deserialize(input);
  this->statedElements.append(_item);
}

void MapComplementaryInformationsDataMessage::_obstaclestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_obstaclestree.addChild(std::bind(&MapComplementaryInformationsDataMessage::_obstaclesFunc, this, std::placeholders::_1));
  }
}

void MapComplementaryInformationsDataMessage::_obstaclesFunc(Reader *input)
{
  MapObstacle _item = MapObstacle();
  _item.deserialize(input);
  this->obstacles.append(_item);
}

void MapComplementaryInformationsDataMessage::_fightstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_fightstree.addChild(std::bind(&MapComplementaryInformationsDataMessage::_fightsFunc, this, std::placeholders::_1));
  }
}

void MapComplementaryInformationsDataMessage::_fightsFunc(Reader *input)
{
  QSharedPointer<FightCommonInformations> _item = QSharedPointer<FightCommonInformations>(new FightCommonInformations() );
  _item->deserialize(input);
  this->fights.append(_item);
}

void MapComplementaryInformationsDataMessage::_hasAggressiveMonstersFunc(Reader *input)
{
  this->hasAggressiveMonsters = input->readBool();
}

void MapComplementaryInformationsDataMessage::_fightStartPositionstreeFunc(Reader *input)
{
  this->fightStartPositions = FightStartingPositions();
  this->fightStartPositions.deserializeAsync(this->_fightStartPositionstree);
}

MapComplementaryInformationsDataMessage::MapComplementaryInformationsDataMessage()
{
  m_type = MessageEnum::MAPCOMPLEMENTARYINFORMATIONSDATAMESSAGE;
}

