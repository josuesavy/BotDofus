#include "SetUpdateMessage.h"

void SetUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_SetUpdateMessage(output);
}

void SetUpdateMessage::serializeAs_SetUpdateMessage(Writer *output)
{
  if(this->setId < 0)
  {
    qDebug()<<"ERREUR - SetUpdateMessage -"<<"Forbidden value (" << this->setId << ") on element setId.";
  }
  output->writeVarShort((int)this->setId);
  output->writeShort((short)this->setObjects.size());
  for(uint _i2 = 0; _i2 < this->setObjects.size(); _i2++)
  {
    if(this->setObjects[_i2] < 0)
    {
      qDebug()<<"ERREUR - SetUpdateMessage -"<<"Forbidden value (" << this->setObjects[_i2] << ") on element 2 (starting at 1) of setObjects.";
    }
    output->writeVarInt((int)this->setObjects[_i2]);
  }
  output->writeShort((short)this->setEffects.size());
  for(uint _i3 = 0; _i3 < this->setEffects.size(); _i3++)
  {
    output->writeShort((short)qSharedPointerCast<ObjectEffect>(this->setEffects[_i3])->getTypes().last());
    qSharedPointerCast<ObjectEffect>(this->setEffects[_i3])->serialize(output);
  }
}

void SetUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_SetUpdateMessage(input);
}

void SetUpdateMessage::deserializeAs_SetUpdateMessage(Reader *input)
{
  uint _val2 = 0;
  uint _id3 = 0;
  QSharedPointer<ObjectEffect> _item3 ;
  this->_setIdFunc(input);
  uint _setObjectsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _setObjectsLen; _i2++)
  {
    _val2 = input->readVarUhInt();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - SetUpdateMessage -"<<"Forbidden value (" << _val2 << ") on elements of setObjects.";
    }
    this->setObjects.append(_val2);
  }
  uint _setEffectsLen = input->readUShort();
  for(uint _i3 = 0; _i3 < _setEffectsLen; _i3++)
  {
    _id3 = input->readUShort();
    _item3 = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_id3));
    _item3->deserialize(input);
    this->setEffects.append(_item3);
  }
}

void SetUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SetUpdateMessage(tree);
}

void SetUpdateMessage::deserializeAsyncAs_SetUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SetUpdateMessage::_setIdFunc, this, std::placeholders::_1));
  this->_setObjectstree = tree.addChild(std::bind(&SetUpdateMessage::_setObjectstreeFunc, this, std::placeholders::_1));
  this->_setEffectstree = tree.addChild(std::bind(&SetUpdateMessage::_setEffectstreeFunc, this, std::placeholders::_1));
}

void SetUpdateMessage::_setIdFunc(Reader *input)
{
  this->setId = input->readVarUhShort();
  if(this->setId < 0)
  {
    qDebug()<<"ERREUR - SetUpdateMessage -"<<"Forbidden value (" << this->setId << ") on element of SetUpdateMessage.setId.";
  }
}

void SetUpdateMessage::_setObjectstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_setObjectstree.addChild(std::bind(&SetUpdateMessage::_setObjectsFunc, this, std::placeholders::_1));
  }
}

void SetUpdateMessage::_setObjectsFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - SetUpdateMessage -"<<"Forbidden value (" << _val << ") on elements of setObjects.";
  }
  this->setObjects.append(_val);
}

void SetUpdateMessage::_setEffectstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_setEffectstree.addChild(std::bind(&SetUpdateMessage::_setEffectsFunc, this, std::placeholders::_1));
  }
}

void SetUpdateMessage::_setEffectsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<ObjectEffect> _item = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->setEffects.append(_item);
}

SetUpdateMessage::SetUpdateMessage()
{
  m_type = MessageEnum::SETUPDATEMESSAGE;
}

