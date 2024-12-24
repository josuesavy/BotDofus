#include "ShortcutBarReplacedMessage.h"

void ShortcutBarReplacedMessage::serialize(Writer *output)
{
  this->serializeAs_ShortcutBarReplacedMessage(output);
}

void ShortcutBarReplacedMessage::serializeAs_ShortcutBarReplacedMessage(Writer *output)
{
  output->writeByte(this->barType);
  output->writeShort((short)this->shortcut->getTypes().last());
  this->shortcut->serialize(output);
}

void ShortcutBarReplacedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ShortcutBarReplacedMessage(input);
}

void ShortcutBarReplacedMessage::deserializeAs_ShortcutBarReplacedMessage(Reader *input)
{
  this->_barTypeFunc(input);
  uint _id2 = uint(input->readUShort());
  this->shortcut = qSharedPointerCast<Shortcut>(ClassManagerSingleton::get()->getClass(_id2));
  this->shortcut->deserialize(input);
}

void ShortcutBarReplacedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShortcutBarReplacedMessage(tree);
}

void ShortcutBarReplacedMessage::deserializeAsyncAs_ShortcutBarReplacedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ShortcutBarReplacedMessage::_barTypeFunc, this, std::placeholders::_1));
  this->_shortcuttree = tree.addChild(std::bind(&ShortcutBarReplacedMessage::_shortcuttreeFunc, this, std::placeholders::_1));
}

void ShortcutBarReplacedMessage::_barTypeFunc(Reader *input)
{
  this->barType = input->readByte();
  if(this->barType < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarReplacedMessage -"<<"Forbidden value (" << this->barType << ") on element of ShortcutBarReplacedMessage.barType.";
  }
}

void ShortcutBarReplacedMessage::_shortcuttreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->shortcut = qSharedPointerCast<Shortcut>(ClassManagerSingleton::get()->getClass(_id));
  this->shortcut->deserializeAsync(this->_shortcuttree);
}

ShortcutBarReplacedMessage::ShortcutBarReplacedMessage()
{
  m_type = MessageEnum::SHORTCUTBARREPLACEDMESSAGE;
}

