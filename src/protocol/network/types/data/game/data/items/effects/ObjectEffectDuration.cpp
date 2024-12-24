#include "ObjectEffectDuration.h"

void ObjectEffectDuration::serialize(Writer *output)
{
  this->serializeAs_ObjectEffectDuration(output);
}

void ObjectEffectDuration::serializeAs_ObjectEffectDuration(Writer *output)
{
  ObjectEffect::serializeAs_ObjectEffect(output);
  if(this->days < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDuration -"<<"Forbidden value (" << this->days << ") on element days.";
  }
  output->writeVarShort((int)this->days);
  if(this->hours < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDuration -"<<"Forbidden value (" << this->hours << ") on element hours.";
  }
  output->writeByte(this->hours);
  if(this->minutes < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDuration -"<<"Forbidden value (" << this->minutes << ") on element minutes.";
  }
  output->writeByte(this->minutes);
}

void ObjectEffectDuration::deserialize(Reader *input)
{
  this->deserializeAs_ObjectEffectDuration(input);
}

void ObjectEffectDuration::deserializeAs_ObjectEffectDuration(Reader *input)
{
  ObjectEffect::deserialize(input);
  this->_daysFunc(input);
  this->_hoursFunc(input);
  this->_minutesFunc(input);
}

void ObjectEffectDuration::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectEffectDuration(tree);
}

void ObjectEffectDuration::deserializeAsyncAs_ObjectEffectDuration(FuncTree tree)
{
  ObjectEffect::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectEffectDuration::_daysFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectEffectDuration::_hoursFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectEffectDuration::_minutesFunc, this, std::placeholders::_1));
}

void ObjectEffectDuration::_daysFunc(Reader *input)
{
  this->days = input->readVarUhShort();
  if(this->days < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDuration -"<<"Forbidden value (" << this->days << ") on element of ObjectEffectDuration.days.";
  }
}

void ObjectEffectDuration::_hoursFunc(Reader *input)
{
  this->hours = input->readByte();
  if(this->hours < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDuration -"<<"Forbidden value (" << this->hours << ") on element of ObjectEffectDuration.hours.";
  }
}

void ObjectEffectDuration::_minutesFunc(Reader *input)
{
  this->minutes = input->readByte();
  if(this->minutes < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDuration -"<<"Forbidden value (" << this->minutes << ") on element of ObjectEffectDuration.minutes.";
  }
}

ObjectEffectDuration::ObjectEffectDuration()
{
  m_types<<ClassEnum::OBJECTEFFECTDURATION;
}

bool ObjectEffectDuration::operator==(const ObjectEffectDuration &compared)
{
  if(days == compared.days)
  if(hours == compared.hours)
  if(minutes == compared.minutes)
  return true;
  
  return false;
}

