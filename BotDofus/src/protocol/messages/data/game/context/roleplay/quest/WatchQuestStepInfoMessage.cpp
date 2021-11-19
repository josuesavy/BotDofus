#include "WatchQuestStepInfoMessage.h"

void WatchQuestStepInfoMessage::serialize(Writer *output)
{
  this->serializeAs_WatchQuestStepInfoMessage(output);
}

void WatchQuestStepInfoMessage::serializeAs_WatchQuestStepInfoMessage(Writer *output)
{
  QuestStepInfoMessage::serializeAs_QuestStepInfoMessage(output);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - WatchQuestStepInfoMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void WatchQuestStepInfoMessage::deserialize(Reader *input)
{
  this->deserializeAs_WatchQuestStepInfoMessage(input);
}

void WatchQuestStepInfoMessage::deserializeAs_WatchQuestStepInfoMessage(Reader *input)
{
  QuestStepInfoMessage::deserialize(input);
  this->_playerIdFunc(input);
}

void WatchQuestStepInfoMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_WatchQuestStepInfoMessage(tree);
}

void WatchQuestStepInfoMessage::deserializeAsyncAs_WatchQuestStepInfoMessage(FuncTree tree)
{
  QuestStepInfoMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&WatchQuestStepInfoMessage::_playerIdFunc, this, std::placeholders::_1));
}

void WatchQuestStepInfoMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - WatchQuestStepInfoMessage -"<<"Forbidden value (" << this->playerId << ") on element of WatchQuestStepInfoMessage.playerId.";
  }
}

WatchQuestStepInfoMessage::WatchQuestStepInfoMessage()
{
  m_type = MessageEnum::WATCHQUESTSTEPINFOMESSAGE;
}

