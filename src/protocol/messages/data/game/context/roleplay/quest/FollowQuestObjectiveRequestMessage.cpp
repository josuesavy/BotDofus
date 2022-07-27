#include "FollowQuestObjectiveRequestMessage.h"

void FollowQuestObjectiveRequestMessage::serialize(Writer *output)
{
  this->serializeAs_FollowQuestObjectiveRequestMessage(output);
}

void FollowQuestObjectiveRequestMessage::serializeAs_FollowQuestObjectiveRequestMessage(Writer *output)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - FollowQuestObjectiveRequestMessage -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  output->writeVarShort((int)this->questId);
  output->writeShort((short)this->objectiveId);
}

void FollowQuestObjectiveRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_FollowQuestObjectiveRequestMessage(input);
}

void FollowQuestObjectiveRequestMessage::deserializeAs_FollowQuestObjectiveRequestMessage(Reader *input)
{
  this->_questIdFunc(input);
  this->_objectiveIdFunc(input);
}

void FollowQuestObjectiveRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FollowQuestObjectiveRequestMessage(tree);
}

void FollowQuestObjectiveRequestMessage::deserializeAsyncAs_FollowQuestObjectiveRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&FollowQuestObjectiveRequestMessage::_questIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FollowQuestObjectiveRequestMessage::_objectiveIdFunc, this, std::placeholders::_1));
}

void FollowQuestObjectiveRequestMessage::_questIdFunc(Reader *input)
{
  this->questId = input->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - FollowQuestObjectiveRequestMessage -"<<"Forbidden value (" << this->questId << ") on element of FollowQuestObjectiveRequestMessage.questId.";
  }
}

void FollowQuestObjectiveRequestMessage::_objectiveIdFunc(Reader *input)
{
  this->objectiveId = input->readShort();
}

FollowQuestObjectiveRequestMessage::FollowQuestObjectiveRequestMessage()
{
  m_type = MessageEnum::FOLLOWQUESTOBJECTIVEREQUESTMESSAGE;
}

