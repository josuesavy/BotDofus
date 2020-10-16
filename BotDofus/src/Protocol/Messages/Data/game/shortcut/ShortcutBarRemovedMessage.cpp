#include "ShortcutBarRemovedMessage.h"

void ShortcutBarRemovedMessage::serialize(Writer *output)
{
  this->serializeAs_ShortcutBarRemovedMessage(output);
}

void ShortcutBarRemovedMessage::serializeAs_ShortcutBarRemovedMessage(Writer *output)
{
  output->writeByte(this->barType);
  if(this->slot < 0 || this->slot > 99)
  {
    qDebug()<<"ERREUR - ShortcutBarRemovedMessage -"<<"Forbidden value (" << this->slot << ") on element slot.";
  }
  output->writeByte(this->slot);
}

void ShortcutBarRemovedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ShortcutBarRemovedMessage(input);
}

void ShortcutBarRemovedMessage::deserializeAs_ShortcutBarRemovedMessage(Reader *input)
{
  this->_barTypeFunc(input);
  this->_slotFunc(input);
}

void ShortcutBarRemovedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShortcutBarRemovedMessage(tree);
}

void ShortcutBarRemovedMessage::deserializeAsyncAs_ShortcutBarRemovedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ShortcutBarRemovedMessage::_barTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ShortcutBarRemovedMessage::_slotFunc, this, std::placeholders::_1));
}

void ShortcutBarRemovedMessage::_barTypeFunc(Reader *input)
{
  this->barType = input->readByte();
  if(this->barType < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarRemovedMessage -"<<"Forbidden value (" << this->barType << ") on element of ShortcutBarRemovedMessage.barType.";
  }
}

void ShortcutBarRemovedMessage::_slotFunc(Reader *input)
{
  this->slot = input->readByte();
  if(this->slot < 0 || this->slot > 99)
  {
    qDebug()<<"ERREUR - ShortcutBarRemovedMessage -"<<"Forbidden value (" << this->slot << ") on element of ShortcutBarRemovedMessage.slot.";
  }
}

ShortcutBarRemovedMessage::ShortcutBarRemovedMessage()
{
  m_type = MessageEnum::SHORTCUTBARREMOVEDMESSAGE;
}

