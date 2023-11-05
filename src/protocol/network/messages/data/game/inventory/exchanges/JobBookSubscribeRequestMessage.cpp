#include "JobBookSubscribeRequestMessage.h"

void JobBookSubscribeRequestMessage::serialize(Writer *output)
{
  this->serializeAs_JobBookSubscribeRequestMessage(output);
}

void JobBookSubscribeRequestMessage::serializeAs_JobBookSubscribeRequestMessage(Writer *output)
{
  output->writeShort((short)this->jobIds.size());
  for(uint _i1 = 0; _i1 < this->jobIds.size(); _i1++)
  {
    if(this->jobIds[_i1] < 0)
    {
      qDebug()<<"ERREUR - JobBookSubscribeRequestMessage -"<<"Forbidden value (" << this->jobIds[_i1] << ") on element 1 (starting at 1) of jobIds.";
    }
    output->writeByte(this->jobIds[_i1]);
  }
}

void JobBookSubscribeRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_JobBookSubscribeRequestMessage(input);
}

void JobBookSubscribeRequestMessage::deserializeAs_JobBookSubscribeRequestMessage(Reader *input)
{
  uint _val1 = 0;
  uint _jobIdsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _jobIdsLen; _i1++)
  {
    _val1 = uint(input->readByte());
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - JobBookSubscribeRequestMessage -"<<"Forbidden value (" << _val1 << ") on elements of jobIds.";
    }
    this->jobIds.append(_val1);
  }
}

void JobBookSubscribeRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobBookSubscribeRequestMessage(tree);
}

void JobBookSubscribeRequestMessage::deserializeAsyncAs_JobBookSubscribeRequestMessage(FuncTree tree)
{
  this->_jobIdstree = tree.addChild(std::bind(&JobBookSubscribeRequestMessage::_jobIdstreeFunc, this, std::placeholders::_1));
}

void JobBookSubscribeRequestMessage::_jobIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_jobIdstree.addChild(std::bind(&JobBookSubscribeRequestMessage::_jobIdsFunc, this, std::placeholders::_1));
  }
}

void JobBookSubscribeRequestMessage::_jobIdsFunc(Reader *input)
{
  uint _val = uint(input->readByte());
  if(_val < 0)
  {
    qDebug()<<"ERREUR - JobBookSubscribeRequestMessage -"<<"Forbidden value (" << _val << ") on elements of jobIds.";
  }
  this->jobIds.append(_val);
}

JobBookSubscribeRequestMessage::JobBookSubscribeRequestMessage()
{
  m_type = MessageEnum::JOBBOOKSUBSCRIBEREQUESTMESSAGE;
}

