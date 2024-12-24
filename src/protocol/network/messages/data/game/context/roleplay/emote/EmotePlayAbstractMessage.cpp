#include "EmotePlayAbstractMessage.h"

void EmotePlayAbstractMessage::serialize(Writer *output)
{
  this->serializeAs_EmotePlayAbstractMessage(output);
}

void EmotePlayAbstractMessage::serializeAs_EmotePlayAbstractMessage(Writer *output)
{
  if(this->emoteId < 0 || this->emoteId > 65535)
  {
    qDebug()<<"ERREUR - EmotePlayAbstractMessage -"<<"Forbidden value (" << this->emoteId << ") on element emoteId.";
  }
  output->writeShort((short)this->emoteId);
  if(this->emoteStartTime < -9007199254740992 || this->emoteStartTime > 9007199254740992)
  {
    qDebug()<<"ERREUR - EmotePlayAbstractMessage -"<<"Forbidden value (" << this->emoteStartTime << ") on element emoteStartTime.";
  }
  output->writeDouble(this->emoteStartTime);
}

void EmotePlayAbstractMessage::deserialize(Reader *input)
{
  this->deserializeAs_EmotePlayAbstractMessage(input);
}

void EmotePlayAbstractMessage::deserializeAs_EmotePlayAbstractMessage(Reader *input)
{
  this->_emoteIdFunc(input);
  this->_emoteStartTimeFunc(input);
}

void EmotePlayAbstractMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_EmotePlayAbstractMessage(tree);
}

void EmotePlayAbstractMessage::deserializeAsyncAs_EmotePlayAbstractMessage(FuncTree tree)
{
  tree.addChild(std::bind(&EmotePlayAbstractMessage::_emoteIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&EmotePlayAbstractMessage::_emoteStartTimeFunc, this, std::placeholders::_1));
}

void EmotePlayAbstractMessage::_emoteIdFunc(Reader *input)
{
  this->emoteId = input->readUShort();
  if(this->emoteId < 0 || this->emoteId > 65535)
  {
    qDebug()<<"ERREUR - EmotePlayAbstractMessage -"<<"Forbidden value (" << this->emoteId << ") on element of EmotePlayAbstractMessage.emoteId.";
  }
}

void EmotePlayAbstractMessage::_emoteStartTimeFunc(Reader *input)
{
  this->emoteStartTime = input->readDouble();
  if(this->emoteStartTime < -9007199254740992 || this->emoteStartTime > 9007199254740992)
  {
    qDebug()<<"ERREUR - EmotePlayAbstractMessage -"<<"Forbidden value (" << this->emoteStartTime << ") on element of EmotePlayAbstractMessage.emoteStartTime.";
  }
}

EmotePlayAbstractMessage::EmotePlayAbstractMessage()
{
  m_type = MessageEnum::EMOTEPLAYABSTRACTMESSAGE;
}

