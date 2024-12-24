#include "OnConnectionEventMessage.h"

void OnConnectionEventMessage::serialize(Writer *output)
{
  this->serializeAs_OnConnectionEventMessage(output);
}

void OnConnectionEventMessage::serializeAs_OnConnectionEventMessage(Writer *output)
{
  output->writeByte(this->eventType);
}

void OnConnectionEventMessage::deserialize(Reader *input)
{
  this->deserializeAs_OnConnectionEventMessage(input);
}

void OnConnectionEventMessage::deserializeAs_OnConnectionEventMessage(Reader *input)
{
  this->_eventTypeFunc(input);
}

void OnConnectionEventMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_OnConnectionEventMessage(tree);
}

void OnConnectionEventMessage::deserializeAsyncAs_OnConnectionEventMessage(FuncTree tree)
{
  tree.addChild(std::bind(&OnConnectionEventMessage::_eventTypeFunc, this, std::placeholders::_1));
}

void OnConnectionEventMessage::_eventTypeFunc(Reader *input)
{
  this->eventType = input->readByte();
  if(this->eventType < 0)
  {
    qDebug()<<"ERREUR - OnConnectionEventMessage -"<<"Forbidden value (" << this->eventType << ") on element of OnConnectionEventMessage.eventType.";
  }
}

OnConnectionEventMessage::OnConnectionEventMessage()
{
  m_type = MessageEnum::ONCONNECTIONEVENTMESSAGE;
}

