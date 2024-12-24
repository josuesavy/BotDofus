#include "SequenceEndMessage.h"

void SequenceEndMessage::serialize(Writer *output)
{
  this->serializeAs_SequenceEndMessage(output);
}

void SequenceEndMessage::serializeAs_SequenceEndMessage(Writer *output)
{
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - SequenceEndMessage -"<<"Forbidden value (" << this->actionId << ") on element actionId.";
  }
  output->writeVarShort((int)this->actionId);
  if(this->authorId < -9007199254740992 || this->authorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - SequenceEndMessage -"<<"Forbidden value (" << this->authorId << ") on element authorId.";
  }
  output->writeDouble(this->authorId);
  output->writeByte(this->sequenceType);
}

void SequenceEndMessage::deserialize(Reader *input)
{
  this->deserializeAs_SequenceEndMessage(input);
}

void SequenceEndMessage::deserializeAs_SequenceEndMessage(Reader *input)
{
  this->_actionIdFunc(input);
  this->_authorIdFunc(input);
  this->_sequenceTypeFunc(input);
}

void SequenceEndMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SequenceEndMessage(tree);
}

void SequenceEndMessage::deserializeAsyncAs_SequenceEndMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SequenceEndMessage::_actionIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SequenceEndMessage::_authorIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SequenceEndMessage::_sequenceTypeFunc, this, std::placeholders::_1));
}

void SequenceEndMessage::_actionIdFunc(Reader *input)
{
  this->actionId = input->readVarUhShort();
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - SequenceEndMessage -"<<"Forbidden value (" << this->actionId << ") on element of SequenceEndMessage.actionId.";
  }
}

void SequenceEndMessage::_authorIdFunc(Reader *input)
{
  this->authorId = input->readDouble();
  if(this->authorId < -9007199254740992 || this->authorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - SequenceEndMessage -"<<"Forbidden value (" << this->authorId << ") on element of SequenceEndMessage.authorId.";
  }
}

void SequenceEndMessage::_sequenceTypeFunc(Reader *input)
{
  this->sequenceType = input->readByte();
}

SequenceEndMessage::SequenceEndMessage()
{
  m_type = MessageEnum::SEQUENCEENDMESSAGE;
}

