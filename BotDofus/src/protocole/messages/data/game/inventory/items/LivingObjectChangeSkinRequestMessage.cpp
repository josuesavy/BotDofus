#include "LivingObjectChangeSkinRequestMessage.h"

void LivingObjectChangeSkinRequestMessage::serialize(Writer *output)
{
  this->serializeAs_LivingObjectChangeSkinRequestMessage(output);
}

void LivingObjectChangeSkinRequestMessage::serializeAs_LivingObjectChangeSkinRequestMessage(Writer *output)
{
  if(this->livingUID < 0)
  {
    qDebug()<<"ERREUR - LivingObjectChangeSkinRequestMessage -"<<"Forbidden value (" << this->livingUID << ") on element livingUID.";
  }
  output->writeVarInt((int)this->livingUID);
  if(this->livingPosition < 0 || this->livingPosition > 255)
  {
    qDebug()<<"ERREUR - LivingObjectChangeSkinRequestMessage -"<<"Forbidden value (" << this->livingPosition << ") on element livingPosition.";
  }
  output->writeByte(this->livingPosition);
  if(this->skinId < 0)
  {
    qDebug()<<"ERREUR - LivingObjectChangeSkinRequestMessage -"<<"Forbidden value (" << this->skinId << ") on element skinId.";
  }
  output->writeVarInt((int)this->skinId);
}

void LivingObjectChangeSkinRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_LivingObjectChangeSkinRequestMessage(input);
}

void LivingObjectChangeSkinRequestMessage::deserializeAs_LivingObjectChangeSkinRequestMessage(Reader *input)
{
  this->_livingUIDFunc(input);
  this->_livingPositionFunc(input);
  this->_skinIdFunc(input);
}

void LivingObjectChangeSkinRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_LivingObjectChangeSkinRequestMessage(tree);
}

void LivingObjectChangeSkinRequestMessage::deserializeAsyncAs_LivingObjectChangeSkinRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&LivingObjectChangeSkinRequestMessage::_livingUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&LivingObjectChangeSkinRequestMessage::_livingPositionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&LivingObjectChangeSkinRequestMessage::_skinIdFunc, this, std::placeholders::_1));
}

void LivingObjectChangeSkinRequestMessage::_livingUIDFunc(Reader *input)
{
  this->livingUID = input->readVarUhInt();
  if(this->livingUID < 0)
  {
    qDebug()<<"ERREUR - LivingObjectChangeSkinRequestMessage -"<<"Forbidden value (" << this->livingUID << ") on element of LivingObjectChangeSkinRequestMessage.livingUID.";
  }
}

void LivingObjectChangeSkinRequestMessage::_livingPositionFunc(Reader *input)
{
  this->livingPosition = input->readUByte();
  if(this->livingPosition < 0 || this->livingPosition > 255)
  {
    qDebug()<<"ERREUR - LivingObjectChangeSkinRequestMessage -"<<"Forbidden value (" << this->livingPosition << ") on element of LivingObjectChangeSkinRequestMessage.livingPosition.";
  }
}

void LivingObjectChangeSkinRequestMessage::_skinIdFunc(Reader *input)
{
  this->skinId = input->readVarUhInt();
  if(this->skinId < 0)
  {
    qDebug()<<"ERREUR - LivingObjectChangeSkinRequestMessage -"<<"Forbidden value (" << this->skinId << ") on element of LivingObjectChangeSkinRequestMessage.skinId.";
  }
}

LivingObjectChangeSkinRequestMessage::LivingObjectChangeSkinRequestMessage()
{
  m_type = MessageEnum::LIVINGOBJECTCHANGESKINREQUESTMESSAGE;
}

