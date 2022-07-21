#include "LivingObjectMessageMessage.h"

void LivingObjectMessageMessage::serialize(Writer *output)
{
  this->serializeAs_LivingObjectMessageMessage(output);
}

void LivingObjectMessageMessage::serializeAs_LivingObjectMessageMessage(Writer *output)
{
  if(this->msgId < 0)
  {
    qDebug()<<"ERREUR - LivingObjectMessageMessage -"<<"Forbidden value (" << this->msgId << ") on element msgId.";
  }
  output->writeVarShort((int)this->msgId);
  if(this->timeStamp < 0)
  {
    qDebug()<<"ERREUR - LivingObjectMessageMessage -"<<"Forbidden value (" << this->timeStamp << ") on element timeStamp.";
  }
  output->writeInt((int)this->timeStamp);
  output->writeUTF(this->owner);
  if(this->objectGenericId < 0)
  {
    qDebug()<<"ERREUR - LivingObjectMessageMessage -"<<"Forbidden value (" << this->objectGenericId << ") on element objectGenericId.";
  }
  output->writeVarInt((int)this->objectGenericId);
}

void LivingObjectMessageMessage::deserialize(Reader *input)
{
  this->deserializeAs_LivingObjectMessageMessage(input);
}

void LivingObjectMessageMessage::deserializeAs_LivingObjectMessageMessage(Reader *input)
{
  this->_msgIdFunc(input);
  this->_timeStampFunc(input);
  this->_ownerFunc(input);
  this->_objectGenericIdFunc(input);
}

void LivingObjectMessageMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_LivingObjectMessageMessage(tree);
}

void LivingObjectMessageMessage::deserializeAsyncAs_LivingObjectMessageMessage(FuncTree tree)
{
  tree.addChild(std::bind(&LivingObjectMessageMessage::_msgIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&LivingObjectMessageMessage::_timeStampFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&LivingObjectMessageMessage::_ownerFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&LivingObjectMessageMessage::_objectGenericIdFunc, this, std::placeholders::_1));
}

void LivingObjectMessageMessage::_msgIdFunc(Reader *input)
{
  this->msgId = input->readVarUhShort();
  if(this->msgId < 0)
  {
    qDebug()<<"ERREUR - LivingObjectMessageMessage -"<<"Forbidden value (" << this->msgId << ") on element of LivingObjectMessageMessage.msgId.";
  }
}

void LivingObjectMessageMessage::_timeStampFunc(Reader *input)
{
  this->timeStamp = input->readInt();
  if(this->timeStamp < 0)
  {
    qDebug()<<"ERREUR - LivingObjectMessageMessage -"<<"Forbidden value (" << this->timeStamp << ") on element of LivingObjectMessageMessage.timeStamp.";
  }
}

void LivingObjectMessageMessage::_ownerFunc(Reader *input)
{
  this->owner = input->readUTF();
}

void LivingObjectMessageMessage::_objectGenericIdFunc(Reader *input)
{
  this->objectGenericId = input->readVarUhInt();
  if(this->objectGenericId < 0)
  {
    qDebug()<<"ERREUR - LivingObjectMessageMessage -"<<"Forbidden value (" << this->objectGenericId << ") on element of LivingObjectMessageMessage.objectGenericId.";
  }
}

LivingObjectMessageMessage::LivingObjectMessageMessage()
{
  m_type = MessageEnum::LIVINGOBJECTMESSAGEMESSAGE;
}

