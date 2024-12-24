#include "EmotePlayMessage.h"

void EmotePlayMessage::serialize(Writer *output)
{
  this->serializeAs_EmotePlayMessage(output);
}

void EmotePlayMessage::serializeAs_EmotePlayMessage(Writer *output)
{
  EmotePlayAbstractMessage::serializeAs_EmotePlayAbstractMessage(output);
  if(this->actorId < -9007199254740992 || this->actorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - EmotePlayMessage -"<<"Forbidden value (" << this->actorId << ") on element actorId.";
  }
  output->writeDouble(this->actorId);
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - EmotePlayMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  output->writeInt((int)this->accountId);
}

void EmotePlayMessage::deserialize(Reader *input)
{
  this->deserializeAs_EmotePlayMessage(input);
}

void EmotePlayMessage::deserializeAs_EmotePlayMessage(Reader *input)
{
  EmotePlayAbstractMessage::deserialize(input);
  this->_actorIdFunc(input);
  this->_accountIdFunc(input);
}

void EmotePlayMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_EmotePlayMessage(tree);
}

void EmotePlayMessage::deserializeAsyncAs_EmotePlayMessage(FuncTree tree)
{
  EmotePlayAbstractMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&EmotePlayMessage::_actorIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&EmotePlayMessage::_accountIdFunc, this, std::placeholders::_1));
}

void EmotePlayMessage::_actorIdFunc(Reader *input)
{
  this->actorId = input->readDouble();
  if(this->actorId < -9007199254740992 || this->actorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - EmotePlayMessage -"<<"Forbidden value (" << this->actorId << ") on element of EmotePlayMessage.actorId.";
  }
}

void EmotePlayMessage::_accountIdFunc(Reader *input)
{
  this->accountId = input->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - EmotePlayMessage -"<<"Forbidden value (" << this->accountId << ") on element of EmotePlayMessage.accountId.";
  }
}

EmotePlayMessage::EmotePlayMessage()
{
  m_type = MessageEnum::EMOTEPLAYMESSAGE;
}

