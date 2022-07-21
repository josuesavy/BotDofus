#include "StartupActionAddObject.h"

void StartupActionAddObject::serialize(Writer *output)
{
  this->serializeAs_StartupActionAddObject(output);
}

void StartupActionAddObject::serializeAs_StartupActionAddObject(Writer *output)
{
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - StartupActionAddObject -"<<"Forbidden value (" << this->uid << ") on element uid.";
  }
  output->writeInt((int)this->uid);
  output->writeUTF(this->title);
  output->writeUTF(this->text);
  output->writeUTF(this->descUrl);
  output->writeUTF(this->pictureUrl);
  output->writeShort((short)this->items.size());
  for(uint _i6 = 0; _i6 < this->items.size(); _i6++)
  {
    qSharedPointerCast<ObjectItemInformationWithQuantity>(this->items[_i6])->serializeAs_ObjectItemInformationWithQuantity(output);
  }
  output->writeVarInt((int)this->type);
}

void StartupActionAddObject::deserialize(Reader *input)
{
  this->deserializeAs_StartupActionAddObject(input);
}

void StartupActionAddObject::deserializeAs_StartupActionAddObject(Reader *input)
{
  QSharedPointer<ObjectItemInformationWithQuantity> _item6 ;
  this->_uidFunc(input);
  this->_titleFunc(input);
  this->_textFunc(input);
  this->_descUrlFunc(input);
  this->_pictureUrlFunc(input);
  uint _itemsLen = input->readUShort();
  for(uint _i6 = 0; _i6 < _itemsLen; _i6++)
  {
    _item6 = QSharedPointer<ObjectItemInformationWithQuantity>(new ObjectItemInformationWithQuantity() );
    _item6->deserialize(input);
    this->items.append(_item6);
  }
  this->_typeFunc(input);
}

void StartupActionAddObject::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StartupActionAddObject(tree);
}

void StartupActionAddObject::deserializeAsyncAs_StartupActionAddObject(FuncTree tree)
{
  tree.addChild(std::bind(&StartupActionAddObject::_uidFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&StartupActionAddObject::_titleFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&StartupActionAddObject::_textFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&StartupActionAddObject::_descUrlFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&StartupActionAddObject::_pictureUrlFunc, this, std::placeholders::_1));
  this->_itemstree = tree.addChild(std::bind(&StartupActionAddObject::_itemstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&StartupActionAddObject::_typeFunc, this, std::placeholders::_1));
}

void StartupActionAddObject::_uidFunc(Reader *input)
{
  this->uid = input->readInt();
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - StartupActionAddObject -"<<"Forbidden value (" << this->uid << ") on element of StartupActionAddObject.uid.";
  }
}

void StartupActionAddObject::_titleFunc(Reader *input)
{
  this->title = input->readUTF();
}

void StartupActionAddObject::_textFunc(Reader *input)
{
  this->text = input->readUTF();
}

void StartupActionAddObject::_descUrlFunc(Reader *input)
{
  this->descUrl = input->readUTF();
}

void StartupActionAddObject::_pictureUrlFunc(Reader *input)
{
  this->pictureUrl = input->readUTF();
}

void StartupActionAddObject::_itemstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_itemstree.addChild(std::bind(&StartupActionAddObject::_itemsFunc, this, std::placeholders::_1));
  }
}

void StartupActionAddObject::_itemsFunc(Reader *input)
{
  QSharedPointer<ObjectItemInformationWithQuantity> _item = QSharedPointer<ObjectItemInformationWithQuantity>(new ObjectItemInformationWithQuantity() );
  _item->deserialize(input);
  this->items.append(_item);
}

void StartupActionAddObject::_typeFunc(Reader *input)
{
  this->type = input->readVarUhInt();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - StartupActionAddObject -"<<"Forbidden value (" << this->type << ") on element of StartupActionAddObject.type.";
  }
}

StartupActionAddObject::StartupActionAddObject()
{
  m_types<<ClassEnum::STARTUPACTIONADDOBJECT;
}

bool StartupActionAddObject::operator==(const StartupActionAddObject &compared)
{
  if(uid == compared.uid)
  if(title == compared.title)
  if(text == compared.text)
  if(descUrl == compared.descUrl)
  if(pictureUrl == compared.pictureUrl)
  if(items == compared.items)
  if(type == compared.type)
  if(_itemstree == compared._itemstree)
  return true;
  
  return false;
}

