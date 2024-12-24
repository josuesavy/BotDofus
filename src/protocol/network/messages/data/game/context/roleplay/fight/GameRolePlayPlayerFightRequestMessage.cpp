#include "GameRolePlayPlayerFightRequestMessage.h"

void GameRolePlayPlayerFightRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayPlayerFightRequestMessage(output);
}

void GameRolePlayPlayerFightRequestMessage::serializeAs_GameRolePlayPlayerFightRequestMessage(Writer *output)
{
  if(this->targetId < 0 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightRequestMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeVarLong((double)this->targetId);
  if(this->targetCellId < -1 || this->targetCellId > 559)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightRequestMessage -"<<"Forbidden value (" << this->targetCellId << ") on element targetCellId.";
  }
  output->writeShort((short)this->targetCellId);
  output->writeBool(this->friendly);
}

void GameRolePlayPlayerFightRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayPlayerFightRequestMessage(input);
}

void GameRolePlayPlayerFightRequestMessage::deserializeAs_GameRolePlayPlayerFightRequestMessage(Reader *input)
{
  this->_targetIdFunc(input);
  this->_targetCellIdFunc(input);
  this->_friendlyFunc(input);
}

void GameRolePlayPlayerFightRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayPlayerFightRequestMessage(tree);
}

void GameRolePlayPlayerFightRequestMessage::deserializeAsyncAs_GameRolePlayPlayerFightRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayPlayerFightRequestMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayPlayerFightRequestMessage::_targetCellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayPlayerFightRequestMessage::_friendlyFunc, this, std::placeholders::_1));
}

void GameRolePlayPlayerFightRequestMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readVarUhLong();
  if(this->targetId < 0 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightRequestMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameRolePlayPlayerFightRequestMessage.targetId.";
  }
}

void GameRolePlayPlayerFightRequestMessage::_targetCellIdFunc(Reader *input)
{
  this->targetCellId = input->readShort();
  if(this->targetCellId < -1 || this->targetCellId > 559)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightRequestMessage -"<<"Forbidden value (" << this->targetCellId << ") on element of GameRolePlayPlayerFightRequestMessage.targetCellId.";
  }
}

void GameRolePlayPlayerFightRequestMessage::_friendlyFunc(Reader *input)
{
  this->friendly = input->readBool();
}

GameRolePlayPlayerFightRequestMessage::GameRolePlayPlayerFightRequestMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYPLAYERFIGHTREQUESTMESSAGE;
  m_needsHash = true;
}

