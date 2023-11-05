#include "GameRolePlayPlayerLifeStatusMessage.h"

void GameRolePlayPlayerLifeStatusMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayPlayerLifeStatusMessage(output);
}

void GameRolePlayPlayerLifeStatusMessage::serializeAs_GameRolePlayPlayerLifeStatusMessage(Writer *output)
{
  output->writeByte(this->state);
  if(this->phenixMapId < 0 || this->phenixMapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerLifeStatusMessage -"<<"Forbidden value (" << this->phenixMapId << ") on element phenixMapId.";
  }
  output->writeDouble(this->phenixMapId);
}

void GameRolePlayPlayerLifeStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayPlayerLifeStatusMessage(input);
}

void GameRolePlayPlayerLifeStatusMessage::deserializeAs_GameRolePlayPlayerLifeStatusMessage(Reader *input)
{
  this->_stateFunc(input);
  this->_phenixMapIdFunc(input);
}

void GameRolePlayPlayerLifeStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayPlayerLifeStatusMessage(tree);
}

void GameRolePlayPlayerLifeStatusMessage::deserializeAsyncAs_GameRolePlayPlayerLifeStatusMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayPlayerLifeStatusMessage::_stateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayPlayerLifeStatusMessage::_phenixMapIdFunc, this, std::placeholders::_1));
}

void GameRolePlayPlayerLifeStatusMessage::_stateFunc(Reader *input)
{
  this->state = input->readByte();
  if(this->state < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerLifeStatusMessage -"<<"Forbidden value (" << this->state << ") on element of GameRolePlayPlayerLifeStatusMessage.state.";
  }
}

void GameRolePlayPlayerLifeStatusMessage::_phenixMapIdFunc(Reader *input)
{
  this->phenixMapId = input->readDouble();
  if(this->phenixMapId < 0 || this->phenixMapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerLifeStatusMessage -"<<"Forbidden value (" << this->phenixMapId << ") on element of GameRolePlayPlayerLifeStatusMessage.phenixMapId.";
  }
}

GameRolePlayPlayerLifeStatusMessage::GameRolePlayPlayerLifeStatusMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYPLAYERLIFESTATUSMESSAGE;
}

