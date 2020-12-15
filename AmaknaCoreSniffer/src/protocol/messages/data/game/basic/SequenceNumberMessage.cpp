#include "SequenceNumberMessage.h"

void SequenceNumberMessage::serialize(Writer *output)
{
  this->serializeAs_SequenceNumberMessage(output);
}

void SequenceNumberMessage::serializeAs_SequenceNumberMessage(Writer *output)
{
  if(this->number < 0 || this->number > 65535)
  {
    qDebug()<<"ERREUR - SequenceNumberMessage -"<<"Forbidden value (" << this->number << ") on element number.";
  }
  output->writeShort((short)this->number);
}

void SequenceNumberMessage::deserialize(Reader *input)
{
  this->deserializeAs_SequenceNumberMessage(input);
}

void SequenceNumberMessage::deserializeAs_SequenceNumberMessage(Reader *input)
{
  this->_numberFunc(input);
}

void SequenceNumberMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SequenceNumberMessage(tree);
}

void SequenceNumberMessage::deserializeAsyncAs_SequenceNumberMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SequenceNumberMessage::_numberFunc, this, std::placeholders::_1));
}

void SequenceNumberMessage::_numberFunc(Reader *input)
{
  this->number = input->readUShort();
  if(this->number < 0 || this->number > 65535)
  {
    qDebug()<<"ERREUR - SequenceNumberMessage -"<<"Forbidden value (" << this->number << ") on element of SequenceNumberMessage.number.";
  }
}

SequenceNumberMessage::SequenceNumberMessage()
{
  m_type = MessageEnum::SEQUENCENUMBERMESSAGE;
}

