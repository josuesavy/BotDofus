#include "ObjectEffectDate.h"

void ObjectEffectDate::serialize(Writer *output)
{
  this->serializeAs_ObjectEffectDate(output);
}

void ObjectEffectDate::serializeAs_ObjectEffectDate(Writer *output)
{
  ObjectEffect::serializeAs_ObjectEffect(output);
  if(this->year < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->year << ") on element year.";
  }
  output->writeVarShort((int)this->year);
  if(this->month < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->month << ") on element month.";
  }
  output->writeByte(this->month);
  if(this->day < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->day << ") on element day.";
  }
  output->writeByte(this->day);
  if(this->hour < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->hour << ") on element hour.";
  }
  output->writeByte(this->hour);
  if(this->minute < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->minute << ") on element minute.";
  }
  output->writeByte(this->minute);
}

void ObjectEffectDate::deserialize(Reader *input)
{
  this->deserializeAs_ObjectEffectDate(input);
}

void ObjectEffectDate::deserializeAs_ObjectEffectDate(Reader *input)
{
  ObjectEffect::deserialize(input);
  this->_yearFunc(input);
  this->_monthFunc(input);
  this->_dayFunc(input);
  this->_hourFunc(input);
  this->_minuteFunc(input);
}

void ObjectEffectDate::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectEffectDate(tree);
}

void ObjectEffectDate::deserializeAsyncAs_ObjectEffectDate(FuncTree tree)
{
  ObjectEffect::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectEffectDate::_yearFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectEffectDate::_monthFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectEffectDate::_dayFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectEffectDate::_hourFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectEffectDate::_minuteFunc, this, std::placeholders::_1));
}

void ObjectEffectDate::_yearFunc(Reader *input)
{
  this->year = input->readVarUhShort();
  if(this->year < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->year << ") on element of ObjectEffectDate.year.";
  }
}

void ObjectEffectDate::_monthFunc(Reader *input)
{
  this->month = input->readByte();
  if(this->month < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->month << ") on element of ObjectEffectDate.month.";
  }
}

void ObjectEffectDate::_dayFunc(Reader *input)
{
  this->day = input->readByte();
  if(this->day < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->day << ") on element of ObjectEffectDate.day.";
  }
}

void ObjectEffectDate::_hourFunc(Reader *input)
{
  this->hour = input->readByte();
  if(this->hour < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->hour << ") on element of ObjectEffectDate.hour.";
  }
}

void ObjectEffectDate::_minuteFunc(Reader *input)
{
  this->minute = input->readByte();
  if(this->minute < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->minute << ") on element of ObjectEffectDate.minute.";
  }
}

ObjectEffectDate::ObjectEffectDate()
{
  m_types<<ClassEnum::OBJECTEFFECTDATE;
}

bool ObjectEffectDate::operator==(const ObjectEffectDate &compared)
{
  if(year == compared.year)
  if(month == compared.month)
  if(day == compared.day)
  if(hour == compared.hour)
  if(minute == compared.minute)
  return true;
  
  return false;
}

