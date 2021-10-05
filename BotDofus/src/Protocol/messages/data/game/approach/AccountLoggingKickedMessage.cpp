#include "AccountLoggingKickedMessage.h"

void AccountLoggingKickedMessage::serialize(Writer *output)
{
  this->serializeAs_AccountLoggingKickedMessage(output);
}

void AccountLoggingKickedMessage::serializeAs_AccountLoggingKickedMessage(Writer *output)
{
  if(this->days < 0)
  {
    qDebug()<<"ERREUR - AccountLoggingKickedMessage -"<<"Forbidden value (" << this->days << ") on element days.";
  }
  output->writeVarShort((int)this->days);
  if(this->hours < 0)
  {
    qDebug()<<"ERREUR - AccountLoggingKickedMessage -"<<"Forbidden value (" << this->hours << ") on element hours.";
  }
  output->writeByte(this->hours);
  if(this->minutes < 0)
  {
    qDebug()<<"ERREUR - AccountLoggingKickedMessage -"<<"Forbidden value (" << this->minutes << ") on element minutes.";
  }
  output->writeByte(this->minutes);
}

void AccountLoggingKickedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AccountLoggingKickedMessage(input);
}

void AccountLoggingKickedMessage::deserializeAs_AccountLoggingKickedMessage(Reader *input)
{
  this->_daysFunc(input);
  this->_hoursFunc(input);
  this->_minutesFunc(input);
}

void AccountLoggingKickedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AccountLoggingKickedMessage(tree);
}

void AccountLoggingKickedMessage::deserializeAsyncAs_AccountLoggingKickedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AccountLoggingKickedMessage::_daysFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AccountLoggingKickedMessage::_hoursFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AccountLoggingKickedMessage::_minutesFunc, this, std::placeholders::_1));
}

void AccountLoggingKickedMessage::_daysFunc(Reader *input)
{
  this->days = input->readVarUhShort();
  if(this->days < 0)
  {
    qDebug()<<"ERREUR - AccountLoggingKickedMessage -"<<"Forbidden value (" << this->days << ") on element of AccountLoggingKickedMessage.days.";
  }
}

void AccountLoggingKickedMessage::_hoursFunc(Reader *input)
{
  this->hours = input->readByte();
  if(this->hours < 0)
  {
    qDebug()<<"ERREUR - AccountLoggingKickedMessage -"<<"Forbidden value (" << this->hours << ") on element of AccountLoggingKickedMessage.hours.";
  }
}

void AccountLoggingKickedMessage::_minutesFunc(Reader *input)
{
  this->minutes = input->readByte();
  if(this->minutes < 0)
  {
    qDebug()<<"ERREUR - AccountLoggingKickedMessage -"<<"Forbidden value (" << this->minutes << ") on element of AccountLoggingKickedMessage.minutes.";
  }
}

AccountLoggingKickedMessage::AccountLoggingKickedMessage()
{
  m_type = MessageEnum::ACCOUNTLOGGINGKICKEDMESSAGE;
}

