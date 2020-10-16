#include "BasicAckMessage.h"

void BasicAckMessage::serialize(Writer *output)
{
  this->serializeAs_BasicAckMessage(output);
}

void BasicAckMessage::serializeAs_BasicAckMessage(Writer *output)
{
  if(this->seq < 0)
  {
    qDebug()<<"ERREUR - BasicAckMessage -"<<"Forbidden value (" << this->seq << ") on element seq.";
  }
  output->writeVarInt((int)this->seq);
  if(this->lastPacketId < 0)
  {
    qDebug()<<"ERREUR - BasicAckMessage -"<<"Forbidden value (" << this->lastPacketId << ") on element lastPacketId.";
  }
  output->writeVarShort((int)this->lastPacketId);
}

void BasicAckMessage::deserialize(Reader *input)
{
  this->deserializeAs_BasicAckMessage(input);
}

void BasicAckMessage::deserializeAs_BasicAckMessage(Reader *input)
{
  this->_seqFunc(input);
  this->_lastPacketIdFunc(input);
}

void BasicAckMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BasicAckMessage(tree);
}

void BasicAckMessage::deserializeAsyncAs_BasicAckMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BasicAckMessage::_seqFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BasicAckMessage::_lastPacketIdFunc, this, std::placeholders::_1));
}

void BasicAckMessage::_seqFunc(Reader *input)
{
  this->seq = input->readVarUhInt();
  if(this->seq < 0)
  {
    qDebug()<<"ERREUR - BasicAckMessage -"<<"Forbidden value (" << this->seq << ") on element of BasicAckMessage.seq.";
  }
}

void BasicAckMessage::_lastPacketIdFunc(Reader *input)
{
  this->lastPacketId = input->readVarUhShort();
  if(this->lastPacketId < 0)
  {
    qDebug()<<"ERREUR - BasicAckMessage -"<<"Forbidden value (" << this->lastPacketId << ") on element of BasicAckMessage.lastPacketId.";
  }
}

BasicAckMessage::BasicAckMessage()
{
  m_type = MessageEnum::BASICACKMESSAGE;
}

