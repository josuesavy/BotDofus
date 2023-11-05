#include "CharacterCanBeCreatedResultMessage.h"

void CharacterCanBeCreatedResultMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterCanBeCreatedResultMessage(output);
}

void CharacterCanBeCreatedResultMessage::serializeAs_CharacterCanBeCreatedResultMessage(Writer *output)
{
  output->writeBool(this->yesYouCan);
}

void CharacterCanBeCreatedResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterCanBeCreatedResultMessage(input);
}

void CharacterCanBeCreatedResultMessage::deserializeAs_CharacterCanBeCreatedResultMessage(Reader *input)
{
  this->_yesYouCanFunc(input);
}

void CharacterCanBeCreatedResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterCanBeCreatedResultMessage(tree);
}

void CharacterCanBeCreatedResultMessage::deserializeAsyncAs_CharacterCanBeCreatedResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterCanBeCreatedResultMessage::_yesYouCanFunc, this, std::placeholders::_1));
}

void CharacterCanBeCreatedResultMessage::_yesYouCanFunc(Reader *input)
{
  this->yesYouCan = input->readBool();
}

CharacterCanBeCreatedResultMessage::CharacterCanBeCreatedResultMessage()
{
  m_type = MessageEnum::CHARACTERCANBECREATEDRESULTMESSAGE;
}

