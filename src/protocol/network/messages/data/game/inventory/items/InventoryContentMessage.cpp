#include "InventoryContentMessage.h"

void InventoryContentMessage::serialize(Writer *output)
{
  this->serializeAs_InventoryContentMessage(output);
}

void InventoryContentMessage::serializeAs_InventoryContentMessage(Writer *output)
{
  output->writeShort((short)this->objects.size());
  for(uint _i1 = 0; _i1 < this->objects.size(); _i1++)
  {
    qSharedPointerCast<ObjectItem>(this->objects[_i1])->serializeAs_ObjectItem(output);
  }
  if(this->kamas < 0 || this->kamas > 9007199254740992)
  {
    qDebug()<<"ERREUR - InventoryContentMessage -"<<"Forbidden value (" << this->kamas << ") on element kamas.";
  }
  output->writeVarLong((double)this->kamas);
}

void InventoryContentMessage::deserialize(Reader *input)
{
  this->deserializeAs_InventoryContentMessage(input);
}

void InventoryContentMessage::deserializeAs_InventoryContentMessage(Reader *input)
{
  QSharedPointer<ObjectItem> _item1 ;
  uint _objectsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _objectsLen; _i1++)
  {
    _item1 = QSharedPointer<ObjectItem>(new ObjectItem() );
    _item1->deserialize(input);
    this->objects.append(_item1);
  }
  this->_kamasFunc(input);
}

void InventoryContentMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_InventoryContentMessage(tree);
}

void InventoryContentMessage::deserializeAsyncAs_InventoryContentMessage(FuncTree tree)
{
  this->_objectstree = tree.addChild(std::bind(&InventoryContentMessage::_objectstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&InventoryContentMessage::_kamasFunc, this, std::placeholders::_1));
}

void InventoryContentMessage::_objectstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_objectstree.addChild(std::bind(&InventoryContentMessage::_objectsFunc, this, std::placeholders::_1));
  }
}

void InventoryContentMessage::_objectsFunc(Reader *input)
{
  QSharedPointer<ObjectItem> _item = QSharedPointer<ObjectItem>(new ObjectItem() );
  _item->deserialize(input);
  this->objects.append(_item);
}

void InventoryContentMessage::_kamasFunc(Reader *input)
{
  this->kamas = input->readVarUhLong();
  if(this->kamas < 0 || this->kamas > 9007199254740992)
  {
    qDebug()<<"ERREUR - InventoryContentMessage -"<<"Forbidden value (" << this->kamas << ") on element of InventoryContentMessage.kamas.";
  }
}

InventoryContentMessage::InventoryContentMessage()
{
  m_type = MessageEnum::INVENTORYCONTENTMESSAGE;
}

