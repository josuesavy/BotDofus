#include "NotificationUpdateFlagMessage.h"

void NotificationUpdateFlagMessage::serialize(Writer *output)
{
  this->serializeAs_NotificationUpdateFlagMessage(output);
}

void NotificationUpdateFlagMessage::serializeAs_NotificationUpdateFlagMessage(Writer *output)
{
  if(this->index < 0)
  {
    qDebug()<<"ERREUR - NotificationUpdateFlagMessage -"<<"Forbidden value (" << this->index << ") on element index.";
  }
  output->writeVarShort((int)this->index);
}

void NotificationUpdateFlagMessage::deserialize(Reader *input)
{
  this->deserializeAs_NotificationUpdateFlagMessage(input);
}

void NotificationUpdateFlagMessage::deserializeAs_NotificationUpdateFlagMessage(Reader *input)
{
  this->_indexFunc(input);
}

void NotificationUpdateFlagMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_NotificationUpdateFlagMessage(tree);
}

void NotificationUpdateFlagMessage::deserializeAsyncAs_NotificationUpdateFlagMessage(FuncTree tree)
{
  tree.addChild(std::bind(&NotificationUpdateFlagMessage::_indexFunc, this, std::placeholders::_1));
}

void NotificationUpdateFlagMessage::_indexFunc(Reader *input)
{
  this->index = input->readVarUhShort();
  if(this->index < 0)
  {
    qDebug()<<"ERREUR - NotificationUpdateFlagMessage -"<<"Forbidden value (" << this->index << ") on element of NotificationUpdateFlagMessage.index.";
  }
}

NotificationUpdateFlagMessage::NotificationUpdateFlagMessage()
{
  m_type = MessageEnum::NOTIFICATIONUPDATEFLAGMESSAGE;
}

