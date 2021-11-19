#include "ExchangeObjectMessage.h"

void ExchangeObjectMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeObjectMessage(output);
}

void ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(Writer *output)
{
  output->writeBool(this->remote);
}

void ExchangeObjectMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeObjectMessage(input);
}

void ExchangeObjectMessage::deserializeAs_ExchangeObjectMessage(Reader *input)
{
  this->_remoteFunc(input);
}

void ExchangeObjectMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeObjectMessage(tree);
}

void ExchangeObjectMessage::deserializeAsyncAs_ExchangeObjectMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeObjectMessage::_remoteFunc, this, std::placeholders::_1));
}

void ExchangeObjectMessage::_remoteFunc(Reader *input)
{
  this->remote = input->readBool();
}

ExchangeObjectMessage::ExchangeObjectMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTMESSAGE;
}

