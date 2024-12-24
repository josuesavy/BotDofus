#include "FightPhase.h"

void FightPhase::serialize(Writer *output)
{
  this->serializeAs_FightPhase(output);
}

void FightPhase::serializeAs_FightPhase(Writer *output)
{
  output->writeByte(this->phase);
  if(this->phaseEndTimeStamp < -9007199254740992 || this->phaseEndTimeStamp > 9007199254740992)
  {
    qDebug()<<"ERREUR - FightPhase -"<<"Forbidden value (" << this->phaseEndTimeStamp << ") on element phaseEndTimeStamp.";
  }
  output->writeDouble(this->phaseEndTimeStamp);
}

void FightPhase::deserialize(Reader *input)
{
  this->deserializeAs_FightPhase(input);
}

void FightPhase::deserializeAs_FightPhase(Reader *input)
{
  this->_phaseFunc(input);
  this->_phaseEndTimeStampFunc(input);
}

void FightPhase::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightPhase(tree);
}

void FightPhase::deserializeAsyncAs_FightPhase(FuncTree tree)
{
  tree.addChild(std::bind(&FightPhase::_phaseFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightPhase::_phaseEndTimeStampFunc, this, std::placeholders::_1));
}

void FightPhase::_phaseFunc(Reader *input)
{
  this->phase = input->readByte();
  if(this->phase < 0)
  {
    qDebug()<<"ERREUR - FightPhase -"<<"Forbidden value (" << this->phase << ") on element of FightPhase.phase.";
  }
}

void FightPhase::_phaseEndTimeStampFunc(Reader *input)
{
  this->phaseEndTimeStamp = input->readDouble();
  if(this->phaseEndTimeStamp < -9007199254740992 || this->phaseEndTimeStamp > 9007199254740992)
  {
    qDebug()<<"ERREUR - FightPhase -"<<"Forbidden value (" << this->phaseEndTimeStamp << ") on element of FightPhase.phaseEndTimeStamp.";
  }
}

FightPhase::FightPhase()
{
  m_types<<ClassEnum::FIGHTPHASE;
}

bool FightPhase::operator==(const FightPhase &compared)
{
  if(phase == compared.phase)
  if(phaseEndTimeStamp == compared.phaseEndTimeStamp)
  return true;
  
  return false;
}

