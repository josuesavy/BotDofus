#include "ExchangeGuildTaxCollectorGetMessage.h"

void ExchangeGuildTaxCollectorGetMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeGuildTaxCollectorGetMessage(output);
}

void ExchangeGuildTaxCollectorGetMessage::serializeAs_ExchangeGuildTaxCollectorGetMessage(Writer *output)
{
  output->writeUTF(this->collectorName);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  output->writeUTF(this->userName);
  if(this->callerId < 0 || this->callerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->callerId << ") on element callerId.";
  }
  output->writeVarLong((double)this->callerId);
  output->writeUTF(this->callerName);
  if(this->experience < -9.007199254740992E15 || this->experience > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->experience << ") on element experience.";
  }
  output->writeDouble(this->experience);
  if(this->pods < 0)
  {
    qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->pods << ") on element pods.";
  }
  output->writeVarShort((int)this->pods);
  output->writeShort((short)this->objectsInfos.size());
  for(uint _i11 = 0; _i11 < this->objectsInfos.size(); _i11++)
  {
    (this->objectsInfos[_i11]).serializeAs_ObjectItemGenericQuantity(output);
  }
}

void ExchangeGuildTaxCollectorGetMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeGuildTaxCollectorGetMessage(input);
}

void ExchangeGuildTaxCollectorGetMessage::deserializeAs_ExchangeGuildTaxCollectorGetMessage(Reader *input)
{
  ObjectItemGenericQuantity _item11 ;
  this->_collectorNameFunc(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_mapIdFunc(input);
  this->_subAreaIdFunc(input);
  this->_userNameFunc(input);
  this->_callerIdFunc(input);
  this->_callerNameFunc(input);
  this->_experienceFunc(input);
  this->_podsFunc(input);
  uint _objectsInfosLen = input->readUShort();
  for(uint _i11 = 0; _i11 < _objectsInfosLen; _i11++)
  {
    _item11 = ObjectItemGenericQuantity();
    _item11.deserialize(input);
    this->objectsInfos.append(_item11);
  }
}

void ExchangeGuildTaxCollectorGetMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeGuildTaxCollectorGetMessage(tree);
}

void ExchangeGuildTaxCollectorGetMessage::deserializeAsyncAs_ExchangeGuildTaxCollectorGetMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeGuildTaxCollectorGetMessage::_collectorNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeGuildTaxCollectorGetMessage::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeGuildTaxCollectorGetMessage::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeGuildTaxCollectorGetMessage::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeGuildTaxCollectorGetMessage::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeGuildTaxCollectorGetMessage::_userNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeGuildTaxCollectorGetMessage::_callerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeGuildTaxCollectorGetMessage::_callerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeGuildTaxCollectorGetMessage::_experienceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeGuildTaxCollectorGetMessage::_podsFunc, this, std::placeholders::_1));
  this->_objectsInfostree = tree.addChild(std::bind(&ExchangeGuildTaxCollectorGetMessage::_objectsInfostreeFunc, this, std::placeholders::_1));
}

void ExchangeGuildTaxCollectorGetMessage::_collectorNameFunc(Reader *input)
{
  this->collectorName = input->readUTF();
}

void ExchangeGuildTaxCollectorGetMessage::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->worldX << ") on element of ExchangeGuildTaxCollectorGetMessage.worldX.";
  }
}

void ExchangeGuildTaxCollectorGetMessage::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->worldY << ") on element of ExchangeGuildTaxCollectorGetMessage.worldY.";
  }
}

void ExchangeGuildTaxCollectorGetMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->mapId << ") on element of ExchangeGuildTaxCollectorGetMessage.mapId.";
  }
}

void ExchangeGuildTaxCollectorGetMessage::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of ExchangeGuildTaxCollectorGetMessage.subAreaId.";
  }
}

void ExchangeGuildTaxCollectorGetMessage::_userNameFunc(Reader *input)
{
  this->userName = input->readUTF();
}

void ExchangeGuildTaxCollectorGetMessage::_callerIdFunc(Reader *input)
{
  this->callerId = input->readVarUhLong();
  if(this->callerId < 0 || this->callerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->callerId << ") on element of ExchangeGuildTaxCollectorGetMessage.callerId.";
  }
}

void ExchangeGuildTaxCollectorGetMessage::_callerNameFunc(Reader *input)
{
  this->callerName = input->readUTF();
}

void ExchangeGuildTaxCollectorGetMessage::_experienceFunc(Reader *input)
{
  this->experience = input->readDouble();
  if(this->experience < -9.007199254740992E15 || this->experience > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->experience << ") on element of ExchangeGuildTaxCollectorGetMessage.experience.";
  }
}

void ExchangeGuildTaxCollectorGetMessage::_podsFunc(Reader *input)
{
  this->pods = input->readVarUhShort();
  if(this->pods < 0)
  {
    qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->pods << ") on element of ExchangeGuildTaxCollectorGetMessage.pods.";
  }
}

void ExchangeGuildTaxCollectorGetMessage::_objectsInfostreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_objectsInfostree.addChild(std::bind(&ExchangeGuildTaxCollectorGetMessage::_objectsInfosFunc, this, std::placeholders::_1));
  }
}

void ExchangeGuildTaxCollectorGetMessage::_objectsInfosFunc(Reader *input)
{
  ObjectItemGenericQuantity _item = ObjectItemGenericQuantity();
  _item.deserialize(input);
  this->objectsInfos.append(_item);
}

ExchangeGuildTaxCollectorGetMessage::ExchangeGuildTaxCollectorGetMessage()
{
  m_type = MessageEnum::EXCHANGEGUILDTAXCOLLECTORGETMESSAGE;
}

