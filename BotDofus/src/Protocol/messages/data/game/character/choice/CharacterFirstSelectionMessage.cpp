#include "CharacterFirstSelectionMessage.h"

void CharacterFirstSelectionMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterFirstSelectionMessage(output);
}

void CharacterFirstSelectionMessage::serializeAs_CharacterFirstSelectionMessage(Writer *output)
{
  CharacterSelectionMessage::serializeAs_CharacterSelectionMessage(output);
  output->writeBool(this->doTutorial);
}

void CharacterFirstSelectionMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterFirstSelectionMessage(input);
}

void CharacterFirstSelectionMessage::deserializeAs_CharacterFirstSelectionMessage(Reader *input)
{
  CharacterSelectionMessage::deserialize(input);
  this->_doTutorialFunc(input);
}

void CharacterFirstSelectionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterFirstSelectionMessage(tree);
}

void CharacterFirstSelectionMessage::deserializeAsyncAs_CharacterFirstSelectionMessage(FuncTree tree)
{
  CharacterSelectionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&CharacterFirstSelectionMessage::_doTutorialFunc, this, std::placeholders::_1));
}

void CharacterFirstSelectionMessage::_doTutorialFunc(Reader *input)
{
  this->doTutorial = input->readBool();
}

CharacterFirstSelectionMessage::CharacterFirstSelectionMessage()
{
  m_type = MessageEnum::CHARACTERFIRSTSELECTIONMESSAGE;
}

