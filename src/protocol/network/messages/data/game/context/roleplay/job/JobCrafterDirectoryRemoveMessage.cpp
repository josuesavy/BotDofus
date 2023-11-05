#include "JobCrafterDirectoryRemoveMessage.h"

void JobCrafterDirectoryRemoveMessage::serialize(Writer *output)
{
  this->serializeAs_JobCrafterDirectoryRemoveMessage(output);
}

void JobCrafterDirectoryRemoveMessage::serializeAs_JobCrafterDirectoryRemoveMessage(Writer *output)
{
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryRemoveMessage -"<<"Forbidden value (" << this->jobId << ") on element jobId.";
  }
  output->writeByte(this->jobId);
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryRemoveMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void JobCrafterDirectoryRemoveMessage::deserialize(Reader *input)
{
  this->deserializeAs_JobCrafterDirectoryRemoveMessage(input);
}

void JobCrafterDirectoryRemoveMessage::deserializeAs_JobCrafterDirectoryRemoveMessage(Reader *input)
{
  this->_jobIdFunc(input);
  this->_playerIdFunc(input);
}

void JobCrafterDirectoryRemoveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobCrafterDirectoryRemoveMessage(tree);
}

void JobCrafterDirectoryRemoveMessage::deserializeAsyncAs_JobCrafterDirectoryRemoveMessage(FuncTree tree)
{
  tree.addChild(std::bind(&JobCrafterDirectoryRemoveMessage::_jobIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobCrafterDirectoryRemoveMessage::_playerIdFunc, this, std::placeholders::_1));
}

void JobCrafterDirectoryRemoveMessage::_jobIdFunc(Reader *input)
{
  this->jobId = input->readByte();
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryRemoveMessage -"<<"Forbidden value (" << this->jobId << ") on element of JobCrafterDirectoryRemoveMessage.jobId.";
  }
}

void JobCrafterDirectoryRemoveMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryRemoveMessage -"<<"Forbidden value (" << this->playerId << ") on element of JobCrafterDirectoryRemoveMessage.playerId.";
  }
}

JobCrafterDirectoryRemoveMessage::JobCrafterDirectoryRemoveMessage()
{
  m_type = MessageEnum::JOBCRAFTERDIRECTORYREMOVEMESSAGE;
}

