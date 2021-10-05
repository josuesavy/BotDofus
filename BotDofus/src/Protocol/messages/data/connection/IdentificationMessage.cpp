#include "IdentificationMessage.h"

void IdentificationMessage::serialize(Writer *output)
{
  this->serializeAs_IdentificationMessage(output);
}

void IdentificationMessage::serializeAs_IdentificationMessage(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->autoconnect);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->useCertificate);
  _box0 = BooleanByteWrapper::setFlag(_box0, 2, this->useLoginToken);
  output->writeByte(_box0);
  this->version.serializeAs_Version(output);
  output->writeUTF(this->lang);
  output->writeVarInt((int)this->credentials.size());
  for(uint _i3 = 0; _i3 < this->credentials.size(); _i3++)
  {
    output->writeByte(this->credentials[_i3]);
  }
  output->writeShort((short)this->serverId);
  if(this->sessionOptionalSalt < -9.007199254740992E15 || this->sessionOptionalSalt > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IdentificationMessage -"<<"Forbidden value (" << this->sessionOptionalSalt << ") on element sessionOptionalSalt.";
  }
  output->writeVarLong((double)this->sessionOptionalSalt);
  output->writeShort((short)this->failedAttempts.size());
  for(uint _i9 = 0; _i9 < this->failedAttempts.size(); _i9++)
  {
    if(this->failedAttempts[_i9] < 0)
    {
      qDebug()<<"ERREUR - IdentificationMessage -"<<"Forbidden value (" << this->failedAttempts[_i9] << ") on element 9 (starting at 1) of failedAttempts.";
    }
    output->writeVarShort((int)this->failedAttempts[_i9]);
  }
}

void IdentificationMessage::deserialize(Reader *input)
{
  this->deserializeAs_IdentificationMessage(input);
}

void IdentificationMessage::deserializeAs_IdentificationMessage(Reader *input)
{
  auto _val3 = 0;
  uint _val9 = 0;
  this->deserializeByteBoxes(input);
  this->version = Version();
  this->version.deserialize(input);
  this->_langFunc(input);
  uint _credentialsLen = input->readVarInt();
  for(uint _i3 = 0; _i3 < _credentialsLen; _i3++)
  {
    _val3 = input->readByte();
    this->credentials.append(_val3);
  }
  this->_serverIdFunc(input);
  this->_sessionOptionalSaltFunc(input);
  uint _failedAttemptsLen = input->readUShort();
  for(uint _i9 = 0; _i9 < _failedAttemptsLen; _i9++)
  {
    _val9 = input->readVarUhShort();
    if(_val9 < 0)
    {
      qDebug()<<"ERREUR - IdentificationMessage -"<<"Forbidden value (" << _val9 << ") on elements of failedAttempts.";
    }
    this->failedAttempts.append(_val9);
  }
}

void IdentificationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IdentificationMessage(tree);
}

void IdentificationMessage::deserializeAsyncAs_IdentificationMessage(FuncTree tree)
{
  tree.addChild(std::bind(&IdentificationMessage::deserializeByteBoxes, this, std::placeholders::_1));
  this->_versiontree = tree.addChild(std::bind(&IdentificationMessage::_versiontreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IdentificationMessage::_langFunc, this, std::placeholders::_1));
  this->_credentialstree = tree.addChild(std::bind(&IdentificationMessage::_credentialstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IdentificationMessage::_serverIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IdentificationMessage::_sessionOptionalSaltFunc, this, std::placeholders::_1));
  this->_failedAttemptstree = tree.addChild(std::bind(&IdentificationMessage::_failedAttemptstreeFunc, this, std::placeholders::_1));
}

void IdentificationMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->autoconnect = BooleanByteWrapper::getFlag(_box0, 0);
  this->useCertificate = BooleanByteWrapper::getFlag(_box0, 1);
  this->useLoginToken = BooleanByteWrapper::getFlag(_box0, 2);
}

void IdentificationMessage::_versiontreeFunc(Reader *input)
{
  this->version = Version();
  this->version.deserializeAsync(this->_versiontree);
}

void IdentificationMessage::_langFunc(Reader *input)
{
  this->lang = input->readUTF();
}

void IdentificationMessage::_credentialstreeFunc(Reader *input)
{
  uint length = input->readVarInt();
  for(uint i = 0; i < length; i++)
  {
    this->_credentialstree.addChild(std::bind(&IdentificationMessage::_credentialsFunc, this, std::placeholders::_1));
  }
}

void IdentificationMessage::_credentialsFunc(Reader *input)
{
  int _val = input->readByte();
  this->credentials.append(_val);
}

void IdentificationMessage::_serverIdFunc(Reader *input)
{
  this->serverId = input->readShort();
}

void IdentificationMessage::_sessionOptionalSaltFunc(Reader *input)
{
  this->sessionOptionalSalt = input->readVarLong();
  if(this->sessionOptionalSalt < -9.007199254740992E15 || this->sessionOptionalSalt > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IdentificationMessage -"<<"Forbidden value (" << this->sessionOptionalSalt << ") on element of IdentificationMessage.sessionOptionalSalt.";
  }
}

void IdentificationMessage::_failedAttemptstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_failedAttemptstree.addChild(std::bind(&IdentificationMessage::_failedAttemptsFunc, this, std::placeholders::_1));
  }
}

void IdentificationMessage::_failedAttemptsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - IdentificationMessage -"<<"Forbidden value (" << _val << ") on elements of failedAttempts.";
  }
  this->failedAttempts.append(_val);
}

IdentificationMessage::IdentificationMessage()
{
  m_type = MessageEnum::IDENTIFICATIONMESSAGE;
}

