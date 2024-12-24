#include "WatchQuestStepInfoRequestMessage.h"

void WatchQuestStepInfoRequestMessage::serialize(Writer *output)
{
  this->serializeAs_WatchQuestStepInfoRequestMessage(output);
}

void WatchQuestStepInfoRequestMessage::serializeAs_WatchQuestStepInfoRequestMessage(Writer *output)
{
  QuestStepInfoRequestMessage::serializeAs_QuestStepInfoRequestMessage(output);
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - WatchQuestStepInfoRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void WatchQuestStepInfoRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_WatchQuestStepInfoRequestMessage(input);
}

void WatchQuestStepInfoRequestMessage::deserializeAs_WatchQuestStepInfoRequestMessage(Reader *input)
{
  QuestStepInfoRequestMessage::deserialize(input);
  this->_playerIdFunc(input);
}

void WatchQuestStepInfoRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_WatchQuestStepInfoRequestMessage(tree);
}

void WatchQuestStepInfoRequestMessage::deserializeAsyncAs_WatchQuestStepInfoRequestMessage(FuncTree tree)
{
  QuestStepInfoRequestMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&WatchQuestStepInfoRequestMessage::_playerIdFunc, this, std::placeholders::_1));
}

void WatchQuestStepInfoRequestMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - WatchQuestStepInfoRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element of WatchQuestStepInfoRequestMessage.playerId.";
  }
}

WatchQuestStepInfoRequestMessage::WatchQuestStepInfoRequestMessage()
{
  m_type = MessageEnum::WATCHQUESTSTEPINFOREQUESTMESSAGE;
}

