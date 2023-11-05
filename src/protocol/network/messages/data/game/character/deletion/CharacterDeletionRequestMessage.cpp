#include "CharacterDeletionRequestMessage.h"

void CharacterDeletionRequestMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterDeletionRequestMessage(output);
}

void CharacterDeletionRequestMessage::serializeAs_CharacterDeletionRequestMessage(Writer *output)
{
  if(this->characterId < 0 || this->characterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterDeletionRequestMessage -"<<"Forbidden value (" << this->characterId << ") on element characterId.";
  }
  output->writeVarLong((double)this->characterId);
  output->writeUTF(this->secretAnswerHash);
}

void CharacterDeletionRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterDeletionRequestMessage(input);
}

void CharacterDeletionRequestMessage::deserializeAs_CharacterDeletionRequestMessage(Reader *input)
{
  this->_characterIdFunc(input);
  this->_secretAnswerHashFunc(input);
}

void CharacterDeletionRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterDeletionRequestMessage(tree);
}

void CharacterDeletionRequestMessage::deserializeAsyncAs_CharacterDeletionRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterDeletionRequestMessage::_characterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterDeletionRequestMessage::_secretAnswerHashFunc, this, std::placeholders::_1));
}

void CharacterDeletionRequestMessage::_characterIdFunc(Reader *input)
{
  this->characterId = input->readVarUhLong();
  if(this->characterId < 0 || this->characterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterDeletionRequestMessage -"<<"Forbidden value (" << this->characterId << ") on element of CharacterDeletionRequestMessage.characterId.";
  }
}

void CharacterDeletionRequestMessage::_secretAnswerHashFunc(Reader *input)
{
  this->secretAnswerHash = input->readUTF();
}

CharacterDeletionRequestMessage::CharacterDeletionRequestMessage()
{
  m_type = MessageEnum::CHARACTERDELETIONREQUESTMESSAGE;
}

