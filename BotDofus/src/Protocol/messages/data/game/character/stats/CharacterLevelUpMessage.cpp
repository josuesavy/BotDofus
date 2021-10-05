#include "CharacterLevelUpMessage.h"

void CharacterLevelUpMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterLevelUpMessage(output);
}

void CharacterLevelUpMessage::serializeAs_CharacterLevelUpMessage(Writer *output)
{
  if(this->newLevel < 0)
  {
    qDebug()<<"ERREUR - CharacterLevelUpMessage -"<<"Forbidden value (" << this->newLevel << ") on element newLevel.";
  }
  output->writeVarShort((int)this->newLevel);
}

void CharacterLevelUpMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterLevelUpMessage(input);
}

void CharacterLevelUpMessage::deserializeAs_CharacterLevelUpMessage(Reader *input)
{
  this->_newLevelFunc(input);
}

void CharacterLevelUpMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterLevelUpMessage(tree);
}

void CharacterLevelUpMessage::deserializeAsyncAs_CharacterLevelUpMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterLevelUpMessage::_newLevelFunc, this, std::placeholders::_1));
}

void CharacterLevelUpMessage::_newLevelFunc(Reader *input)
{
  this->newLevel = input->readVarUhShort();
  if(this->newLevel < 0)
  {
    qDebug()<<"ERREUR - CharacterLevelUpMessage -"<<"Forbidden value (" << this->newLevel << ") on element of CharacterLevelUpMessage.newLevel.";
  }
}

CharacterLevelUpMessage::CharacterLevelUpMessage()
{
  m_type = MessageEnum::CHARACTERLEVELUPMESSAGE;
}

