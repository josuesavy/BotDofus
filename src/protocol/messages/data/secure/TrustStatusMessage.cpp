#include "TrustStatusMessage.h"

void TrustStatusMessage::serialize(Writer *output)
{
  this->serializeAs_TrustStatusMessage(output);
}

void TrustStatusMessage::serializeAs_TrustStatusMessage(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->trusted);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->certified);
  output->writeByte(_box0);
}

void TrustStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_TrustStatusMessage(input);
}

void TrustStatusMessage::deserializeAs_TrustStatusMessage(Reader *input)
{
  this->deserializeByteBoxes(input);
}

void TrustStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TrustStatusMessage(tree);
}

void TrustStatusMessage::deserializeAsyncAs_TrustStatusMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TrustStatusMessage::deserializeByteBoxes, this, std::placeholders::_1));
}

void TrustStatusMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->trusted = BooleanByteWrapper::getFlag(_box0, 0);
  this->certified = BooleanByteWrapper::getFlag(_box0, 1);
}

TrustStatusMessage::TrustStatusMessage()
{
  m_type = MessageEnum::TRUSTSTATUSMESSAGE;
}

