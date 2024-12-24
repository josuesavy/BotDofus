#include "JobExperienceOtherPlayerUpdateMessage.h"

void JobExperienceOtherPlayerUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_JobExperienceOtherPlayerUpdateMessage(output);
}

void JobExperienceOtherPlayerUpdateMessage::serializeAs_JobExperienceOtherPlayerUpdateMessage(Writer *output)
{
  JobExperienceUpdateMessage::serializeAs_JobExperienceUpdateMessage(output);
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - JobExperienceOtherPlayerUpdateMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void JobExperienceOtherPlayerUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_JobExperienceOtherPlayerUpdateMessage(input);
}

void JobExperienceOtherPlayerUpdateMessage::deserializeAs_JobExperienceOtherPlayerUpdateMessage(Reader *input)
{
  JobExperienceUpdateMessage::deserialize(input);
  this->_playerIdFunc(input);
}

void JobExperienceOtherPlayerUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobExperienceOtherPlayerUpdateMessage(tree);
}

void JobExperienceOtherPlayerUpdateMessage::deserializeAsyncAs_JobExperienceOtherPlayerUpdateMessage(FuncTree tree)
{
  JobExperienceUpdateMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&JobExperienceOtherPlayerUpdateMessage::_playerIdFunc, this, std::placeholders::_1));
}

void JobExperienceOtherPlayerUpdateMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - JobExperienceOtherPlayerUpdateMessage -"<<"Forbidden value (" << this->playerId << ") on element of JobExperienceOtherPlayerUpdateMessage.playerId.";
  }
}

JobExperienceOtherPlayerUpdateMessage::JobExperienceOtherPlayerUpdateMessage()
{
  m_type = MessageEnum::JOBEXPERIENCEOTHERPLAYERUPDATEMESSAGE;
}

