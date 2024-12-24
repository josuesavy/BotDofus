#include "CharacterDeletionPrepareRequestMessage.h"

void CharacterDeletionPrepareRequestMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterDeletionPrepareRequestMessage(output);
}

void CharacterDeletionPrepareRequestMessage::serializeAs_CharacterDeletionPrepareRequestMessage(Writer *output)
{
  if(this->characterId < 0 || this->characterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterDeletionPrepareRequestMessage -"<<"Forbidden value (" << this->characterId << ") on element characterId.";
  }
  output->writeVarLong((double)this->characterId);
}

void CharacterDeletionPrepareRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterDeletionPrepareRequestMessage(input);
}

void CharacterDeletionPrepareRequestMessage::deserializeAs_CharacterDeletionPrepareRequestMessage(Reader *input)
{
  this->_characterIdFunc(input);
}

void CharacterDeletionPrepareRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterDeletionPrepareRequestMessage(tree);
}

void CharacterDeletionPrepareRequestMessage::deserializeAsyncAs_CharacterDeletionPrepareRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterDeletionPrepareRequestMessage::_characterIdFunc, this, std::placeholders::_1));
}

void CharacterDeletionPrepareRequestMessage::_characterIdFunc(Reader *input)
{
  this->characterId = input->readVarUhLong();
  if(this->characterId < 0 || this->characterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterDeletionPrepareRequestMessage -"<<"Forbidden value (" << this->characterId << ") on element of CharacterDeletionPrepareRequestMessage.characterId.";
  }
}

CharacterDeletionPrepareRequestMessage::CharacterDeletionPrepareRequestMessage()
{
  m_type = MessageEnum::CHARACTERDELETIONPREPAREREQUESTMESSAGE;
}

