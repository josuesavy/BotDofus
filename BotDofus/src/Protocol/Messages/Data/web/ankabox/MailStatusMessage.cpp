#include "MailStatusMessage.h"

void MailStatusMessage::serialize(Writer *output)
{
  this->serializeAs_MailStatusMessage(output);
}

void MailStatusMessage::serializeAs_MailStatusMessage(Writer *output)
{
  if(this->unread < 0)
  {
    qDebug()<<"ERREUR - MailStatusMessage -"<<"Forbidden value (" << this->unread << ") on element unread.";
  }
  output->writeVarShort((int)this->unread);
  if(this->total < 0)
  {
    qDebug()<<"ERREUR - MailStatusMessage -"<<"Forbidden value (" << this->total << ") on element total.";
  }
  output->writeVarShort((int)this->total);
}

void MailStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_MailStatusMessage(input);
}

void MailStatusMessage::deserializeAs_MailStatusMessage(Reader *input)
{
  this->_unreadFunc(input);
  this->_totalFunc(input);
}

void MailStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MailStatusMessage(tree);
}

void MailStatusMessage::deserializeAsyncAs_MailStatusMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MailStatusMessage::_unreadFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MailStatusMessage::_totalFunc, this, std::placeholders::_1));
}

void MailStatusMessage::_unreadFunc(Reader *input)
{
  this->unread = input->readVarUhShort();
  if(this->unread < 0)
  {
    qDebug()<<"ERREUR - MailStatusMessage -"<<"Forbidden value (" << this->unread << ") on element of MailStatusMessage.unread.";
  }
}

void MailStatusMessage::_totalFunc(Reader *input)
{
  this->total = input->readVarUhShort();
  if(this->total < 0)
  {
    qDebug()<<"ERREUR - MailStatusMessage -"<<"Forbidden value (" << this->total << ") on element of MailStatusMessage.total.";
  }
}

MailStatusMessage::MailStatusMessage()
{
  m_type = MessageEnum::MAILSTATUSMESSAGE;
}

