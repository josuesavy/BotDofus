#include "CharacterCreationResultMessage.h"

void CharacterCreationResultMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterCreationResultMessage(output);
}

void CharacterCreationResultMessage::serializeAs_CharacterCreationResultMessage(Writer *output)
{
  output->writeByte(this->result);
  output->writeByte(this->reason);
}

void CharacterCreationResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterCreationResultMessage(input);
}

void CharacterCreationResultMessage::deserializeAs_CharacterCreationResultMessage(Reader *input)
{
  this->_resultFunc(input);
  this->_reasonFunc(input);
}

void CharacterCreationResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterCreationResultMessage(tree);
}

void CharacterCreationResultMessage::deserializeAsyncAs_CharacterCreationResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterCreationResultMessage::_resultFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCreationResultMessage::_reasonFunc, this, std::placeholders::_1));
}

void CharacterCreationResultMessage::_resultFunc(Reader *input)
{
  this->result = input->readByte();
  if(this->result < 0)
  {
    qDebug()<<"ERREUR - CharacterCreationResultMessage -"<<"Forbidden value (" << this->result << ") on element of CharacterCreationResultMessage.result.";
  }
}

void CharacterCreationResultMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - CharacterCreationResultMessage -"<<"Forbidden value (" << this->reason << ") on element of CharacterCreationResultMessage.reason.";
  }
}

CharacterCreationResultMessage::CharacterCreationResultMessage()
{
  m_type = MessageEnum::CHARACTERCREATIONRESULTMESSAGE;
}

