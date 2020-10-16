#include "HumanOptionEmote.h"

void HumanOptionEmote::serialize(Writer *output)
{
  this->serializeAs_HumanOptionEmote(output);
}

void HumanOptionEmote::serializeAs_HumanOptionEmote(Writer *output)
{
  HumanOption::serializeAs_HumanOption(output);
  if(this->emoteId < 0 || this->emoteId > 255)
  {
    qDebug()<<"ERREUR - HumanOptionEmote -"<<"Forbidden value (" << this->emoteId << ") on element emoteId.";
  }
  output->writeByte(this->emoteId);
  if(this->emoteStartTime < -9.007199254740992E15 || this->emoteStartTime > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HumanOptionEmote -"<<"Forbidden value (" << this->emoteStartTime << ") on element emoteStartTime.";
  }
  output->writeDouble(this->emoteStartTime);
}

void HumanOptionEmote::deserialize(Reader *input)
{
  this->deserializeAs_HumanOptionEmote(input);
}

void HumanOptionEmote::deserializeAs_HumanOptionEmote(Reader *input)
{
  HumanOption::deserialize(input);
  this->_emoteIdFunc(input);
  this->_emoteStartTimeFunc(input);
}

void HumanOptionEmote::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HumanOptionEmote(tree);
}

void HumanOptionEmote::deserializeAsyncAs_HumanOptionEmote(FuncTree tree)
{
  HumanOption::deserializeAsync(tree);
  tree.addChild(std::bind(&HumanOptionEmote::_emoteIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HumanOptionEmote::_emoteStartTimeFunc, this, std::placeholders::_1));
}

void HumanOptionEmote::_emoteIdFunc(Reader *input)
{
  this->emoteId = input->readUByte();
  if(this->emoteId < 0 || this->emoteId > 255)
  {
    qDebug()<<"ERREUR - HumanOptionEmote -"<<"Forbidden value (" << this->emoteId << ") on element of HumanOptionEmote.emoteId.";
  }
}

void HumanOptionEmote::_emoteStartTimeFunc(Reader *input)
{
  this->emoteStartTime = input->readDouble();
  if(this->emoteStartTime < -9.007199254740992E15 || this->emoteStartTime > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HumanOptionEmote -"<<"Forbidden value (" << this->emoteStartTime << ") on element of HumanOptionEmote.emoteStartTime.";
  }
}

HumanOptionEmote::HumanOptionEmote()
{
  m_types<<ClassEnum::HUMANOPTIONEMOTE;
}

bool HumanOptionEmote::operator==(const HumanOptionEmote &compared)
{
  if(emoteId == compared.emoteId)
  if(emoteStartTime == compared.emoteStartTime)
  return true;
  
  return false;
}

