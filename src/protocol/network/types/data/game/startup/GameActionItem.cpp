#include "GameActionItem.h"

void GameActionItem::serialize(Writer *output)
{
  this->serializeAs_GameActionItem(output);
}

void GameActionItem::serializeAs_GameActionItem(Writer *output)
{
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - GameActionItem -"<<"Forbidden value (" << this->uid << ") on element uid.";
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
}

void GameActionItem::deserialize(Reader *input)
{
  this->deserializeAs_GameActionItem(input);
}

void GameActionItem::deserializeAs_GameActionItem(Reader *input)
{
  QSharedPointer<ObjectItemInformationWithQuantity> _item6 ;
  this->_uidFunc(input);
  this->_titleFunc(input);
  this->_textFunc(input);
  this->_descUrlFunc(input);
  this->_pictureUrlFunc(input);
  uint _itemsLen = uint(input->readUShort());
  for(uint _i6 = 0; _i6 < _itemsLen; _i6++)
  {
    _item6 = QSharedPointer<ObjectItemInformationWithQuantity>(new ObjectItemInformationWithQuantity() );
    _item6->deserialize(input);
    this->items.append(_item6);
  }
}

void GameActionItem::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionItem(tree);
}

void GameActionItem::deserializeAsyncAs_GameActionItem(FuncTree tree)
{
  tree.addChild(std::bind(&GameActionItem::_uidFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionItem::_titleFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionItem::_textFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionItem::_descUrlFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionItem::_pictureUrlFunc, this, std::placeholders::_1));
  this->_itemstree = tree.addChild(std::bind(&GameActionItem::_itemstreeFunc, this, std::placeholders::_1));
}

void GameActionItem::_uidFunc(Reader *input)
{
  this->uid = input->readInt();
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - GameActionItem -"<<"Forbidden value (" << this->uid << ") on element of GameActionItem.uid.";
  }
}

void GameActionItem::_titleFunc(Reader *input)
{
  this->title = input->readUTF();
}

void GameActionItem::_textFunc(Reader *input)
{
  this->text = input->readUTF();
}

void GameActionItem::_descUrlFunc(Reader *input)
{
  this->descUrl = input->readUTF();
}

void GameActionItem::_pictureUrlFunc(Reader *input)
{
  this->pictureUrl = input->readUTF();
}

void GameActionItem::_itemstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_itemstree.addChild(std::bind(&GameActionItem::_itemsFunc, this, std::placeholders::_1));
  }
}

void GameActionItem::_itemsFunc(Reader *input)
{
  QSharedPointer<ObjectItemInformationWithQuantity> _item = QSharedPointer<ObjectItemInformationWithQuantity>(new ObjectItemInformationWithQuantity() );
  _item->deserialize(input);
  this->items.append(_item);
}

GameActionItem::GameActionItem()
{
  m_types<<ClassEnum::GAMEACTIONITEM;
}

bool GameActionItem::operator==(const GameActionItem &compared)
{
  if(uid == compared.uid)
  if(title == compared.title)
  if(text == compared.text)
  if(descUrl == compared.descUrl)
  if(pictureUrl == compared.pictureUrl)
  if(items == compared.items)
  if(_itemstree == compared._itemstree)
  return true;
  
  return false;
}

