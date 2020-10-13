#include "KamasUpdateMessage.h"

void KamasUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_KamasUpdateMessage(output);
}

void KamasUpdateMessage::serializeAs_KamasUpdateMessage(Writer *output)
{
  if(this->kamasTotal < 0 || this->kamasTotal > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - KamasUpdateMessage -"<<"Forbidden value (" << this->kamasTotal << ") on element kamasTotal.";
  }
  output->writeVarLong((double)this->kamasTotal);
}

void KamasUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_KamasUpdateMessage(input);
}

void KamasUpdateMessage::deserializeAs_KamasUpdateMessage(Reader *input)
{
  this->_kamasTotalFunc(input);
}

void KamasUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_KamasUpdateMessage(tree);
}

void KamasUpdateMessage::deserializeAsyncAs_KamasUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&KamasUpdateMessage::_kamasTotalFunc, this, std::placeholders::_1));
}

void KamasUpdateMessage::_kamasTotalFunc(Reader *input)
{
  this->kamasTotal = input->readVarUhLong();
  if(this->kamasTotal < 0 || this->kamasTotal > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - KamasUpdateMessage -"<<"Forbidden value (" << this->kamasTotal << ") on element of KamasUpdateMessage.kamasTotal.";
  }
}

KamasUpdateMessage::KamasUpdateMessage()
{
  m_type = MessageEnum::KAMASUPDATEMESSAGE;
}

