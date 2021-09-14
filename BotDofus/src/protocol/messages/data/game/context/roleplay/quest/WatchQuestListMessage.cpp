#include "WatchQuestListMessage.h"

void WatchQuestListMessage::serialize(Writer *output)
{
  this->serializeAs_WatchQuestListMessage(output);
}

void WatchQuestListMessage::serializeAs_WatchQuestListMessage(Writer *output)
{
  QuestListMessage::serializeAs_QuestListMessage(output);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - WatchQuestListMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void WatchQuestListMessage::deserialize(Reader *input)
{
  this->deserializeAs_WatchQuestListMessage(input);
}

void WatchQuestListMessage::deserializeAs_WatchQuestListMessage(Reader *input)
{
  QuestListMessage::deserialize(input);
  this->_playerIdFunc(input);
}

void WatchQuestListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_WatchQuestListMessage(tree);
}

void WatchQuestListMessage::deserializeAsyncAs_WatchQuestListMessage(FuncTree tree)
{
  QuestListMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&WatchQuestListMessage::_playerIdFunc, this, std::placeholders::_1));
}

void WatchQuestListMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - WatchQuestListMessage -"<<"Forbidden value (" << this->playerId << ") on element of WatchQuestListMessage.playerId.";
  }
}

WatchQuestListMessage::WatchQuestListMessage()
{
  m_type = MessageEnum::WATCHQUESTLISTMESSAGE;
}

