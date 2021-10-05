#include "GameRolePlayFightRequestCanceledMessage.h"

void GameRolePlayFightRequestCanceledMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayFightRequestCanceledMessage(output);
}

void GameRolePlayFightRequestCanceledMessage::serializeAs_GameRolePlayFightRequestCanceledMessage(Writer *output)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayFightRequestCanceledMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  if(this->sourceId < -9.007199254740992E15 || this->sourceId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayFightRequestCanceledMessage -"<<"Forbidden value (" << this->sourceId << ") on element sourceId.";
  }
  output->writeDouble(this->sourceId);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayFightRequestCanceledMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
}

void GameRolePlayFightRequestCanceledMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayFightRequestCanceledMessage(input);
}

void GameRolePlayFightRequestCanceledMessage::deserializeAs_GameRolePlayFightRequestCanceledMessage(Reader *input)
{
  this->_fightIdFunc(input);
  this->_sourceIdFunc(input);
  this->_targetIdFunc(input);
}

void GameRolePlayFightRequestCanceledMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayFightRequestCanceledMessage(tree);
}

void GameRolePlayFightRequestCanceledMessage::deserializeAsyncAs_GameRolePlayFightRequestCanceledMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayFightRequestCanceledMessage::_fightIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayFightRequestCanceledMessage::_sourceIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayFightRequestCanceledMessage::_targetIdFunc, this, std::placeholders::_1));
}

void GameRolePlayFightRequestCanceledMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayFightRequestCanceledMessage -"<<"Forbidden value (" << this->fightId << ") on element of GameRolePlayFightRequestCanceledMessage.fightId.";
  }
}

void GameRolePlayFightRequestCanceledMessage::_sourceIdFunc(Reader *input)
{
  this->sourceId = input->readDouble();
  if(this->sourceId < -9.007199254740992E15 || this->sourceId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayFightRequestCanceledMessage -"<<"Forbidden value (" << this->sourceId << ") on element of GameRolePlayFightRequestCanceledMessage.sourceId.";
  }
}

void GameRolePlayFightRequestCanceledMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayFightRequestCanceledMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameRolePlayFightRequestCanceledMessage.targetId.";
  }
}

GameRolePlayFightRequestCanceledMessage::GameRolePlayFightRequestCanceledMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYFIGHTREQUESTCANCELEDMESSAGE;
}

