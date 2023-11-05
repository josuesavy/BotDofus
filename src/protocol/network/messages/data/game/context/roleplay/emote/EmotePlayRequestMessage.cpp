#include "EmotePlayRequestMessage.h"

void EmotePlayRequestMessage::serialize(Writer *output)
{
  this->serializeAs_EmotePlayRequestMessage(output);
}

void EmotePlayRequestMessage::serializeAs_EmotePlayRequestMessage(Writer *output)
{
  if(this->emoteId < 0 || this->emoteId > 65535)
  {
    qDebug()<<"ERREUR - EmotePlayRequestMessage -"<<"Forbidden value (" << this->emoteId << ") on element emoteId.";
  }
  output->writeShort((short)this->emoteId);
}

void EmotePlayRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_EmotePlayRequestMessage(input);
}

void EmotePlayRequestMessage::deserializeAs_EmotePlayRequestMessage(Reader *input)
{
  this->_emoteIdFunc(input);
}

void EmotePlayRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_EmotePlayRequestMessage(tree);
}

void EmotePlayRequestMessage::deserializeAsyncAs_EmotePlayRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&EmotePlayRequestMessage::_emoteIdFunc, this, std::placeholders::_1));
}

void EmotePlayRequestMessage::_emoteIdFunc(Reader *input)
{
  this->emoteId = input->readUShort();
  if(this->emoteId < 0 || this->emoteId > 65535)
  {
    qDebug()<<"ERREUR - EmotePlayRequestMessage -"<<"Forbidden value (" << this->emoteId << ") on element of EmotePlayRequestMessage.emoteId.";
  }
}

EmotePlayRequestMessage::EmotePlayRequestMessage()
{
  m_type = MessageEnum::EMOTEPLAYREQUESTMESSAGE;
}

