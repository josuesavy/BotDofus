#include "CharacterLevelUpInformationMessage.h"

void CharacterLevelUpInformationMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterLevelUpInformationMessage(output);
}

void CharacterLevelUpInformationMessage::serializeAs_CharacterLevelUpInformationMessage(Writer *output)
{
  CharacterLevelUpMessage::serializeAs_CharacterLevelUpMessage(output);
  output->writeUTF(this->name);
  if(this->id < 0 || this->id > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterLevelUpInformationMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarLong((double)this->id);
}

void CharacterLevelUpInformationMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterLevelUpInformationMessage(input);
}

void CharacterLevelUpInformationMessage::deserializeAs_CharacterLevelUpInformationMessage(Reader *input)
{
  CharacterLevelUpMessage::deserialize(input);
  this->_nameFunc(input);
  this->_idFunc(input);
}

void CharacterLevelUpInformationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterLevelUpInformationMessage(tree);
}

void CharacterLevelUpInformationMessage::deserializeAsyncAs_CharacterLevelUpInformationMessage(FuncTree tree)
{
  CharacterLevelUpMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&CharacterLevelUpInformationMessage::_nameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterLevelUpInformationMessage::_idFunc, this, std::placeholders::_1));
}

void CharacterLevelUpInformationMessage::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

void CharacterLevelUpInformationMessage::_idFunc(Reader *input)
{
  this->id = input->readVarUhLong();
  if(this->id < 0 || this->id > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterLevelUpInformationMessage -"<<"Forbidden value (" << this->id << ") on element of CharacterLevelUpInformationMessage.id.";
  }
}

CharacterLevelUpInformationMessage::CharacterLevelUpInformationMessage()
{
  m_type = MessageEnum::CHARACTERLEVELUPINFORMATIONMESSAGE;
}

