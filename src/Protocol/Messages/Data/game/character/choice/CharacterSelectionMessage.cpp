#include "CharacterSelectionMessage.h"

void CharacterSelectionMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterSelectionMessage(output);
}

void CharacterSelectionMessage::serializeAs_CharacterSelectionMessage(Writer *output)
{
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterSelectionMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarLong((double)this->id);
}

void CharacterSelectionMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterSelectionMessage(input);
}

void CharacterSelectionMessage::deserializeAs_CharacterSelectionMessage(Reader *input)
{
  this->_idFunc(input);
}

void CharacterSelectionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterSelectionMessage(tree);
}

void CharacterSelectionMessage::deserializeAsyncAs_CharacterSelectionMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterSelectionMessage::_idFunc, this, std::placeholders::_1));
}

void CharacterSelectionMessage::_idFunc(Reader *input)
{
  this->id = input->readVarUhLong();
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterSelectionMessage -"<<"Forbidden value (" << this->id << ") on element of CharacterSelectionMessage.id.";
  }
}

CharacterSelectionMessage::CharacterSelectionMessage()
{
  m_type = MessageEnum::CHARACTERSELECTIONMESSAGE;
}

