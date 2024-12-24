#include "CharacterSelectedForceMessage.h"

void CharacterSelectedForceMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterSelectedForceMessage(output);
}

void CharacterSelectedForceMessage::serializeAs_CharacterSelectedForceMessage(Writer *output)
{
  if(this->id < 1 || this->id > 2147483647)
  {
    qDebug()<<"ERREUR - CharacterSelectedForceMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeInt((int)this->id);
}

void CharacterSelectedForceMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterSelectedForceMessage(input);
}

void CharacterSelectedForceMessage::deserializeAs_CharacterSelectedForceMessage(Reader *input)
{
  this->_idFunc(input);
}

void CharacterSelectedForceMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterSelectedForceMessage(tree);
}

void CharacterSelectedForceMessage::deserializeAsyncAs_CharacterSelectedForceMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterSelectedForceMessage::_idFunc, this, std::placeholders::_1));
}

void CharacterSelectedForceMessage::_idFunc(Reader *input)
{
  this->id = input->readInt();
  if(this->id < 1 || this->id > 2147483647)
  {
    qDebug()<<"ERREUR - CharacterSelectedForceMessage -"<<"Forbidden value (" << this->id << ") on element of CharacterSelectedForceMessage.id.";
  }
}

CharacterSelectedForceMessage::CharacterSelectedForceMessage()
{
  m_type = MessageEnum::CHARACTERSELECTEDFORCEMESSAGE;
}

