#include "GameContextKickMessage.h"

void GameContextKickMessage::serialize(Writer *output)
{
  this->serializeAs_GameContextKickMessage(output);
}

void GameContextKickMessage::serializeAs_GameContextKickMessage(Writer *output)
{
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameContextKickMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
}

void GameContextKickMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameContextKickMessage(input);
}

void GameContextKickMessage::deserializeAs_GameContextKickMessage(Reader *input)
{
  this->_targetIdFunc(input);
}

void GameContextKickMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameContextKickMessage(tree);
}

void GameContextKickMessage::deserializeAsyncAs_GameContextKickMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameContextKickMessage::_targetIdFunc, this, std::placeholders::_1));
}

void GameContextKickMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameContextKickMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameContextKickMessage.targetId.";
  }
}

GameContextKickMessage::GameContextKickMessage()
{
  m_type = MessageEnum::GAMECONTEXTKICKMESSAGE;
}

