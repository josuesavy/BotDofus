#include "ShortcutBarRefreshMessage.h"

void ShortcutBarRefreshMessage::serialize(Writer *output)
{
  this->serializeAs_ShortcutBarRefreshMessage(output);
}

void ShortcutBarRefreshMessage::serializeAs_ShortcutBarRefreshMessage(Writer *output)
{
  output->writeByte(this->barType);
  output->writeShort((short)this->shortcut->getTypes().last());
  this->shortcut->serialize(output);
}

void ShortcutBarRefreshMessage::deserialize(Reader *input)
{
  this->deserializeAs_ShortcutBarRefreshMessage(input);
}

void ShortcutBarRefreshMessage::deserializeAs_ShortcutBarRefreshMessage(Reader *input)
{
  this->_barTypeFunc(input);
  uint _id2 = input->readUShort();
  this->shortcut = qSharedPointerCast<Shortcut>(ClassManagerSingleton::get()->getClass(_id2));
  this->shortcut->deserialize(input);
}

void ShortcutBarRefreshMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShortcutBarRefreshMessage(tree);
}

void ShortcutBarRefreshMessage::deserializeAsyncAs_ShortcutBarRefreshMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ShortcutBarRefreshMessage::_barTypeFunc, this, std::placeholders::_1));
  this->_shortcuttree = tree.addChild(std::bind(&ShortcutBarRefreshMessage::_shortcuttreeFunc, this, std::placeholders::_1));
}

void ShortcutBarRefreshMessage::_barTypeFunc(Reader *input)
{
  this->barType = input->readByte();
  if(this->barType < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarRefreshMessage -"<<"Forbidden value (" << this->barType << ") on element of ShortcutBarRefreshMessage.barType.";
  }
}

void ShortcutBarRefreshMessage::_shortcuttreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->shortcut = qSharedPointerCast<Shortcut>(ClassManagerSingleton::get()->getClass(_id));
  this->shortcut->deserializeAsync(this->_shortcuttree);
}

ShortcutBarRefreshMessage::ShortcutBarRefreshMessage()
{
  m_type = MessageEnum::SHORTCUTBARREFRESHMESSAGE;
}

