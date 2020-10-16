#include "ChatSmileyMessage.h"

void ChatSmileyMessage::serialize(Writer *output)
{
  this->serializeAs_ChatSmileyMessage(output);
}

void ChatSmileyMessage::serializeAs_ChatSmileyMessage(Writer *output)
{
  if(this->entityId < -9.007199254740992E15 || this->entityId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ChatSmileyMessage -"<<"Forbidden value (" << this->entityId << ") on element entityId.";
  }
  output->writeDouble(this->entityId);
  if(this->smileyId < 0)
  {
    qDebug()<<"ERREUR - ChatSmileyMessage -"<<"Forbidden value (" << this->smileyId << ") on element smileyId.";
  }
  output->writeVarShort((int)this->smileyId);
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - ChatSmileyMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  output->writeInt((int)this->accountId);
}

void ChatSmileyMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChatSmileyMessage(input);
}

void ChatSmileyMessage::deserializeAs_ChatSmileyMessage(Reader *input)
{
  this->_entityIdFunc(input);
  this->_smileyIdFunc(input);
  this->_accountIdFunc(input);
}

void ChatSmileyMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChatSmileyMessage(tree);
}

void ChatSmileyMessage::deserializeAsyncAs_ChatSmileyMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChatSmileyMessage::_entityIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChatSmileyMessage::_smileyIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChatSmileyMessage::_accountIdFunc, this, std::placeholders::_1));
}

void ChatSmileyMessage::_entityIdFunc(Reader *input)
{
  this->entityId = input->readDouble();
  if(this->entityId < -9.007199254740992E15 || this->entityId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ChatSmileyMessage -"<<"Forbidden value (" << this->entityId << ") on element of ChatSmileyMessage.entityId.";
  }
}

void ChatSmileyMessage::_smileyIdFunc(Reader *input)
{
  this->smileyId = input->readVarUhShort();
  if(this->smileyId < 0)
  {
    qDebug()<<"ERREUR - ChatSmileyMessage -"<<"Forbidden value (" << this->smileyId << ") on element of ChatSmileyMessage.smileyId.";
  }
}

void ChatSmileyMessage::_accountIdFunc(Reader *input)
{
  this->accountId = input->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - ChatSmileyMessage -"<<"Forbidden value (" << this->accountId << ") on element of ChatSmileyMessage.accountId.";
  }
}

ChatSmileyMessage::ChatSmileyMessage()
{
  m_type = MessageEnum::CHATSMILEYMESSAGE;
}

