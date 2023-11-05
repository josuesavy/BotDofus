#include "CharacterDeletionPrepareMessage.h"

void CharacterDeletionPrepareMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterDeletionPrepareMessage(output);
}

void CharacterDeletionPrepareMessage::serializeAs_CharacterDeletionPrepareMessage(Writer *output)
{
  if(this->characterId < 0 || this->characterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterDeletionPrepareMessage -"<<"Forbidden value (" << this->characterId << ") on element characterId.";
  }
  output->writeVarLong((double)this->characterId);
  output->writeUTF(this->characterName);
  output->writeUTF(this->secretQuestion);
  output->writeBool(this->needSecretAnswer);
}

void CharacterDeletionPrepareMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterDeletionPrepareMessage(input);
}

void CharacterDeletionPrepareMessage::deserializeAs_CharacterDeletionPrepareMessage(Reader *input)
{
  this->_characterIdFunc(input);
  this->_characterNameFunc(input);
  this->_secretQuestionFunc(input);
  this->_needSecretAnswerFunc(input);
}

void CharacterDeletionPrepareMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterDeletionPrepareMessage(tree);
}

void CharacterDeletionPrepareMessage::deserializeAsyncAs_CharacterDeletionPrepareMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterDeletionPrepareMessage::_characterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterDeletionPrepareMessage::_characterNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterDeletionPrepareMessage::_secretQuestionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterDeletionPrepareMessage::_needSecretAnswerFunc, this, std::placeholders::_1));
}

void CharacterDeletionPrepareMessage::_characterIdFunc(Reader *input)
{
  this->characterId = input->readVarUhLong();
  if(this->characterId < 0 || this->characterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterDeletionPrepareMessage -"<<"Forbidden value (" << this->characterId << ") on element of CharacterDeletionPrepareMessage.characterId.";
  }
}

void CharacterDeletionPrepareMessage::_characterNameFunc(Reader *input)
{
  this->characterName = input->readUTF();
}

void CharacterDeletionPrepareMessage::_secretQuestionFunc(Reader *input)
{
  this->secretQuestion = input->readUTF();
}

void CharacterDeletionPrepareMessage::_needSecretAnswerFunc(Reader *input)
{
  this->needSecretAnswer = input->readBool();
}

CharacterDeletionPrepareMessage::CharacterDeletionPrepareMessage()
{
  m_type = MessageEnum::CHARACTERDELETIONPREPAREMESSAGE;
}

