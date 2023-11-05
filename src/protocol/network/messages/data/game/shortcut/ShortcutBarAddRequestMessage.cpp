#include "ShortcutBarAddRequestMessage.h"

void ShortcutBarAddRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ShortcutBarAddRequestMessage(output);
}

void ShortcutBarAddRequestMessage::serializeAs_ShortcutBarAddRequestMessage(Writer *output)
{
  output->writeByte(this->barType);
  output->writeShort((short)this->shortcut->getTypes().last());
  this->shortcut->serialize(output);
}

void ShortcutBarAddRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ShortcutBarAddRequestMessage(input);
}

void ShortcutBarAddRequestMessage::deserializeAs_ShortcutBarAddRequestMessage(Reader *input)
{
  this->_barTypeFunc(input);
  uint _id2 = uint(input->readUShort());
  this->shortcut = qSharedPointerCast<Shortcut>(ClassManagerSingleton::get()->getClass(_id2));
  this->shortcut->deserialize(input);
}

void ShortcutBarAddRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShortcutBarAddRequestMessage(tree);
}

void ShortcutBarAddRequestMessage::deserializeAsyncAs_ShortcutBarAddRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ShortcutBarAddRequestMessage::_barTypeFunc, this, std::placeholders::_1));
  this->_shortcuttree = tree.addChild(std::bind(&ShortcutBarAddRequestMessage::_shortcuttreeFunc, this, std::placeholders::_1));
}

void ShortcutBarAddRequestMessage::_barTypeFunc(Reader *input)
{
  this->barType = input->readByte();
  if(this->barType < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarAddRequestMessage -"<<"Forbidden value (" << this->barType << ") on element of ShortcutBarAddRequestMessage.barType.";
  }
}

void ShortcutBarAddRequestMessage::_shortcuttreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->shortcut = qSharedPointerCast<Shortcut>(ClassManagerSingleton::get()->getClass(_id));
  this->shortcut->deserializeAsync(this->_shortcuttree);
}

ShortcutBarAddRequestMessage::ShortcutBarAddRequestMessage()
{
  m_type = MessageEnum::SHORTCUTBARADDREQUESTMESSAGE;
}

