#include "UpdateSelfAgressableStatusMessage.h"

void UpdateSelfAgressableStatusMessage::serialize(Writer *output)
{
  this->serializeAs_UpdateSelfAgressableStatusMessage(output);
}

void UpdateSelfAgressableStatusMessage::serializeAs_UpdateSelfAgressableStatusMessage(Writer *output)
{
  output->writeByte(this->status);
  if(this->probationTime < 0)
  {
    qDebug()<<"ERREUR - UpdateSelfAgressableStatusMessage -"<<"Forbidden value (" << this->probationTime << ") on element probationTime.";
  }
  output->writeInt((int)this->probationTime);
}

void UpdateSelfAgressableStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_UpdateSelfAgressableStatusMessage(input);
}

void UpdateSelfAgressableStatusMessage::deserializeAs_UpdateSelfAgressableStatusMessage(Reader *input)
{
  this->_statusFunc(input);
  this->_probationTimeFunc(input);
}

void UpdateSelfAgressableStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_UpdateSelfAgressableStatusMessage(tree);
}

void UpdateSelfAgressableStatusMessage::deserializeAsyncAs_UpdateSelfAgressableStatusMessage(FuncTree tree)
{
  tree.addChild(std::bind(&UpdateSelfAgressableStatusMessage::_statusFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&UpdateSelfAgressableStatusMessage::_probationTimeFunc, this, std::placeholders::_1));
}

void UpdateSelfAgressableStatusMessage::_statusFunc(Reader *input)
{
  this->status = input->readByte();
  if(this->status < 0)
  {
    qDebug()<<"ERREUR - UpdateSelfAgressableStatusMessage -"<<"Forbidden value (" << this->status << ") on element of UpdateSelfAgressableStatusMessage.status.";
  }
}

void UpdateSelfAgressableStatusMessage::_probationTimeFunc(Reader *input)
{
  this->probationTime = input->readInt();
  if(this->probationTime < 0)
  {
    qDebug()<<"ERREUR - UpdateSelfAgressableStatusMessage -"<<"Forbidden value (" << this->probationTime << ") on element of UpdateSelfAgressableStatusMessage.probationTime.";
  }
}

UpdateSelfAgressableStatusMessage::UpdateSelfAgressableStatusMessage()
{
  m_type = MessageEnum::UPDATESELFAGRESSABLESTATUSMESSAGE;
}

