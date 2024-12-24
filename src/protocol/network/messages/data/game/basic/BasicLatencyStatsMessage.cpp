#include "BasicLatencyStatsMessage.h"

void BasicLatencyStatsMessage::serialize(Writer *output)
{
  this->serializeAs_BasicLatencyStatsMessage(output);
}

void BasicLatencyStatsMessage::serializeAs_BasicLatencyStatsMessage(Writer *output)
{
  if(this->latency < 0 || this->latency > 65535)
  {
    qDebug()<<"ERREUR - BasicLatencyStatsMessage -"<<"Forbidden value (" << this->latency << ") on element latency.";
  }
  output->writeShort((short)this->latency);
  if(this->sampleCount < 0)
  {
    qDebug()<<"ERREUR - BasicLatencyStatsMessage -"<<"Forbidden value (" << this->sampleCount << ") on element sampleCount.";
  }
  output->writeVarShort((int)this->sampleCount);
  if(this->max < 0)
  {
    qDebug()<<"ERREUR - BasicLatencyStatsMessage -"<<"Forbidden value (" << this->max << ") on element max.";
  }
  output->writeVarShort((int)this->max);
}

void BasicLatencyStatsMessage::deserialize(Reader *input)
{
  this->deserializeAs_BasicLatencyStatsMessage(input);
}

void BasicLatencyStatsMessage::deserializeAs_BasicLatencyStatsMessage(Reader *input)
{
  this->_latencyFunc(input);
  this->_sampleCountFunc(input);
  this->_maxFunc(input);
}

void BasicLatencyStatsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BasicLatencyStatsMessage(tree);
}

void BasicLatencyStatsMessage::deserializeAsyncAs_BasicLatencyStatsMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BasicLatencyStatsMessage::_latencyFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BasicLatencyStatsMessage::_sampleCountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BasicLatencyStatsMessage::_maxFunc, this, std::placeholders::_1));
}

void BasicLatencyStatsMessage::_latencyFunc(Reader *input)
{
  this->latency = input->readUShort();
  if(this->latency < 0 || this->latency > 65535)
  {
    qDebug()<<"ERREUR - BasicLatencyStatsMessage -"<<"Forbidden value (" << this->latency << ") on element of BasicLatencyStatsMessage.latency.";
  }
}

void BasicLatencyStatsMessage::_sampleCountFunc(Reader *input)
{
  this->sampleCount = input->readVarUhShort();
  if(this->sampleCount < 0)
  {
    qDebug()<<"ERREUR - BasicLatencyStatsMessage -"<<"Forbidden value (" << this->sampleCount << ") on element of BasicLatencyStatsMessage.sampleCount.";
  }
}

void BasicLatencyStatsMessage::_maxFunc(Reader *input)
{
  this->max = input->readVarUhShort();
  if(this->max < 0)
  {
    qDebug()<<"ERREUR - BasicLatencyStatsMessage -"<<"Forbidden value (" << this->max << ") on element of BasicLatencyStatsMessage.max.";
  }
}

BasicLatencyStatsMessage::BasicLatencyStatsMessage()
{
  m_type = MessageEnum::BASICLATENCYSTATSMESSAGE;
  m_needsHash = true;
}

