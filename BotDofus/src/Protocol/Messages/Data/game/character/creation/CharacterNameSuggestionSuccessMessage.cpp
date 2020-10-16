#include "CharacterNameSuggestionSuccessMessage.h"

void CharacterNameSuggestionSuccessMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterNameSuggestionSuccessMessage(output);
}

void CharacterNameSuggestionSuccessMessage::serializeAs_CharacterNameSuggestionSuccessMessage(Writer *output)
{
  output->writeUTF(this->suggestion);
}

void CharacterNameSuggestionSuccessMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterNameSuggestionSuccessMessage(input);
}

void CharacterNameSuggestionSuccessMessage::deserializeAs_CharacterNameSuggestionSuccessMessage(Reader *input)
{
  this->_suggestionFunc(input);
}

void CharacterNameSuggestionSuccessMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterNameSuggestionSuccessMessage(tree);
}

void CharacterNameSuggestionSuccessMessage::deserializeAsyncAs_CharacterNameSuggestionSuccessMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterNameSuggestionSuccessMessage::_suggestionFunc, this, std::placeholders::_1));
}

void CharacterNameSuggestionSuccessMessage::_suggestionFunc(Reader *input)
{
  this->suggestion = input->readUTF();
}

CharacterNameSuggestionSuccessMessage::CharacterNameSuggestionSuccessMessage()
{
  m_type = MessageEnum::CHARACTERNAMESUGGESTIONSUCCESSMESSAGE;
}

