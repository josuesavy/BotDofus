#include "AccountCapabilitiesMessage.h"

void AccountCapabilitiesMessage::serialize(Writer *output)
{
  this->serializeAs_AccountCapabilitiesMessage(output);
}

void AccountCapabilitiesMessage::serializeAs_AccountCapabilitiesMessage(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->tutorialAvailable);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->canCreateNewCharacter);
  output->writeByte(_box0);
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - AccountCapabilitiesMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  output->writeInt((int)this->accountId);
  output->writeByte(this->status);
}

void AccountCapabilitiesMessage::deserialize(Reader *input)
{
  this->deserializeAs_AccountCapabilitiesMessage(input);
}

void AccountCapabilitiesMessage::deserializeAs_AccountCapabilitiesMessage(Reader *input)
{
  this->deserializeByteBoxes(input);
  this->_accountIdFunc(input);
  this->_statusFunc(input);
}

void AccountCapabilitiesMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AccountCapabilitiesMessage(tree);
}

void AccountCapabilitiesMessage::deserializeAsyncAs_AccountCapabilitiesMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AccountCapabilitiesMessage::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&AccountCapabilitiesMessage::_accountIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AccountCapabilitiesMessage::_statusFunc, this, std::placeholders::_1));
}

void AccountCapabilitiesMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = uint(input->readByte());
  this->tutorialAvailable = BooleanByteWrapper::getFlag(_box0, 0);
  this->canCreateNewCharacter = BooleanByteWrapper::getFlag(_box0, 1);
}

void AccountCapabilitiesMessage::_accountIdFunc(Reader *input)
{
  this->accountId = input->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - AccountCapabilitiesMessage -"<<"Forbidden value (" << this->accountId << ") on element of AccountCapabilitiesMessage.accountId.";
  }
}

void AccountCapabilitiesMessage::_statusFunc(Reader *input)
{
  this->status = input->readByte();
}

AccountCapabilitiesMessage::AccountCapabilitiesMessage()
{
  m_type = MessageEnum::ACCOUNTCAPABILITIESMESSAGE;
}

