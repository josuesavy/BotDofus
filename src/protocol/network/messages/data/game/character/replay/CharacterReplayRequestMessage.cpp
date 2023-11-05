#include "CharacterReplayRequestMessage.h"

void CharacterReplayRequestMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterReplayRequestMessage(output);
}

void CharacterReplayRequestMessage::serializeAs_CharacterReplayRequestMessage(Writer *output)
{
  if(this->characterId < 0 || this->characterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterReplayRequestMessage -"<<"Forbidden value (" << this->characterId << ") on element characterId.";
  }
  output->writeVarLong((double)this->characterId);
}

void CharacterReplayRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterReplayRequestMessage(input);
}

void CharacterReplayRequestMessage::deserializeAs_CharacterReplayRequestMessage(Reader *input)
{
  this->_characterIdFunc(input);
}

void CharacterReplayRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterReplayRequestMessage(tree);
}

void CharacterReplayRequestMessage::deserializeAsyncAs_CharacterReplayRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterReplayRequestMessage::_characterIdFunc, this, std::placeholders::_1));
}

void CharacterReplayRequestMessage::_characterIdFunc(Reader *input)
{
  this->characterId = input->readVarUhLong();
  if(this->characterId < 0 || this->characterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterReplayRequestMessage -"<<"Forbidden value (" << this->characterId << ") on element of CharacterReplayRequestMessage.characterId.";
  }
}

CharacterReplayRequestMessage::CharacterReplayRequestMessage()
{
  m_type = MessageEnum::CHARACTERREPLAYREQUESTMESSAGE;
}

