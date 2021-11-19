#include "FocusedExchangeReadyMessage.h"

void FocusedExchangeReadyMessage::serialize(Writer *output)
{
  this->serializeAs_FocusedExchangeReadyMessage(output);
}

void FocusedExchangeReadyMessage::serializeAs_FocusedExchangeReadyMessage(Writer *output)
{
  ExchangeReadyMessage::serializeAs_ExchangeReadyMessage(output);
  if(this->focusActionId < 0)
  {
    qDebug()<<"ERREUR - FocusedExchangeReadyMessage -"<<"Forbidden value (" << this->focusActionId << ") on element focusActionId.";
  }
  output->writeVarInt((int)this->focusActionId);
}

void FocusedExchangeReadyMessage::deserialize(Reader *input)
{
  this->deserializeAs_FocusedExchangeReadyMessage(input);
}

void FocusedExchangeReadyMessage::deserializeAs_FocusedExchangeReadyMessage(Reader *input)
{
  ExchangeReadyMessage::deserialize(input);
  this->_focusActionIdFunc(input);
}

void FocusedExchangeReadyMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FocusedExchangeReadyMessage(tree);
}

void FocusedExchangeReadyMessage::deserializeAsyncAs_FocusedExchangeReadyMessage(FuncTree tree)
{
  ExchangeReadyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&FocusedExchangeReadyMessage::_focusActionIdFunc, this, std::placeholders::_1));
}

void FocusedExchangeReadyMessage::_focusActionIdFunc(Reader *input)
{
  this->focusActionId = input->readVarUhInt();
  if(this->focusActionId < 0)
  {
    qDebug()<<"ERREUR - FocusedExchangeReadyMessage -"<<"Forbidden value (" << this->focusActionId << ") on element of FocusedExchangeReadyMessage.focusActionId.";
  }
}

FocusedExchangeReadyMessage::FocusedExchangeReadyMessage()
{
  m_type = MessageEnum::FOCUSEDEXCHANGEREADYMESSAGE;
  m_needsHash = true;
}

