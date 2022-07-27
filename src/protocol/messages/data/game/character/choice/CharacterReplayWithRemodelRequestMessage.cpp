#include "CharacterReplayWithRemodelRequestMessage.h"

void CharacterReplayWithRemodelRequestMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterReplayWithRemodelRequestMessage(output);
}

void CharacterReplayWithRemodelRequestMessage::serializeAs_CharacterReplayWithRemodelRequestMessage(Writer *output)
{
  CharacterReplayRequestMessage::serializeAs_CharacterReplayRequestMessage(output);
  this->remodel.serializeAs_RemodelingInformation(output);
}

void CharacterReplayWithRemodelRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterReplayWithRemodelRequestMessage(input);
}

void CharacterReplayWithRemodelRequestMessage::deserializeAs_CharacterReplayWithRemodelRequestMessage(Reader *input)
{
  CharacterReplayRequestMessage::deserialize(input);
  this->remodel = RemodelingInformation();
  this->remodel.deserialize(input);
}

void CharacterReplayWithRemodelRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterReplayWithRemodelRequestMessage(tree);
}

void CharacterReplayWithRemodelRequestMessage::deserializeAsyncAs_CharacterReplayWithRemodelRequestMessage(FuncTree tree)
{
  CharacterReplayRequestMessage::deserializeAsync(tree);
  this->_remodeltree = tree.addChild(std::bind(&CharacterReplayWithRemodelRequestMessage::_remodeltreeFunc, this, std::placeholders::_1));
}

void CharacterReplayWithRemodelRequestMessage::_remodeltreeFunc(Reader *input)
{
  this->remodel = RemodelingInformation();
  this->remodel.deserializeAsync(this->_remodeltree);
}

CharacterReplayWithRemodelRequestMessage::CharacterReplayWithRemodelRequestMessage()
{
  m_type = MessageEnum::CHARACTERREPLAYWITHREMODELREQUESTMESSAGE;
}

