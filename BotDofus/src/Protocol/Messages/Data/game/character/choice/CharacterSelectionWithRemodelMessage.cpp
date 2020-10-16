#include "CharacterSelectionWithRemodelMessage.h"

void CharacterSelectionWithRemodelMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterSelectionWithRemodelMessage(output);
}

void CharacterSelectionWithRemodelMessage::serializeAs_CharacterSelectionWithRemodelMessage(Writer *output)
{
  CharacterSelectionMessage::serializeAs_CharacterSelectionMessage(output);
  this->remodel.serializeAs_RemodelingInformation(output);
}

void CharacterSelectionWithRemodelMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterSelectionWithRemodelMessage(input);
}

void CharacterSelectionWithRemodelMessage::deserializeAs_CharacterSelectionWithRemodelMessage(Reader *input)
{
  CharacterSelectionMessage::deserialize(input);
  this->remodel = RemodelingInformation();
  this->remodel.deserialize(input);
}

void CharacterSelectionWithRemodelMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterSelectionWithRemodelMessage(tree);
}

void CharacterSelectionWithRemodelMessage::deserializeAsyncAs_CharacterSelectionWithRemodelMessage(FuncTree tree)
{
  CharacterSelectionMessage::deserializeAsync(tree);
  this->_remodeltree = tree.addChild(std::bind(&CharacterSelectionWithRemodelMessage::_remodeltreeFunc, this, std::placeholders::_1));
}

void CharacterSelectionWithRemodelMessage::_remodeltreeFunc(Reader *input)
{
  this->remodel = RemodelingInformation();
  this->remodel.deserializeAsync(this->_remodeltree);
}

CharacterSelectionWithRemodelMessage::CharacterSelectionWithRemodelMessage()
{
  m_type = MessageEnum::CHARACTERSELECTIONWITHREMODELMESSAGE;
}

