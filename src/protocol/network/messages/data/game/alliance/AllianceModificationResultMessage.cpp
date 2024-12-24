#include "AllianceModificationResultMessage.h"

void AllianceModificationResultMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceModificationResultMessage(output);
}

void AllianceModificationResultMessage::serializeAs_AllianceModificationResultMessage(Writer *output)
{
  output->writeByte(this->result);
}

void AllianceModificationResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceModificationResultMessage(input);
}

void AllianceModificationResultMessage::deserializeAs_AllianceModificationResultMessage(Reader *input)
{
  this->_resultFunc(input);
}

void AllianceModificationResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceModificationResultMessage(tree);
}

void AllianceModificationResultMessage::deserializeAsyncAs_AllianceModificationResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceModificationResultMessage::_resultFunc, this, std::placeholders::_1));
}

void AllianceModificationResultMessage::_resultFunc(Reader *input)
{
  this->result = input->readByte();
  if(this->result < 0)
  {
    qDebug()<<"ERREUR - AllianceModificationResultMessage -"<<"Forbidden value (" << this->result << ") on element of AllianceModificationResultMessage.result.";
  }
}

AllianceModificationResultMessage::AllianceModificationResultMessage()
{
  m_type = MessageEnum::ALLIANCEMODIFICATIONRESULTMESSAGE;
}

