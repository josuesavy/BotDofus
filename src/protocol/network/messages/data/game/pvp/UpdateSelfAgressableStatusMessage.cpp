#include "UpdateSelfAgressableStatusMessage.h"

void UpdateSelfAgressableStatusMessage::serialize(Writer *output)
{
  this->serializeAs_UpdateSelfAgressableStatusMessage(output);
}

void UpdateSelfAgressableStatusMessage::serializeAs_UpdateSelfAgressableStatusMessage(Writer *output)
{
  output->writeByte(this->status);
  if(this->probationTime < 0 || this->probationTime > 9007199254740992)
  {
    qDebug()<<"ERREUR - UpdateSelfAgressableStatusMessage -"<<"Forbidden value (" << this->probationTime << ") on element probationTime.";
  }
  output->writeDouble(this->probationTime);
  output->writeInt((int)this->roleAvAId);
  output->writeInt((int)this->pictoScore);
}

void UpdateSelfAgressableStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_UpdateSelfAgressableStatusMessage(input);
}

void UpdateSelfAgressableStatusMessage::deserializeAs_UpdateSelfAgressableStatusMessage(Reader *input)
{
  this->_statusFunc(input);
  this->_probationTimeFunc(input);
  this->_roleAvAIdFunc(input);
  this->_pictoScoreFunc(input);
}

void UpdateSelfAgressableStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_UpdateSelfAgressableStatusMessage(tree);
}

void UpdateSelfAgressableStatusMessage::deserializeAsyncAs_UpdateSelfAgressableStatusMessage(FuncTree tree)
{
  tree.addChild(std::bind(&UpdateSelfAgressableStatusMessage::_statusFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&UpdateSelfAgressableStatusMessage::_probationTimeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&UpdateSelfAgressableStatusMessage::_roleAvAIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&UpdateSelfAgressableStatusMessage::_pictoScoreFunc, this, std::placeholders::_1));
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
  this->probationTime = input->readDouble();
  if(this->probationTime < 0 || this->probationTime > 9007199254740992)
  {
    qDebug()<<"ERREUR - UpdateSelfAgressableStatusMessage -"<<"Forbidden value (" << this->probationTime << ") on element of UpdateSelfAgressableStatusMessage.probationTime.";
  }
}

void UpdateSelfAgressableStatusMessage::_roleAvAIdFunc(Reader *input)
{
  this->roleAvAId = input->readInt();
}

void UpdateSelfAgressableStatusMessage::_pictoScoreFunc(Reader *input)
{
  this->pictoScore = input->readInt();
}

UpdateSelfAgressableStatusMessage::UpdateSelfAgressableStatusMessage()
{
  m_type = MessageEnum::UPDATESELFAGRESSABLESTATUSMESSAGE;
}

