#include "EmotePlayErrorMessage.h"

void EmotePlayErrorMessage::serialize(Writer *output)
{
  this->serializeAs_EmotePlayErrorMessage(output);
}

void EmotePlayErrorMessage::serializeAs_EmotePlayErrorMessage(Writer *output)
{
  if(this->emoteId < 0 || this->emoteId > 65535)
  {
    qDebug()<<"ERREUR - EmotePlayErrorMessage -"<<"Forbidden value (" << this->emoteId << ") on element emoteId.";
  }
  output->writeShort((short)this->emoteId);
}

void EmotePlayErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_EmotePlayErrorMessage(input);
}

void EmotePlayErrorMessage::deserializeAs_EmotePlayErrorMessage(Reader *input)
{
  this->_emoteIdFunc(input);
}

void EmotePlayErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_EmotePlayErrorMessage(tree);
}

void EmotePlayErrorMessage::deserializeAsyncAs_EmotePlayErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&EmotePlayErrorMessage::_emoteIdFunc, this, std::placeholders::_1));
}

void EmotePlayErrorMessage::_emoteIdFunc(Reader *input)
{
  this->emoteId = input->readUShort();
  if(this->emoteId < 0 || this->emoteId > 65535)
  {
    qDebug()<<"ERREUR - EmotePlayErrorMessage -"<<"Forbidden value (" << this->emoteId << ") on element of EmotePlayErrorMessage.emoteId.";
  }
}

EmotePlayErrorMessage::EmotePlayErrorMessage()
{
  m_type = MessageEnum::EMOTEPLAYERRORMESSAGE;
}

