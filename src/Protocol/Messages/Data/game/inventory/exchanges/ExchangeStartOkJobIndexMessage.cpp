#include "ExchangeStartOkJobIndexMessage.h"

void ExchangeStartOkJobIndexMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartOkJobIndexMessage(output);
}

void ExchangeStartOkJobIndexMessage::serializeAs_ExchangeStartOkJobIndexMessage(Writer *output)
{
  output->writeShort((short)this->jobs.size());
  for(uint _i1 = 0; _i1 < this->jobs.size(); _i1++)
  {
    if(this->jobs[_i1] < 0)
    {
      qDebug()<<"ERREUR - ExchangeStartOkJobIndexMessage -"<<"Forbidden value (" << this->jobs[_i1] << ") on element 1 (starting at 1) of jobs.";
    }
    output->writeVarInt((int)this->jobs[_i1]);
  }
}

void ExchangeStartOkJobIndexMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartOkJobIndexMessage(input);
}

void ExchangeStartOkJobIndexMessage::deserializeAs_ExchangeStartOkJobIndexMessage(Reader *input)
{
  uint _val1 = 0;
  uint _jobsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _jobsLen; _i1++)
  {
    _val1 = input->readVarUhInt();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - ExchangeStartOkJobIndexMessage -"<<"Forbidden value (" << _val1 << ") on elements of jobs.";
    }
    this->jobs.append(_val1);
  }
}

void ExchangeStartOkJobIndexMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartOkJobIndexMessage(tree);
}

void ExchangeStartOkJobIndexMessage::deserializeAsyncAs_ExchangeStartOkJobIndexMessage(FuncTree tree)
{
  this->_jobstree = tree.addChild(std::bind(&ExchangeStartOkJobIndexMessage::_jobstreeFunc, this, std::placeholders::_1));
}

void ExchangeStartOkJobIndexMessage::_jobstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_jobstree.addChild(std::bind(&ExchangeStartOkJobIndexMessage::_jobsFunc, this, std::placeholders::_1));
  }
}

void ExchangeStartOkJobIndexMessage::_jobsFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkJobIndexMessage -"<<"Forbidden value (" << _val << ") on elements of jobs.";
  }
  this->jobs.append(_val);
}

ExchangeStartOkJobIndexMessage::ExchangeStartOkJobIndexMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKJOBINDEXMESSAGE;
}

