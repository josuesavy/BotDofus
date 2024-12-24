#include "HumanOptionAlliance.h"

void HumanOptionAlliance::serialize(Writer *output)
{
  this->serializeAs_HumanOptionAlliance(output);
}

void HumanOptionAlliance::serializeAs_HumanOptionAlliance(Writer *output)
{
  HumanOption::serializeAs_HumanOption(output);
  this->allianceInformation->serializeAs_AllianceInformation(output);
  output->writeByte(this->aggressable);
}

void HumanOptionAlliance::deserialize(Reader *input)
{
  this->deserializeAs_HumanOptionAlliance(input);
}

void HumanOptionAlliance::deserializeAs_HumanOptionAlliance(Reader *input)
{
  HumanOption::deserialize(input);
  this->allianceInformation = QSharedPointer<AllianceInformation>(new AllianceInformation() );
  this->allianceInformation->deserialize(input);
  this->_aggressableFunc(input);
}

void HumanOptionAlliance::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HumanOptionAlliance(tree);
}

void HumanOptionAlliance::deserializeAsyncAs_HumanOptionAlliance(FuncTree tree)
{
  HumanOption::deserializeAsync(tree);
  this->_allianceInformationtree = tree.addChild(std::bind(&HumanOptionAlliance::_allianceInformationtreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HumanOptionAlliance::_aggressableFunc, this, std::placeholders::_1));
}

void HumanOptionAlliance::_allianceInformationtreeFunc(Reader *input)
{
  this->allianceInformation = QSharedPointer<AllianceInformation>(new AllianceInformation() );
  this->allianceInformation->deserializeAsync(this->_allianceInformationtree);
}

void HumanOptionAlliance::_aggressableFunc(Reader *input)
{
  this->aggressable = input->readByte();
  if(this->aggressable < 0)
  {
    qDebug()<<"ERREUR - HumanOptionAlliance -"<<"Forbidden value (" << this->aggressable << ") on element of HumanOptionAlliance.aggressable.";
  }
}

HumanOptionAlliance::HumanOptionAlliance()
{
  m_types<<ClassEnum::HUMANOPTIONALLIANCE;
}

bool HumanOptionAlliance::operator==(const HumanOptionAlliance &compared)
{
  if(allianceInformation == compared.allianceInformation)
  if(aggressable == compared.aggressable)
  if(_allianceInformationtree == compared._allianceInformationtree)
  return true;
  
  return false;
}

