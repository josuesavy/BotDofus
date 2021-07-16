#include "IdentificationSuccessMessage.h"

void IdentificationSuccessMessage::serialize(Writer *output)
{
  this->serializeAs_IdentificationSuccessMessage(output);
}

void IdentificationSuccessMessage::serializeAs_IdentificationSuccessMessage(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->hasRights);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->hasConsoleRight);
  _box0 = BooleanByteWrapper::setFlag(_box0, 2, this->wasAlreadyConnected);
  output->writeByte(_box0);
  output->writeUTF(this->login);
  this->accountTag.serializeAs_AccountTagInformation(output);
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  output->writeInt((int)this->accountId);
  if(this->communityId < 0)
  {
    qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->communityId << ") on element communityId.";
  }
  output->writeByte(this->communityId);
  output->writeUTF(this->secretQuestion);
  if(this->accountCreation < 0 || this->accountCreation > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->accountCreation << ") on element accountCreation.";
  }
  output->writeDouble(this->accountCreation);
  if(this->subscriptionElapsedDuration < 0 || this->subscriptionElapsedDuration > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->subscriptionElapsedDuration << ") on element subscriptionElapsedDuration.";
  }
  output->writeDouble(this->subscriptionElapsedDuration);
  if(this->subscriptionEndDate < 0 || this->subscriptionEndDate > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->subscriptionEndDate << ") on element subscriptionEndDate.";
  }
  output->writeDouble(this->subscriptionEndDate);
  if(this->havenbagAvailableRoom < 0 || this->havenbagAvailableRoom > 255)
  {
    qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->havenbagAvailableRoom << ") on element havenbagAvailableRoom.";
  }
  output->writeByte(this->havenbagAvailableRoom);
}

void IdentificationSuccessMessage::deserialize(Reader *input)
{
  this->deserializeAs_IdentificationSuccessMessage(input);
}

void IdentificationSuccessMessage::deserializeAs_IdentificationSuccessMessage(Reader *input)
{
  this->deserializeByteBoxes(input);
  this->_loginFunc(input);
  this->accountTag = AccountTagInformation();
  this->accountTag.deserialize(input);
  this->_accountIdFunc(input);
  this->_communityIdFunc(input);
  this->_secretQuestionFunc(input);
  this->_accountCreationFunc(input);
  this->_subscriptionElapsedDurationFunc(input);
  this->_subscriptionEndDateFunc(input);
  this->_havenbagAvailableRoomFunc(input);
}

void IdentificationSuccessMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IdentificationSuccessMessage(tree);
}

void IdentificationSuccessMessage::deserializeAsyncAs_IdentificationSuccessMessage(FuncTree tree)
{
  tree.addChild(std::bind(&IdentificationSuccessMessage::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&IdentificationSuccessMessage::_loginFunc, this, std::placeholders::_1));
  this->_accountTagtree = tree.addChild(std::bind(&IdentificationSuccessMessage::_accountTagtreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IdentificationSuccessMessage::_accountIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IdentificationSuccessMessage::_communityIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IdentificationSuccessMessage::_secretQuestionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IdentificationSuccessMessage::_accountCreationFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IdentificationSuccessMessage::_subscriptionElapsedDurationFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IdentificationSuccessMessage::_subscriptionEndDateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IdentificationSuccessMessage::_havenbagAvailableRoomFunc, this, std::placeholders::_1));
}

void IdentificationSuccessMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->hasRights = BooleanByteWrapper::getFlag(_box0, 0);
  this->hasConsoleRight = BooleanByteWrapper::getFlag(_box0, 1);
  this->wasAlreadyConnected = BooleanByteWrapper::getFlag(_box0, 2);
}

void IdentificationSuccessMessage::_loginFunc(Reader *input)
{
  this->login = input->readUTF();
}

void IdentificationSuccessMessage::_accountTagtreeFunc(Reader *input)
{
  this->accountTag = AccountTagInformation();
  this->accountTag.deserializeAsync(this->_accountTagtree);
}

void IdentificationSuccessMessage::_accountIdFunc(Reader *input)
{
  this->accountId = input->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->accountId << ") on element of IdentificationSuccessMessage.accountId.";
  }
}

void IdentificationSuccessMessage::_communityIdFunc(Reader *input)
{
  this->communityId = input->readByte();
  if(this->communityId < 0)
  {
    qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->communityId << ") on element of IdentificationSuccessMessage.communityId.";
  }
}

void IdentificationSuccessMessage::_secretQuestionFunc(Reader *input)
{
  this->secretQuestion = input->readUTF();
}

void IdentificationSuccessMessage::_accountCreationFunc(Reader *input)
{
  this->accountCreation = input->readDouble();
  if(this->accountCreation < 0 || this->accountCreation > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->accountCreation << ") on element of IdentificationSuccessMessage.accountCreation.";
  }
}

void IdentificationSuccessMessage::_subscriptionElapsedDurationFunc(Reader *input)
{
  this->subscriptionElapsedDuration = input->readDouble();
  if(this->subscriptionElapsedDuration < 0 || this->subscriptionElapsedDuration > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->subscriptionElapsedDuration << ") on element of IdentificationSuccessMessage.subscriptionElapsedDuration.";
  }
}

void IdentificationSuccessMessage::_subscriptionEndDateFunc(Reader *input)
{
  this->subscriptionEndDate = input->readDouble();
  if(this->subscriptionEndDate < 0 || this->subscriptionEndDate > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->subscriptionEndDate << ") on element of IdentificationSuccessMessage.subscriptionEndDate.";
  }
}

void IdentificationSuccessMessage::_havenbagAvailableRoomFunc(Reader *input)
{
  this->havenbagAvailableRoom = input->readUByte();
  if(this->havenbagAvailableRoom < 0 || this->havenbagAvailableRoom > 255)
  {
    qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->havenbagAvailableRoom << ") on element of IdentificationSuccessMessage.havenbagAvailableRoom.";
  }
}

IdentificationSuccessMessage::IdentificationSuccessMessage()
{
  m_type = MessageEnum::IDENTIFICATIONSUCCESSMESSAGE;
}

