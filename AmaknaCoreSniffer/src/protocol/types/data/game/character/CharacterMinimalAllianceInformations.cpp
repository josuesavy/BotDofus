#include "CharacterMinimalAllianceInformations.h"

void CharacterMinimalAllianceInformations::serialize(Writer *output)
{
  this->serializeAs_CharacterMinimalAllianceInformations(output);
}

void CharacterMinimalAllianceInformations::serializeAs_CharacterMinimalAllianceInformations(Writer *output)
{
  CharacterMinimalGuildInformations::serializeAs_CharacterMinimalGuildInformations(output);
  this->alliance->serializeAs_BasicAllianceInformations(output);
}

void CharacterMinimalAllianceInformations::deserialize(Reader *input)
{
  this->deserializeAs_CharacterMinimalAllianceInformations(input);
}

void CharacterMinimalAllianceInformations::deserializeAs_CharacterMinimalAllianceInformations(Reader *input)
{
  CharacterMinimalGuildInformations::deserialize(input);
  this->alliance = QSharedPointer<BasicAllianceInformations>(new BasicAllianceInformations() );
  this->alliance->deserialize(input);
}

void CharacterMinimalAllianceInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterMinimalAllianceInformations(tree);
}

void CharacterMinimalAllianceInformations::deserializeAsyncAs_CharacterMinimalAllianceInformations(FuncTree tree)
{
  CharacterMinimalGuildInformations::deserializeAsync(tree);
  this->_alliancetree = tree.addChild(std::bind(&CharacterMinimalAllianceInformations::_alliancetreeFunc, this, std::placeholders::_1));
}

void CharacterMinimalAllianceInformations::_alliancetreeFunc(Reader *input)
{
  this->alliance = QSharedPointer<BasicAllianceInformations>(new BasicAllianceInformations() );
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

