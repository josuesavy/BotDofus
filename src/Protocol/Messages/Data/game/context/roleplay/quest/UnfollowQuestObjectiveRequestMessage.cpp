#include "UnfollowQuestObjectiveRequestMessage.h"

void UnfollowQuestObjectiveRequestMessage::serialize(Writer *output)
{
  this->serializeAs_UnfollowQuestObjectiveRequestMessage(output);
}

void UnfollowQuestObjectiveRequestMessage::serializeAs_UnfollowQuestObjectiveRequestMessage(Writer *output)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - UnfollowQuestObjectiveRequestMessage -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  output->writeVarShort((int)this->questId);
  output->writeShort((short)this->objectiveId);
}

void UnfollowQuestObjectiveRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_UnfollowQuestObjectiveRequestMessage(input);
}

void UnfollowQuestObjectiveRequestMessage::deserializeAs_UnfollowQuestObjectiveRequestMessage(Reader *input)
{
  this->_questIdFunc(input);
  this->_objectiveIdFunc(input);
}

void UnfollowQuestObjectiveRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_UnfollowQuestObjectiveRequestMessage(tree);
}

void UnfollowQuestObjectiveRequestMessage::deserializeAsyncAs_UnfollowQuestObjectiveRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&UnfollowQuestObjectiveRequestMessage::_questIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&UnfollowQuestObjectiveRequestMessage::_objectiveIdFunc, this, std::placeholders::_1));
}

void UnfollowQuestObjectiveRequestMessage::_questIdFunc(Reader *input)
{
  this->questId = input->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - UnfollowQuestObjectiveRequestMessage -"<<"Forbidden value (" << this->questId << ") on element of UnfollowQuestObjectiveRequestMessage.questId.";
  }
}

void UnfollowQuestObjectiveRequestMessage::_objectiveIdFunc(Reader *input)
{
  this->objectiveId = input->readShort();
}

UnfollowQuestObjectiveRequestMessage::UnfollowQuestObjectiveRequestMessage()
{
  m_type = MessageEnum::UNFOLLOWQUESTOBJECTIVEREQUESTMESSAGE;
}

