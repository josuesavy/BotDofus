#include "ShortcutBarSwapRequestMessage.h"

void ShortcutBarSwapRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ShortcutBarSwapRequestMessage(output);
}

void ShortcutBarSwapRequestMessage::serializeAs_ShortcutBarSwapRequestMessage(Writer *output)
{
  output->writeByte(this->barType);
  if(this->firstSlot < 0 || this->firstSlot > 99)
  {
    qDebug()<<"ERREUR - ShortcutBarSwapRequestMessage -"<<"Forbidden value (" << this->firstSlot << ") on element firstSlot.";
  }
  output->writeByte(this->firstSlot);
  if(this->secondSlot < 0 || this->secondSlot > 99)
  {
    qDebug()<<"ERREUR - ShortcutBarSwapRequestMessage -"<<"Forbidden value (" << this->secondSlot << ") on element secondSlot.";
  }
  output->writeByte(this->secondSlot);
}

void ShortcutBarSwapRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ShortcutBarSwapRequestMessage(input);
}

void ShortcutBarSwapRequestMessage::deserializeAs_ShortcutBarSwapRequestMessage(Reader *input)
{
  this->_barTypeFunc(input);
  this->_firstSlotFunc(input);
  this->_secondSlotFunc(input);
}

void ShortcutBarSwapRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShortcutBarSwapRequestMessage(tree);
}

void ShortcutBarSwapRequestMessage::deserializeAsyncAs_ShortcutBarSwapRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ShortcutBarSwapRequestMessage::_barTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ShortcutBarSwapRequestMessage::_firstSlotFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ShortcutBarSwapRequestMessage::_secondSlotFunc, this, std::placeholders::_1));
}

void ShortcutBarSwapRequestMessage::_barTypeFunc(Reader *input)
{
  this->barType = input->readByte();
  if(this->barType < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarSwapRequestMessage -"<<"Forbidden value (" << this->barType << ") on element of ShortcutBarSwapRequestMessage.barType.";
  }
}

void ShortcutBarSwapRequestMessage::_firstSlotFunc(Reader *input)
{
  this->firstSlot = input->readByte();
  if(this->firstSlot < 0 || this->firstSlot > 99)
  {
    qDebug()<<"ERREUR - ShortcutBarSwapRequestMessage -"<<"Forbidden value (" << this->firstSlot << ") on element of ShortcutBarSwapRequestMessage.firstSlot.";
  }
}

void ShortcutBarSwapRequestMessage::_secondSlotFunc(Reader *input)
{
  this->secondSlot = input->readByte();
  if(this->secondSlot < 0 || this->secondSlot > 99)
  {
    qDebug()<<"ERREUR - ShortcutBarSwapRequestMessage -"<<"Forbidden value (" << this->secondSlot << ") on element of ShortcutBarSwapRequestMessage.secondSlot.";
  }
}

ShortcutBarSwapRequestMessage::ShortcutBarSwapRequestMessage()
{
  m_type = MessageEnum::SHORTCUTBARSWAPREQUESTMESSAGE;
}

