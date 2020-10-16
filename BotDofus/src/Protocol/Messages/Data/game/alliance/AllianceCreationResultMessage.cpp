#include "AllianceCreationResultMessage.h"

void AllianceCreationResultMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceCreationResultMessage(output);
}

void AllianceCreationResultMessage::serializeAs_AllianceCreationResultMessage(Writer *output)
{
  output->writeByte(this->result);
}

void AllianceCreationResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceCreationResultMessage(input);
}

void AllianceCreationResultMessage::deserializeAs_AllianceCreationResultMessage(Reader *input)
{
  this->_resultFunc(input);
}

void AllianceCreationResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceCreationResultMessage(tree);
}

void AllianceCreationResultMessage::deserializeAsyncAs_AllianceCreationResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceCreationResultMessage::_resultFunc, this, std::placeholders::_1));
}

void AllianceCreationResultMessage::_resultFunc(Reader *input)
{
  this->result = input->readByte();
  if(this->result < 0)
  {
    qDebug()<<"ERREUR - AllianceCreationResultMessage -"<<"Forbidden value (" << this->result << ") on element of AllianceCreationResultMessage.result.";
  }
}

AllianceCreationResultMessage::AllianceCreationResultMessage()
{
  m_type = MessageEnum::ALLIANCECREATIONRESULTMESSAGE;
}

