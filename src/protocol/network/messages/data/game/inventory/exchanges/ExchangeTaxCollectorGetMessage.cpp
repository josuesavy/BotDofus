#include "ExchangeTaxCollectorGetMessage.h"

void ExchangeTaxCollectorGetMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeTaxCollectorGetMessage(output);
}

void ExchangeTaxCollectorGetMessage::serializeAs_ExchangeTaxCollectorGetMessage(Writer *output)
{
  output->writeUTF(this->collectorName);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - ExchangeTaxCollectorGetMessage -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - ExchangeTaxCollectorGetMessage -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeTaxCollectorGetMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - ExchangeTaxCollectorGetMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  output->writeUTF(this->userName);
  if(this->callerId < 0 || this->callerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeTaxCollectorGetMessage -"<<"Forbidden value (" << this->callerId << ") on element callerId.";
  }
  output->writeVarLong((double)this->callerId);
  output->writeUTF(this->callerName);
  if(this->pods < 0)
  {
    qDebug()<<"ERREUR - ExchangeTaxCollectorGetMessage -"<<"Forbidden value (" << this->pods << ") on element pods.";
  }
  output->writeVarShort((int)this->pods);
  output->writeShort((short)this->objectsInfos.size());
  for(uint _i10 = 0; _i10 < this->objectsInfos.size(); _i10++)
  {
    (this->objectsInfos[_i10]).serializeAs_ObjectItemGenericQuantity(output);
  }
  this->look->serializeAs_EntityLook(output);
}

void ExchangeTaxCollectorGetMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeTaxCollectorGetMessage(input);
}

void ExchangeTaxCollectorGetMessage::deserializeAs_ExchangeTaxCollectorGetMessage(Reader *input)
{
  ObjectItemGenericQuantity _item10 ;
  this->_collectorNameFunc(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_mapIdFunc(input);
  this->_subAreaIdFunc(input);
  this->_userNameFunc(input);
  this->_callerIdFunc(input);
  this->_callerNameFunc(input);
  this->_podsFunc(input);
  uint _objectsInfosLen = uint(input->readUShort());
  for(uint _i10 = 0; _i10 < _objectsInfosLen; _i10++)
  {
    _item10 = ObjectItemGenericQuantity();
    _item10.deserialize(input);
    this->objectsInfos.append(_item10);
  }
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserialize(input);
}

void ExchangeTaxCollectorGetMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeTaxCollectorGetMessage(tree);
}

void ExchangeTaxCollectorGetMessage::deserializeAsyncAs_ExchangeTaxCollectorGetMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeTaxCollectorGetMessage::_collectorNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeTaxCollectorGetMessage::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeTaxCollectorGetMessage::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeTaxCollectorGetMessage::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeTaxCollectorGetMessage::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeTaxCollectorGetMessage::_userNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeTaxCollectorGetMessage::_callerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeTaxCollectorGetMessage::_callerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeTaxCollectorGetMessage::_podsFunc, this, std::placeholders::_1));
  this->_objectsInfostree = tree.addChild(std::bind(&ExchangeTaxCollectorGetMessage::_objectsInfostreeFunc, this, std::placeholders::_1));
  this->_looktree = tree.addChild(std::bind(&ExchangeTaxCollectorGetMessage::_looktreeFunc, this, std::placeholders::_1));
}

void ExchangeTaxCollectorGetMessage::_collectorNameFunc(Reader *input)
{
  this->collectorName = input->readUTF();
}

void ExchangeTaxCollectorGetMessage::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - ExchangeTaxCollectorGetMessage -"<<"Forbidden value (" << this->worldX << ") on element of ExchangeTaxCollectorGetMessage.worldX.";
  }
}

void ExchangeTaxCollectorGetMessage::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - ExchangeTaxCollectorGetMessage -"<<"Forbidden value (" << this->worldY << ") on element of ExchangeTaxCollectorGetMessage.worldY.";
  }
}

void ExchangeTaxCollectorGetMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeTaxCollectorGetMessage -"<<"Forbidden value (" << this->mapId << ") on element of ExchangeTaxCollectorGetMessage.mapId.";
  }
}

void ExchangeTaxCollectorGetMessage::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - ExchangeTaxCollectorGetMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of ExchangeTaxCollectorGetMessage.subAreaId.";
  }
}

void ExchangeTaxCollectorGetMessage::_userNameFunc(Reader *input)
{
  this->userName = input->readUTF();
}

void ExchangeTaxCollectorGetMessage::_callerIdFunc(Reader *input)
{
  this->callerId = input->readVarUhLong();
  if(this->callerId < 0 || this->callerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeTaxCollectorGetMessage -"<<"Forbidden value (" << this->callerId << ") on element of ExchangeTaxCollectorGetMessage.callerId.";
  }
}

void ExchangeTaxCollectorGetMessage::_callerNameFunc(Reader *input)
{
  this->callerName = input->readUTF();
}

void ExchangeTaxCollectorGetMessage::_podsFunc(Reader *input)
{
  this->pods = input->readVarUhShort();
  if(this->pods < 0)
  {
    qDebug()<<"ERREUR - ExchangeTaxCollectorGetMessage -"<<"Forbidden value (" << this->pods << ") on element of ExchangeTaxCollectorGetMessage.pods.";
  }
}

void ExchangeTaxCollectorGetMessage::_objectsInfostreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_objectsInfostree.addChild(std::bind(&ExchangeTaxCollectorGetMessage::_objectsInfosFunc, this, std::placeholders::_1));
  }
}

void ExchangeTaxCollectorGetMessage::_objectsInfosFunc(Reader *input)
{
  ObjectItemGenericQuantity _item = ObjectItemGenericQuantity();
  _item.deserialize(input);
  this->objectsInfos.append(_item);
}

void ExchangeTaxCollectorGetMessage::_looktreeFunc(Reader *input)
{
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserializeAsync(this->_looktree);
}

ExchangeTaxCollectorGetMessage::ExchangeTaxCollectorGetMessage()
{
  m_type = MessageEnum::EXCHANGETAXCOLLECTORGETMESSAGE;
}

