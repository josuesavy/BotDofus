#include "CharacterMinimalAllianceInformations.h"

void CharacterMinimalAllianceInformations::serialize(Writer *output)
{
  this->serializeAs_CharacterMinimalAllianceInformations(output);
}

void CharacterMinimalAllianceInformations::serializeAs_CharacterMinimalAllianceInformations(Writer *output)
{
  CharacterMinimalPlusLookInformations::serializeAs_CharacterMinimalPlusLookInformations(output);
  this->alliance->serializeAs_BasicNamedAllianceInformations(output);
}

void CharacterMinimalAllianceInformations::deserialize(Reader *input)
{
  this->deserializeAs_CharacterMinimalAllianceInformations(input);
}

void CharacterMinimalAllianceInformations::deserializeAs_CharacterMinimalAllianceInformations(Reader *input)
{
  CharacterMinimalPlusLookInformations::deserialize(input);
  this->alliance = QSharedPointer<BasicNamedAllianceInformations>(new BasicNamedAllianceInformations() );
  this->alliance->deserialize(input);
}

void CharacterMinimalAllianceInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterMinimalAllianceInformations(tree);
}

void CharacterMinimalAllianceInformations::deserializeAsyncAs_CharacterMinimalAllianceInformations(FuncTree tree)
{
  CharacterMinimalPlusLookInformations::deserializeAsync(tree);
  this->_alliancetree = tree.addChild(std::bind(&CharacterMinimalAllianceInformations::_alliancetreeFunc, this, std::placeholders::_1));
}

void CharacterMinimalAllianceInformations::_alliancetreeFunc(Reader *input)
{
  this->alliance = QSharedPointer<BasicNamedAllianceInformations>(new BasicNamedAllianceInformations() );
  this->alliance->deserializeAsync(this->_alliancetree);
}

CharacterMinimalAllianceInformations::CharacterMinimalAllianceInformations()
{
  m_types<<ClassEnum::CHARACTERMINIMALALLIANCEINFORMATIONS;
}

bool CharacterMinimalAllianceInformations::operator==(const CharacterMinimalAllianceInformations &compared)
{
  if(alliance == compared.alliance)
  if(_alliancetree == compared._alliancetree)
  return true;
  
  return false;
}

