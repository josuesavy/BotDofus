#include "EmoteAddMessage.h"

void EmoteAddMessage::serialize(Writer *output)
{
  this->serializeAs_EmoteAddMessage(output);
}

void EmoteAddMessage::serializeAs_EmoteAddMessage(Writer *output)
{
  if(this->emoteId < 0 || this->emoteId > 65535)
  {
    qDebug()<<"ERREUR - EmoteAddMessage -"<<"Forbidden value (" << this->emoteId << ") on element emoteId.";
  }
  output->writeShort((short)this->emoteId);
}

void EmoteAddMessage::deserialize(Reader *input)
{
  this->deserializeAs_EmoteAddMessage(input);
}

void EmoteAddMessage::deserializeAs_EmoteAddMessage(Reader *input)
{
  this->_emoteIdFunc(input);
}

void EmoteAddMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_EmoteAddMessage(tree);
}

void EmoteAddMessage::deserializeAsyncAs_EmoteAddMessage(FuncTree tree)
{
  tree.addChild(std::bind(&EmoteAddMessage::_emoteIdFunc, this, std::placeholders::_1));
}

void EmoteAddMessage::_emoteIdFunc(Reader *input)
{
  this->emoteId = input->readUShort();
  if(this->emoteId < 0 || this->emoteId > 65535)
  {
    qDebug()<<"ERREUR - EmoteAddMessage -"<<"Forbidden value (" << this->emoteId << ") on element of EmoteAddMessage.emoteId.";
  }
}

EmoteAddMessage::EmoteAddMessage()
{
  m_type = MessageEnum::EMOTEADDMESSAGE;
}

