#include "CharacterDeletionErrorMessage.h"

void CharacterDeletionErrorMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterDeletionErrorMessage(output);
}

void CharacterDeletionErrorMessage::serializeAs_CharacterDeletionErrorMessage(Writer *output)
{
  output->writeByte(this->reason);
}

void CharacterDeletionErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterDeletionErrorMessage(input);
}

void CharacterDeletionErrorMessage::deserializeAs_CharacterDeletionErrorMessage(Reader *input)
{
  this->_reasonFunc(input);
}

void CharacterDeletionErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterDeletionErrorMessage(tree);
}

void CharacterDeletionErrorMessage::deserializeAsyncAs_CharacterDeletionErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterDeletionErrorMessage::_reasonFunc, this, std::placeholders::_1));
}

void CharacterDeletionErrorMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - CharacterDeletionErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of CharacterDeletionErrorMessage.reason.";
  }
}

CharacterDeletionErrorMessage::CharacterDeletionErrorMessage()
{
  m_type = MessageEnum::CHARACTERDELETIONERRORMESSAGE;
}

