#include "CharacterNameSuggestionFailureMessage.h"

void CharacterNameSuggestionFailureMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterNameSuggestionFailureMessage(output);
}

void CharacterNameSuggestionFailureMessage::serializeAs_CharacterNameSuggestionFailureMessage(Writer *output)
{
  output->writeByte(this->reason);
}

void CharacterNameSuggestionFailureMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterNameSuggestionFailureMessage(input);
}

void CharacterNameSuggestionFailureMessage::deserializeAs_CharacterNameSuggestionFailureMessage(Reader *input)
{
  this->_reasonFunc(input);
}

void CharacterNameSuggestionFailureMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterNameSuggestionFailureMessage(tree);
}

void CharacterNameSuggestionFailureMessage::deserializeAsyncAs_CharacterNameSuggestionFailureMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterNameSuggestionFailureMessage::_reasonFunc, this, std::placeholders::_1));
}

void CharacterNameSuggestionFailureMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - CharacterNameSuggestionFailureMessage -"<<"Forbidden value (" << this->reason << ") on element of CharacterNameSuggestionFailureMessage.reason.";
  }
}

CharacterNameSuggestionFailureMessage::CharacterNameSuggestionFailureMessage()
{
  m_type = MessageEnum::CHARACTERNAMESUGGESTIONFAILUREMESSAGE;
}

