#include "JobLevelUpMessage.h"

void JobLevelUpMessage::serialize(Writer *output)
{
  this->serializeAs_JobLevelUpMessage(output);
}

void JobLevelUpMessage::serializeAs_JobLevelUpMessage(Writer *output)
{
  if(this->newLevel < 0 || this->newLevel > 255)
  {
    qDebug()<<"ERREUR - JobLevelUpMessage -"<<"Forbidden value (" << this->newLevel << ") on element newLevel.";
  }
  output->writeByte(this->newLevel);
  this->jobsDescription->serializeAs_JobDescription(output);
}

void JobLevelUpMessage::deserialize(Reader *input)
{
  this->deserializeAs_JobLevelUpMessage(input);
}

void JobLevelUpMessage::deserializeAs_JobLevelUpMessage(Reader *input)
{
  this->_newLevelFunc(input);
  this->jobsDescription = QSharedPointer<JobDescription>(new JobDescription() );
  this->jobsDescription->deserialize(input);
}

void JobLevelUpMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobLevelUpMessage(tree);
}

void JobLevelUpMessage::deserializeAsyncAs_JobLevelUpMessage(FuncTree tree)
{
  tree.addChild(std::bind(&JobLevelUpMessage::_newLevelFunc, this, std::placeholders::_1));
  this->_jobsDescriptiontree = tree.addChild(std::bind(&JobLevelUpMessage::_jobsDescriptiontreeFunc, this, std::placeholders::_1));
}

void JobLevelUpMessage::_newLevelFunc(Reader *input)
{
  this->newLevel = input->readUByte();
  if(this->newLevel < 0 || this->newLevel > 255)
  {
    qDebug()<<"ERREUR - JobLevelUpMessage -"<<"Forbidden value (" << this->newLevel << ") on element of JobLevelUpMessage.newLevel.";
  }
}

void JobLevelUpMessage::_jobsDescriptiontreeFunc(Reader *input)
{
  this->jobsDescription = QSharedPointer<JobDescription>(new JobDescription() );
  this->jobsDescription->deserializeAsync(this->_jobsDescriptiontree);
}

JobLevelUpMessage::JobLevelUpMessage()
{
  m_type = MessageEnum::JOBLEVELUPMESSAGE;
}

