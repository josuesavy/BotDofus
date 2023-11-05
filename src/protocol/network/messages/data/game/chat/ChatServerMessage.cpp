#include "ChatServerMessage.h"

void ChatServerMessage::serialize(Writer *output)
{
  this->serializeAs_ChatServerMessage(output);
}

void ChatServerMessage::serializeAs_ChatServerMessage(Writer *output)
{
  ChatAbstractServerMessage::serializeAs_ChatAbstractServerMessage(output);
  if(this->senderId < -9007199254740992 || this->senderId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ChatServerMessage -"<<"Forbidden value (" << this->senderId << ") on element senderId.";
  }
  output->writeDouble(this->senderId);
  output->writeUTF(this->senderName);
  output->writeUTF(this->prefix);
  if(this->senderAccountId < 0)
  {
    qDebug()<<"ERREUR - ChatServerMessage -"<<"Forbidden value (" << this->senderAccountId << ") on element senderAccountId.";
  }
  output->writeInt((int)this->senderAccountId);
}

void ChatServerMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChatServerMessage(input);
}

void ChatServerMessage::deserializeAs_ChatServerMessage(Reader *input)
{
  ChatAbstractServerMessage::deserialize(input);
  this->_senderIdFunc(input);
  this->_senderNameFunc(input);
  this->_prefixFunc(input);
  this->_senderAccountIdFunc(input);
}

void ChatServerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChatServerMessage(tree);
}

void ChatServerMessage::deserializeAsyncAs_ChatServerMessage(FuncTree tree)
{
  ChatAbstractServerMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ChatServerMessage::_senderIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChatServerMessage::_senderNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChatServerMessage::_prefixFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChatServerMessage::_senderAccountIdFunc, this, std::placeholders::_1));
}

void ChatServerMessage::_senderIdFunc(Reader *input)
{
  this->senderId = input->readDouble();
  if(this->senderId < -9007199254740992 || this->senderId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ChatServerMessage -"<<"Forbidden value (" << this->senderId << ") on element of ChatServerMessage.senderId.";
  }
}

void ChatServerMessage::_senderNameFunc(Reader *input)
{
  this->senderName = input->readUTF();
}

void ChatServerMessage::_prefixFunc(Reader *input)
{
  this->prefix = input->readUTF();
}

void ChatServerMessage::_senderAccountIdFunc(Reader *input)
{
  this->senderAccountId = input->readInt();
  if(this->senderAccountId < 0)
  {
    qDebug()<<"ERREUR - ChatServerMessage -"<<"Forbidden value (" << this->senderAccountId << ") on element of ChatServerMessage.senderAccountId.";
  }
}

ChatServerMessage::ChatServerMessage()
{
  m_type = MessageEnum::CHATSERVERMESSAGE;
}

