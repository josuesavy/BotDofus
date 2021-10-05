#include "HumanOptionAlliance.h"

void HumanOptionAlliance::serialize(Writer *output)
{
  this->serializeAs_HumanOptionAlliance(output);
}

void HumanOptionAlliance::serializeAs_HumanOptionAlliance(Writer *output)
{
  HumanOption::serializeAs_HumanOption(output);
  this->allianceInformations->serializeAs_AllianceInformations(output);
  output->writeByte(this->aggressable);
}

void HumanOptionAlliance::deserialize(Reader *input)
{
  this->deserializeAs_HumanOptionAlliance(input);
}

void HumanOptionAlliance::deserializeAs_HumanOptionAlliance(Reader *input)
{
  HumanOption::deserialize(input);
  this->allianceInformations = QSharedPointer<AllianceInformations>(new AllianceInformations() );
  this->allianceInformations->deserialize(input);
  this->_aggressableFunc(input);
}

void HumanOptionAlliance::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HumanOptionAlliance(tree);
}

void HumanOptionAlliance::deserializeAsyncAs_HumanOptionAlliance(FuncTree tree)
{
  HumanOption::deserializeAsync(tree);
  this->_allianceInformationstree = tree.addChild(std::bind(&HumanOptionAlliance::_allianceInformationstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HumanOptionAlliance::_aggressableFunc, this, std::placeholders::_1));
}

void HumanOptionAlliance::_allianceInformationstreeFunc(Reader *input)
{
  this->allianceInformations = QSharedPointer<AllianceInformations>(new AllianceInformations() );
  this->allianceInformations->deserializeAsync(this->_allianceInformationstree);
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
  if(allianceInformations == compared.allianceInformations)
  if(aggressable == compared.aggressable)
  if(_allianceInformationstree == compared._allianceInformationstree)
  return true;
  
  return false;
}

