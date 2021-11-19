#include "GameFightLeaveMessage.h"

void GameFightLeaveMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightLeaveMessage(output);
}

void GameFightLeaveMessage::serializeAs_GameFightLeaveMessage(Writer *output)
{
  if(this->charId < -9.007199254740992E15 || this->charId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightLeaveMessage -"<<"Forbidden value (" << this->charId << ") on element charId.";
  }
  output->writeDouble(this->charId);
}

void GameFightLeaveMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightLeaveMessage(input);
}

void GameFightLeaveMessage::deserializeAs_GameFightLeaveMessage(Reader *input)
{
  this->_charIdFunc(input);
}

void GameFightLeaveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightLeaveMessage(tree);
}

void GameFightLeaveMessage::deserializeAsyncAs_GameFightLeaveMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightLeaveMessage::_charIdFunc, this, std::placeholders::_1));
}

void GameFightLeaveMessage::_charIdFunc(Reader *input)
{
  this->charId = input->readDouble();
  if(this->charId < -9.007199254740992E15 || this->charId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightLeaveMessage -"<<"Forbidden value (" << this->charId << ") on element of GameFightLeaveMessage.charId.";
  }
}

GameFightLeaveMessage::GameFightLeaveMessage()
{
  m_type = MessageEnum::GAMEFIGHTLEAVEMESSAGE;
}

