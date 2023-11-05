#include "JobCrafterDirectoryEntryRequestMessage.h"

void JobCrafterDirectoryEntryRequestMessage::serialize(Writer *output)
{
  this->serializeAs_JobCrafterDirectoryEntryRequestMessage(output);
}

void JobCrafterDirectoryEntryRequestMessage::serializeAs_JobCrafterDirectoryEntryRequestMessage(Writer *output)
{
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void JobCrafterDirectoryEntryRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_JobCrafterDirectoryEntryRequestMessage(input);
}

void JobCrafterDirectoryEntryRequestMessage::deserializeAs_JobCrafterDirectoryEntryRequestMessage(Reader *input)
{
  this->_playerIdFunc(input);
}

void JobCrafterDirectoryEntryRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobCrafterDirectoryEntryRequestMessage(tree);
}

void JobCrafterDirectoryEntryRequestMessage::deserializeAsyncAs_JobCrafterDirectoryEntryRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&JobCrafterDirectoryEntryRequestMessage::_playerIdFunc, this, std::placeholders::_1));
}

void JobCrafterDirectoryEntryRequestMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element of JobCrafterDirectoryEntryRequestMessage.playerId.";
  }
}

JobCrafterDirectoryEntryRequestMessage::JobCrafterDirectoryEntryRequestMessage()
{
  m_type = MessageEnum::JOBCRAFTERDIRECTORYENTRYREQUESTMESSAGE;
}

