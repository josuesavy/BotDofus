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
  if(this->breedsVisible < 0)
  {
    qDebug()<<"ERREUR - AccountCapabilitiesMessage -"<<"Forbidden value (" << this->breedsVisible << ") on element breedsVisible.";
  }
  output->writeVarInt((int)this->breedsVisible);
  if(this->breedsAvailable < 0)
  {
    qDebug()<<"ERREUR - AccountCapabilitiesMessage -"<<"Forbidden value (" << this->breedsAvailable << ") on element breedsAvailable.";
  }
  output->writeVarInt((int)this->breedsAvailable);
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
  this->_breedsVisibleFunc(input);
  this->_breedsAvailableFunc(input);
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
  tree.addChild(std::bind(&AccountCapabilitiesMessage::_breedsVisibleFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AccountCapabilitiesMessage::_breedsAvailableFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AccountCapabilitiesMessage::_statusFunc, this, std::placeholders::_1));
}

void AccountCapabilitiesMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
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

void AccountCapabilitiesMessage::_breedsVisibleFunc(Reader *input)
{
  this->breedsVisible = input->readVarUhInt();
  if(this->breedsVisible < 0)
  {
    qDebug()<<"ERREUR - AccountCapabilitiesMessage -"<<"Forbidden value (" << this->breedsVisible << ") on element of AccountCapabilitiesMessage.breedsVisible.";
  }
}

void AccountCapabilitiesMessage::_breedsAvailableFunc(Reader *input)
{
  this->breedsAvailable = input->readVarUhInt();
  if(this->breedsAvailable < 0)
  {
    qDebug()<<"ERREUR - AccountCapabilitiesMessage -"<<"Forbidden value (" << this->breedsAvailable << ") on element of AccountCapabilitiesMessage.breedsAvailable.";
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

