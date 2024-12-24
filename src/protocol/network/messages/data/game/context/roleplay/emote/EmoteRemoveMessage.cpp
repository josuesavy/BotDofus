#include "EmoteRemoveMessage.h"

void EmoteRemoveMessage::serialize(Writer *output)
{
  this->serializeAs_EmoteRemoveMessage(output);
}

void EmoteRemoveMessage::serializeAs_EmoteRemoveMessage(Writer *output)
{
  if(this->emoteId < 0 || this->emoteId > 65535)
  {
    qDebug()<<"ERREUR - EmoteRemoveMessage -"<<"Forbidden value (" << this->emoteId << ") on element emoteId.";
  }
  output->writeShort((short)this->emoteId);
}

void EmoteRemoveMessage::deserialize(Reader *input)
{
  this->deserializeAs_EmoteRemoveMessage(input);
}

void EmoteRemoveMessage::deserializeAs_EmoteRemoveMessage(Reader *input)
{
  this->_emoteIdFunc(input);
}

void EmoteRemoveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_EmoteRemoveMessage(tree);
}

void EmoteRemoveMessage::deserializeAsyncAs_EmoteRemoveMessage(FuncTree tree)
{
  tree.addChild(std::bind(&EmoteRemoveMessage::_emoteIdFunc, this, std::placeholders::_1));
}

void EmoteRemoveMessage::_emoteIdFunc(Reader *input)
{
  this->emoteId = input->readUShort();
  if(this->emoteId < 0 || this->emoteId > 65535)
  {
    qDebug()<<"ERREUR - EmoteRemoveMessage -"<<"Forbidden value (" << this->emoteId << ") on element of EmoteRemoveMessage.emoteId.";
  }
}

EmoteRemoveMessage::EmoteRemoveMessage()
{
  m_type = MessageEnum::EMOTEREMOVEMESSAGE;
}

