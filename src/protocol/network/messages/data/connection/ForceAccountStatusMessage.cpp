#include "ForceAccountStatusMessage.h"

void ForceAccountStatusMessage::serialize(Writer *output)
{
  this->serializeAs_ForceAccountStatusMessage(output);
}

void ForceAccountStatusMessage::serializeAs_ForceAccountStatusMessage(Writer *output)
{
  output->writeBool(this->force);
  if(this->forcedAccountId < 0)
  {
    qDebug()<<"ERREUR - ForceAccountStatusMessage -"<<"Forbidden value (" << this->forcedAccountId << ") on element forcedAccountId.";
  }
  output->writeInt((int)this->forcedAccountId);
  output->writeUTF(this->forcedNickname);
  output->writeUTF(this->forcedTag);
}

void ForceAccountStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_ForceAccountStatusMessage(input);
}

void ForceAccountStatusMessage::deserializeAs_ForceAccountStatusMessage(Reader *input)
{
  this->_forceFunc(input);
  this->_forcedAccountIdFunc(input);
  this->_forcedNicknameFunc(input);
  this->_forcedTagFunc(input);
}

void ForceAccountStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ForceAccountStatusMessage(tree);
}

void ForceAccountStatusMessage::deserializeAsyncAs_ForceAccountStatusMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ForceAccountStatusMessage::_forceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ForceAccountStatusMessage::_forcedAccountIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ForceAccountStatusMessage::_forcedNicknameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ForceAccountStatusMessage::_forcedTagFunc, this, std::placeholders::_1));
}

void ForceAccountStatusMessage::_forceFunc(Reader *input)
{
  this->force = input->readBool();
}

void ForceAccountStatusMessage::_forcedAccountIdFunc(Reader *input)
{
  this->forcedAccountId = input->readInt();
  if(this->forcedAccountId < 0)
  {
    qDebug()<<"ERREUR - ForceAccountStatusMessage -"<<"Forbidden value (" << this->forcedAccountId << ") on element of ForceAccountStatusMessage.forcedAccountId.";
  }
}

void ForceAccountStatusMessage::_forcedNicknameFunc(Reader *input)
{
  this->forcedNickname = input->readUTF();
}

void ForceAccountStatusMessage::_forcedTagFunc(Reader *input)
{
  this->forcedTag = input->readUTF();
}

ForceAccountStatusMessage::ForceAccountStatusMessage()
{
  m_type = MessageEnum::FORCEACCOUNTSTATUSMESSAGE;
}

