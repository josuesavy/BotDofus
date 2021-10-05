#include "ShortcutBarContentMessage.h"

void ShortcutBarContentMessage::serialize(Writer *output)
{
  this->serializeAs_ShortcutBarContentMessage(output);
}

void ShortcutBarContentMessage::serializeAs_ShortcutBarContentMessage(Writer *output)
{
  output->writeByte(this->barType);
  output->writeShort((short)this->shortcuts.size());
  for(uint _i2 = 0; _i2 < this->shortcuts.size(); _i2++)
  {
    output->writeShort((short)qSharedPointerCast<Shortcut>(this->shortcuts[_i2])->getTypes().last());
    qSharedPointerCast<Shortcut>(this->shortcuts[_i2])->serialize(output);
  }
}

void ShortcutBarContentMessage::deserialize(Reader *input)
{
  this->deserializeAs_ShortcutBarContentMessage(input);
}

void ShortcutBarContentMessage::deserializeAs_ShortcutBarContentMessage(Reader *input)
{
  uint _id2 = 0;
  QSharedPointer<Shortcut> _item2 ;
  this->_barTypeFunc(input);
  uint _shortcutsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _shortcutsLen; _i2++)
  {
    _id2 = input->readUShort();
    _item2 = qSharedPointerCast<Shortcut>(ClassManagerSingleton::get()->getClass(_id2));
    _item2->deserialize(input);
    this->shortcuts.append(_item2);
  }
}

void ShortcutBarContentMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShortcutBarContentMessage(tree);
}

void ShortcutBarContentMessage::deserializeAsyncAs_ShortcutBarContentMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ShortcutBarContentMessage::_barTypeFunc, this, std::placeholders::_1));
  this->_shortcutstree = tree.addChild(std::bind(&ShortcutBarContentMessage::_shortcutstreeFunc, this, std::placeholders::_1));
}

void ShortcutBarContentMessage::_barTypeFunc(Reader *input)
{
  this->barType = input->readByte();
  if(this->barType < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarContentMessage -"<<"Forbidden value (" << this->barType << ") on element of ShortcutBarContentMessage.barType.";
  }
}

void ShortcutBarContentMessage::_shortcutstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_shortcutstree.addChild(std::bind(&ShortcutBarContentMessage::_shortcutsFunc, this, std::placeholders::_1));
  }
}

void ShortcutBarContentMessage::_shortcutsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<Shortcut> _item = qSharedPointerCast<Shortcut>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->shortcuts.append(_item);
}

ShortcutBarContentMessage::ShortcutBarContentMessage()
{
  m_type = MessageEnum::SHORTCUTBARCONTENTMESSAGE;
}

