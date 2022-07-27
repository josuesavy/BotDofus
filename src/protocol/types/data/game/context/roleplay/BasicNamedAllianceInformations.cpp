#include "BasicNamedAllianceInformations.h"

void BasicNamedAllianceInformations::serialize(Writer *output)
{
  this->serializeAs_BasicNamedAllianceInformations(output);
}

void BasicNamedAllianceInformations::serializeAs_BasicNamedAllianceInformations(Writer *output)
{
  BasicAllianceInformations::serializeAs_BasicAllianceInformations(output);
  output->writeUTF(this->allianceName);
}

void BasicNamedAllianceInformations::deserialize(Reader *input)
{
  this->deserializeAs_BasicNamedAllianceInformations(input);
}

void BasicNamedAllianceInformations::deserializeAs_BasicNamedAllianceInformations(Reader *input)
{
  BasicAllianceInformations::deserialize(input);
  this->_allianceNameFunc(input);
}

void BasicNamedAllianceInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BasicNamedAllianceInformations(tree);
}

void BasicNamedAllianceInformations::deserializeAsyncAs_BasicNamedAllianceInformations(FuncTree tree)
{
  BasicAllianceInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&BasicNamedAllianceInformations::_allianceNameFunc, this, std::placeholders::_1));
}

void BasicNamedAllianceInformations::_allianceNameFunc(Reader *input)
{
  this->allianceName = input->readUTF();
}

BasicNamedAllianceInformations::BasicNamedAllianceInformations()
{
  m_types<<ClassEnum::BASICNAMEDALLIANCEINFORMATIONS;
}

bool BasicNamedAllianceInformations::operator==(const BasicNamedAllianceInformations &compared)
{
  if(allianceName == compared.allianceName)
  return true;
  
  return false;
}

