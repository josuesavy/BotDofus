#include "SlaveNoLongerControledMessage.h"

void SlaveNoLongerControledMessage::serialize(Writer *output)
{
  this->serializeAs_SlaveNoLongerControledMessage(output);
}

void SlaveNoLongerControledMessage::serializeAs_SlaveNoLongerControledMessage(Writer *output)
{
  if(this->masterId < -9007199254740992 || this->masterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - SlaveNoLongerControledMessage -"<<"Forbidden value (" << this->masterId << ") on element masterId.";
  }
  output->writeDouble(this->masterId);
  if(this->slaveId < -9007199254740992 || this->slaveId > 9007199254740992)
  {
    qDebug()<<"ERREUR - SlaveNoLongerControledMessage -"<<"Forbidden value (" << this->slaveId << ") on element slaveId.";
  }
  output->writeDouble(this->slaveId);
}

void SlaveNoLongerControledMessage::deserialize(Reader *input)
{
  this->deserializeAs_SlaveNoLongerControledMessage(input);
}

void SlaveNoLongerControledMessage::deserializeAs_SlaveNoLongerControledMessage(Reader *input)
{
  this->_masterIdFunc(input);
  this->_slaveIdFunc(input);
}

void SlaveNoLongerControledMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SlaveNoLongerControledMessage(tree);
}

void SlaveNoLongerControledMessage::deserializeAsyncAs_SlaveNoLongerControledMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SlaveNoLongerControledMessage::_masterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SlaveNoLongerControledMessage::_slaveIdFunc, this, std::placeholders::_1));
}

void SlaveNoLongerControledMessage::_masterIdFunc(Reader *input)
{
  this->masterId = input->readDouble();
  if(this->masterId < -9007199254740992 || this->masterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - SlaveNoLongerControledMessage -"<<"Forbidden value (" << this->masterId << ") on element of SlaveNoLongerControledMessage.masterId.";
  }
}

void SlaveNoLongerControledMessage::_slaveIdFunc(Reader *input)
{
  this->slaveId = input->readDouble();
  if(this->slaveId < -9007199254740992 || this->slaveId > 9007199254740992)
  {
    qDebug()<<"ERREUR - SlaveNoLongerControledMessage -"<<"Forbidden value (" << this->slaveId << ") on element of SlaveNoLongerControledMessage.slaveId.";
  }
}

SlaveNoLongerControledMessage::SlaveNoLongerControledMessage()
{
  m_type = MessageEnum::SLAVENOLONGERCONTROLEDMESSAGE;
}

