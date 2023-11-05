#include "CharacterSelectedSuccessMessage.h"

void CharacterSelectedSuccessMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterSelectedSuccessMessage(output);
}

void CharacterSelectedSuccessMessage::serializeAs_CharacterSelectedSuccessMessage(Writer *output)
{
  this->infos->serializeAs_CharacterBaseInformations(output);
  output->writeBool(this->isCollectingStats);
}

void CharacterSelectedSuccessMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterSelectedSuccessMessage(input);
}

void CharacterSelectedSuccessMessage::deserializeAs_CharacterSelectedSuccessMessage(Reader *input)
{
  this->infos = QSharedPointer<CharacterBaseInformations>(new CharacterBaseInformations() );
  this->infos->deserialize(input);
  this->_isCollectingStatsFunc(input);
}

void CharacterSelectedSuccessMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterSelectedSuccessMessage(tree);
}

void CharacterSelectedSuccessMessage::deserializeAsyncAs_CharacterSelectedSuccessMessage(FuncTree tree)
{
  this->_infostree = tree.addChild(std::bind(&CharacterSelectedSuccessMessage::_infostreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterSelectedSuccessMessage::_isCollectingStatsFunc, this, std::placeholders::_1));
}

void CharacterSelectedSuccessMessage::_infostreeFunc(Reader *input)
{
  this->infos = QSharedPointer<CharacterBaseInformations>(new CharacterBaseInformations() );
  this->infos->deserializeAsync(this->_infostree);
}

void CharacterSelectedSuccessMessage::_isCollectingStatsFunc(Reader *input)
{
  this->isCollectingStats = input->readBool();
}

CharacterSelectedSuccessMessage::CharacterSelectedSuccessMessage()
{
  m_type = MessageEnum::CHARACTERSELECTEDSUCCESSMESSAGE;
}

