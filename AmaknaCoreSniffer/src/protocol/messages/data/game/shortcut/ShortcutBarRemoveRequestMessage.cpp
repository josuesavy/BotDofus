#include "ShortcutBarRemoveRequestMessage.h"

void ShortcutBarRemoveRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ShortcutBarRemoveRequestMessage(output);
}

void ShortcutBarRemoveRequestMessage::serializeAs_ShortcutBarRemoveRequestMessage(Writer *output)
{
  output->writeByte(this->barType);
  if(this->slot < 0 || this->slot > 99)
  {
    qDebug()<<"ERREUR - ShortcutBarRemoveRequestMessage -"<<"Forbidden value (" << this->slot << ") on element slot.";
  }
  output->writeByte(this->slot);
}

void ShortcutBarRemoveRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ShortcutBarRemoveRequestMessage(input);
}

void ShortcutBarRemoveRequestMessage::deserializeAs_ShortcutBarRemoveRequestMessage(Reader *input)
{
  this->_barTypeFunc(input);
  this->_slotFunc(input);
}

void ShortcutBarRemoveRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShortcutBarRemoveRequestMessage(tree);
}

void ShortcutBarRemoveRequestMessage::deserializeAsyncAs_ShortcutBarRemoveRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ShortcutBarRemoveRequestMessage::_barTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ShortcutBarRemoveRequestMessage::_slotFunc, this, std::placeholders::_1));
}

void ShortcutBarRemoveRequestMessage::_barTypeFunc(Reader *input)
{
  this->barType = input->readByte();
  if(this->barType < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarRemoveRequestMessage -"<<"Forbidden value (" << this->barType << ") on element of ShortcutBarRemoveRequestMessage.barType.";
  }
}

void ShortcutBarRemoveRequestMessage::_slotFunc(Reader *input)
{
  this->slot = input->readByte();
  if(this->slot < 0 || this->slot > 99)
  {
    qDebug()<<"ERREUR - ShortcutBarRemoveRequestMessage -"<<"Forbidden value (" << this->slot << ") on element of ShortcutBarRemoveRequestMessage.slot.";
  }
}

ShortcutBarRemoveRequestMessage::ShortcutBarRemoveRequestMessage()
{
  m_type = MessageEnum::SHORTCUTBARREMOVEREQUESTMESSAGE;
}

