#include "IdentificationFailedMessage.h"

void IdentificationFailedMessage::serialize(Writer *output)
{
  this->serializeAs_IdentificationFailedMessage(output);
}

void IdentificationFailedMessage::serializeAs_IdentificationFailedMessage(Writer *output)
{
  output->writeByte(this->reason);
}

void IdentificationFailedMessage::deserialize(Reader *input)
{
  this->deserializeAs_IdentificationFailedMessage(input);
}

void IdentificationFailedMessage::deserializeAs_IdentificationFailedMessage(Reader *input)
{
  this->_reasonFunc(input);
}

void IdentificationFailedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IdentificationFailedMessage(tree);
}

void IdentificationFailedMessage::deserializeAsyncAs_IdentificationFailedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&IdentificationFailedMessage::_reasonFunc, this, std::placeholders::_1));
}

void IdentificationFailedMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - IdentificationFailedMessage -"<<"Forbidden value (" << this->reason << ") on element of IdentificationFailedMessage.reason.";
  }
}

IdentificationFailedMessage::IdentificationFailedMessage()
{
  m_type = MessageEnum::IDENTIFICATIONFAILEDMESSAGE;
}

