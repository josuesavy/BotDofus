#include "LivingObjectDissociateMessage.h"

void LivingObjectDissociateMessage::serialize(Writer *output)
{
  this->serializeAs_LivingObjectDissociateMessage(output);
}

void LivingObjectDissociateMessage::serializeAs_LivingObjectDissociateMessage(Writer *output)
{
  if(this->livingUID < 0)
  {
    qDebug()<<"ERREUR - LivingObjectDissociateMessage -"<<"Forbidden value (" << this->livingUID << ") on element livingUID.";
  }
  output->writeVarInt((int)this->livingUID);
  if(this->livingPosition < 0 || this->livingPosition > 255)
  {
    qDebug()<<"ERREUR - LivingObjectDissociateMessage -"<<"Forbidden value (" << this->livingPosition << ") on element livingPosition.";
  }
  output->writeByte(this->livingPosition);
}

void LivingObjectDissociateMessage::deserialize(Reader *input)
{
  this->deserializeAs_LivingObjectDissociateMessage(input);
}

void LivingObjectDissociateMessage::deserializeAs_LivingObjectDissociateMessage(Reader *input)
{
  this->_livingUIDFunc(input);
  this->_livingPositionFunc(input);
}

void LivingObjectDissociateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_LivingObjectDissociateMessage(tree);
}

void LivingObjectDissociateMessage::deserializeAsyncAs_LivingObjectDissociateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&LivingObjectDissociateMessage::_livingUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&LivingObjectDissociateMessage::_livingPositionFunc, this, std::placeholders::_1));
}

void LivingObjectDissociateMessage::_livingUIDFunc(Reader *input)
{
  this->livingUID = input->readVarUhInt();
  if(this->livingUID < 0)
  {
    qDebug()<<"ERREUR - LivingObjectDissociateMessage -"<<"Forbidden value (" << this->livingUID << ") on element of LivingObjectDissociateMessage.livingUID.";
  }
}

void LivingObjectDissociateMessage::_livingPositionFunc(Reader *input)
{
  this->livingPosition = input->readUByte();
  if(this->livingPosition < 0 || this->livingPosition > 255)
  {
    qDebug()<<"ERREUR - LivingObjectDissociateMessage -"<<"Forbidden value (" << this->livingPosition << ") on element of LivingObjectDissociateMessage.livingPosition.";
  }
}

LivingObjectDissociateMessage::LivingObjectDissociateMessage()
{
  m_type = MessageEnum::LIVINGOBJECTDISSOCIATEMESSAGE;
}

