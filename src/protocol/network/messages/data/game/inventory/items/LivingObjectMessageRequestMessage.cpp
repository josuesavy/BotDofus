#include "LivingObjectMessageRequestMessage.h"

void LivingObjectMessageRequestMessage::serialize(Writer *output)
{
  this->serializeAs_LivingObjectMessageRequestMessage(output);
}

void LivingObjectMessageRequestMessage::serializeAs_LivingObjectMessageRequestMessage(Writer *output)
{
  if(this->msgId < 0)
  {
    qDebug()<<"ERREUR - LivingObjectMessageRequestMessage -"<<"Forbidden value (" << this->msgId << ") on element msgId.";
  }
  output->writeVarShort((int)this->msgId);
  output->writeShort((short)this->parameters.size());
  for(uint _i2 = 0; _i2 < this->parameters.size(); _i2++)
  {
    output->writeUTF(this->parameters[_i2]);
  }
  if(this->livingObject < 0)
  {
    qDebug()<<"ERREUR - LivingObjectMessageRequestMessage -"<<"Forbidden value (" << this->livingObject << ") on element livingObject.";
  }
  output->writeVarInt((int)this->livingObject);
}

void LivingObjectMessageRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_LivingObjectMessageRequestMessage(input);
}

void LivingObjectMessageRequestMessage::deserializeAs_LivingObjectMessageRequestMessage(Reader *input)
{
  QString _val2 ;
  this->_msgIdFunc(input);
  uint _parametersLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _parametersLen; _i2++)
  {
    _val2 = input->readUTF();
    this->parameters.append(_val2);
  }
  this->_livingObjectFunc(input);
}

void LivingObjectMessageRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_LivingObjectMessageRequestMessage(tree);
}

void LivingObjectMessageRequestMessage::deserializeAsyncAs_LivingObjectMessageRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&LivingObjectMessageRequestMessage::_msgIdFunc, this, std::placeholders::_1));
  this->_parameterstree = tree.addChild(std::bind(&LivingObjectMessageRequestMessage::_parameterstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&LivingObjectMessageRequestMessage::_livingObjectFunc, this, std::placeholders::_1));
}

void LivingObjectMessageRequestMessage::_msgIdFunc(Reader *input)
{
  this->msgId = input->readVarUhShort();
  if(this->msgId < 0)
  {
    qDebug()<<"ERREUR - LivingObjectMessageRequestMessage -"<<"Forbidden value (" << this->msgId << ") on element of LivingObjectMessageRequestMessage.msgId.";
  }
}

void LivingObjectMessageRequestMessage::_parameterstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_parameterstree.addChild(std::bind(&LivingObjectMessageRequestMessage::_parametersFunc, this, std::placeholders::_1));
  }
}

void LivingObjectMessageRequestMessage::_parametersFunc(Reader *input)
{
  QString _val = input->readUTF();
  this->parameters.append(_val);
}

void LivingObjectMessageRequestMessage::_livingObjectFunc(Reader *input)
{
  this->livingObject = input->readVarUhInt();
  if(this->livingObject < 0)
  {
    qDebug()<<"ERREUR - LivingObjectMessageRequestMessage -"<<"Forbidden value (" << this->livingObject << ") on element of LivingObjectMessageRequestMessage.livingObject.";
  }
}

LivingObjectMessageRequestMessage::LivingObjectMessageRequestMessage()
{
  m_type = MessageEnum::LIVINGOBJECTMESSAGEREQUESTMESSAGE;
}

