#include "TrustStatusMessage.h"

void TrustStatusMessage::serialize(Writer *output)
{
  this->serializeAs_TrustStatusMessage(output);
}

void TrustStatusMessage::serializeAs_TrustStatusMessage(Writer *output)
{
  output->writeBool(this->certified);
}

void TrustStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_TrustStatusMessage(input);
}

void TrustStatusMessage::deserializeAs_TrustStatusMessage(Reader *input)
{
  this->_certifiedFunc(input);
}

void TrustStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TrustStatusMessage(tree);
}

void TrustStatusMessage::deserializeAsyncAs_TrustStatusMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TrustStatusMessage::_certifiedFunc, this, std::placeholders::_1));
}

void TrustStatusMessage::_certifiedFunc(Reader *input)
{
  this->certified = input->readBool();
}

TrustStatusMessage::TrustStatusMessage()
{
  m_type = MessageEnum::TRUSTSTATUSMESSAGE;
}

