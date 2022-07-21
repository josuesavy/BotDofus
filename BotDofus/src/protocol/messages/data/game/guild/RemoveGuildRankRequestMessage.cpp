#include "RemoveGuildRankRequestMessage.h"

void RemoveGuildRankRequestMessage::serialize(Writer *output)
{
  this->serializeAs_RemoveGuildRankRequestMessage(output);
}

void RemoveGuildRankRequestMessage::serializeAs_RemoveGuildRankRequestMessage(Writer *output)
{
  if(this->rankId < 0)
  {
    qDebug()<<"ERREUR - RemoveGuildRankRequestMessage -"<<"Forbidden value (" << this->rankId << ") on element rankId.";
  }
  output->writeVarInt((int)this->rankId);
  if(this->newRankId < 0)
  {
    qDebug()<<"ERREUR - RemoveGuildRankRequestMessage -"<<"Forbidden value (" << this->newRankId << ") on element newRankId.";
  }
  output->writeVarInt((int)this->newRankId);
}

void RemoveGuildRankRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_RemoveGuildRankRequestMessage(input);
}

void RemoveGuildRankRequestMessage::deserializeAs_RemoveGuildRankRequestMessage(Reader *input)
{
  this->_rankIdFunc(input);
  this->_newRankIdFunc(input);
}

void RemoveGuildRankRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_RemoveGuildRankRequestMessage(tree);
}

void RemoveGuildRankRequestMessage::deserializeAsyncAs_RemoveGuildRankRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&RemoveGuildRankRequestMessage::_rankIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&RemoveGuildRankRequestMessage::_newRankIdFunc, this, std::placeholders::_1));
}

void RemoveGuildRankRequestMessage::_rankIdFunc(Reader *input)
{
  this->rankId = input->readVarUhInt();
  if(this->rankId < 0)
  {
    qDebug()<<"ERREUR - RemoveGuildRankRequestMessage -"<<"Forbidden value (" << this->rankId << ") on element of RemoveGuildRankRequestMessage.rankId.";
  }
}

void RemoveGuildRankRequestMessage::_newRankIdFunc(Reader *input)
{
  this->newRankId = input->readVarUhInt();
  if(this->newRankId < 0)
  {
    qDebug()<<"ERREUR - RemoveGuildRankRequestMessage -"<<"Forbidden value (" << this->newRankId << ") on element of RemoveGuildRankRequestMessage.newRankId.";
  }
}

RemoveGuildRankRequestMessage::RemoveGuildRankRequestMessage()
{
  m_type = MessageEnum::REMOVEGUILDRANKREQUESTMESSAGE;
}

