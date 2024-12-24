#include "BasicDateMessage.h"

void BasicDateMessage::serialize(Writer *output)
{
  this->serializeAs_BasicDateMessage(output);
}

void BasicDateMessage::serializeAs_BasicDateMessage(Writer *output)
{
  if(this->day < 0)
  {
    qDebug()<<"ERREUR - BasicDateMessage -"<<"Forbidden value (" << this->day << ") on element day.";
  }
  output->writeByte(this->day);
  if(this->month < 0)
  {
    qDebug()<<"ERREUR - BasicDateMessage -"<<"Forbidden value (" << this->month << ") on element month.";
  }
  output->writeByte(this->month);
  if(this->year < 0)
  {
    qDebug()<<"ERREUR - BasicDateMessage -"<<"Forbidden value (" << this->year << ") on element year.";
  }
  output->writeShort((short)this->year);
}

void BasicDateMessage::deserialize(Reader *input)
{
  this->deserializeAs_BasicDateMessage(input);
}

void BasicDateMessage::deserializeAs_BasicDateMessage(Reader *input)
{
  this->_dayFunc(input);
  this->_monthFunc(input);
  this->_yearFunc(input);
}

void BasicDateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BasicDateMessage(tree);
}

void BasicDateMessage::deserializeAsyncAs_BasicDateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BasicDateMessage::_dayFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BasicDateMessage::_monthFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BasicDateMessage::_yearFunc, this, std::placeholders::_1));
}

void BasicDateMessage::_dayFunc(Reader *input)
{
  this->day = input->readByte();
  if(this->day < 0)
  {
    qDebug()<<"ERREUR - BasicDateMessage -"<<"Forbidden value (" << this->day << ") on element of BasicDateMessage.day.";
  }
}

void BasicDateMessage::_monthFunc(Reader *input)
{
  this->month = input->readByte();
  if(this->month < 0)
  {
    qDebug()<<"ERREUR - BasicDateMessage -"<<"Forbidden value (" << this->month << ") on element of BasicDateMessage.month.";
  }
}

void BasicDateMessage::_yearFunc(Reader *input)
{
  this->year = input->readShort();
  if(this->year < 0)
  {
    qDebug()<<"ERREUR - BasicDateMessage -"<<"Forbidden value (" << this->year << ") on element of BasicDateMessage.year.";
  }
}

BasicDateMessage::BasicDateMessage()
{
  m_type = MessageEnum::BASICDATEMESSAGE;
}

