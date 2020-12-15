#include "CharactersListMessage.h"

void CharactersListMessage::serialize(Writer *output)
{
  this->serializeAs_CharactersListMessage(output);
}

void CharactersListMessage::serializeAs_CharactersListMessage(Writer *output)
{
  BasicCharactersListMessage::serializeAs_BasicCharactersListMessage(output);
  output->writeBool(this->hasStartupActions);
}

void CharactersListMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharactersListMessage(input);
}

void CharactersListMessage::deserializeAs_CharactersListMessage(Reader *input)
{
  BasicCharactersListMessage::deserialize(input);
  this->_hasStartupActionsFunc(input);
}

void CharactersListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharactersListMessage(tree);
}

void CharactersListMessage::deserializeAsyncAs_CharactersListMessage(FuncTree tree)
{
  BasicCharactersListMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&CharactersListMessage::_hasStartupActionsFunc, this, std::placeholders::_1));
}

void CharactersListMessage::_hasStartupActionsFunc(Reader *input)
{
  this->hasStartupActions = input->readBool();
}

CharactersListMessage::CharactersListMessage()
{
  m_type = MessageEnum::CHARACTERSLISTMESSAGE;
}

