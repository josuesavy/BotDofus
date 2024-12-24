#include "IdentificationFailedBannedMessage.h"

void IdentificationFailedBannedMessage::serialize(Writer *output)
{
  this->serializeAs_IdentificationFailedBannedMessage(output);
}

void IdentificationFailedBannedMessage::serializeAs_IdentificationFailedBannedMessage(Writer *output)
{
  IdentificationFailedMessage::serializeAs_IdentificationFailedMessage(output);
  if(this->banEndDate < 0 || this->banEndDate > 9007199254740992)
  {
    qDebug()<<"ERREUR - IdentificationFailedBannedMessage -"<<"Forbidden value (" << this->banEndDate << ") on element banEndDate.";
  }
  output->writeDouble(this->banEndDate);
}

void IdentificationFailedBannedMessage::deserialize(Reader *input)
{
  this->deserializeAs_IdentificationFailedBannedMessage(input);
}

void IdentificationFailedBannedMessage::deserializeAs_IdentificationFailedBannedMessage(Reader *input)
{
  IdentificationFailedMessage::deserialize(input);
  this->_banEndDateFunc(input);
}

void IdentificationFailedBannedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IdentificationFailedBannedMessage(tree);
}

void IdentificationFailedBannedMessage::deserializeAsyncAs_IdentificationFailedBannedMessage(FuncTree tree)
{
  IdentificationFailedMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&IdentificationFailedBannedMessage::_banEndDateFunc, this, std::placeholders::_1));
}

void IdentificationFailedBannedMessage::_banEndDateFunc(Reader *input)
{
  this->banEndDate = input->readDouble();
  if(this->banEndDate < 0 || this->banEndDate > 9007199254740992)
  {
    qDebug()<<"ERREUR - IdentificationFailedBannedMessage -"<<"Forbidden value (" << this->banEndDate << ") on element of IdentificationFailedBannedMessage.banEndDate.";
  }
}

IdentificationFailedBannedMessage::IdentificationFailedBannedMessage()
{
  m_type = MessageEnum::IDENTIFICATIONFAILEDBANNEDMESSAGE;
}

