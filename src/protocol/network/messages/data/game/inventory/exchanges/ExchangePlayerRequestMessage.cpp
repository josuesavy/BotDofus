#include "ExchangePlayerRequestMessage.h"

void ExchangePlayerRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangePlayerRequestMessage(output);
}

void ExchangePlayerRequestMessage::serializeAs_ExchangePlayerRequestMessage(Writer *output)
{
  ExchangeRequestMessage::serializeAs_ExchangeRequestMessage(output);
  if(this->target < 0 || this->target > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangePlayerRequestMessage -"<<"Forbidden value (" << this->target << ") on element target.";
  }
  output->writeVarLong((double)this->target);
}

void ExchangePlayerRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangePlayerRequestMessage(input);
}

void ExchangePlayerRequestMessage::deserializeAs_ExchangePlayerRequestMessage(Reader *input)
{
  ExchangeRequestMessage::deserialize(input);
  this->_targetFunc(input);
}

void ExchangePlayerRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangePlayerRequestMessage(tree);
}

void ExchangePlayerRequestMessage::deserializeAsyncAs_ExchangePlayerRequestMessage(FuncTree tree)
{
  ExchangeRequestMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ExchangePlayerRequestMessage::_targetFunc, this, std::placeholders::_1));
}

void ExchangePlayerRequestMessage::_targetFunc(Reader *input)
{
  this->target = input->readVarUhLong();
  if(this->target < 0 || this->target > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangePlayerRequestMessage -"<<"Forbidden value (" << this->target << ") on element of ExchangePlayerRequestMessage.target.";
  }
}

ExchangePlayerRequestMessage::ExchangePlayerRequestMessage()
{
  m_type = MessageEnum::EXCHANGEPLAYERREQUESTMESSAGE;
  m_needsHash = true;
}

