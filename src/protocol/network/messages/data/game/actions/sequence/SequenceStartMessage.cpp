#include "SequenceStartMessage.h"

void SequenceStartMessage::serialize(Writer *output)
{
  this->serializeAs_SequenceStartMessage(output);
}

void SequenceStartMessage::serializeAs_SequenceStartMessage(Writer *output)
{
  output->writeByte(this->sequenceType);
  if(this->authorId < -9007199254740992 || this->authorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - SequenceStartMessage -"<<"Forbidden value (" << this->authorId << ") on element authorId.";
  }
  output->writeDouble(this->authorId);
}

void SequenceStartMessage::deserialize(Reader *input)
{
  this->deserializeAs_SequenceStartMessage(input);
}

void SequenceStartMessage::deserializeAs_SequenceStartMessage(Reader *input)
{
  this->_sequenceTypeFunc(input);
  this->_authorIdFunc(input);
}

void SequenceStartMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SequenceStartMessage(tree);
}

void SequenceStartMessage::deserializeAsyncAs_SequenceStartMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SequenceStartMessage::_sequenceTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SequenceStartMessage::_authorIdFunc, this, std::placeholders::_1));
}

void SequenceStartMessage::_sequenceTypeFunc(Reader *input)
{
  this->sequenceType = input->readByte();
}

void SequenceStartMessage::_authorIdFunc(Reader *input)
{
  this->authorId = input->readDouble();
  if(this->authorId < -9007199254740992 || this->authorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - SequenceStartMessage -"<<"Forbidden value (" << this->authorId << ") on element of SequenceStartMessage.authorId.";
  }
}

SequenceStartMessage::SequenceStartMessage()
{
  m_type = MessageEnum::SEQUENCESTARTMESSAGE;
}

