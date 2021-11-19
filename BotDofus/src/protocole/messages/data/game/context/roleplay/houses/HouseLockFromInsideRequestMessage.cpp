#include "HouseLockFromInsideRequestMessage.h"

void HouseLockFromInsideRequestMessage::serialize(Writer *output)
{
  this->serializeAs_HouseLockFromInsideRequestMessage(output);
}

void HouseLockFromInsideRequestMessage::serializeAs_HouseLockFromInsideRequestMessage(Writer *output)
{
  LockableChangeCodeMessage::serializeAs_LockableChangeCodeMessage(output);
}

void HouseLockFromInsideRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_HouseLockFromInsideRequestMessage(input);
}

void HouseLockFromInsideRequestMessage::deserializeAs_HouseLockFromInsideRequestMessage(Reader *input)
{
  LockableChangeCodeMessage::deserialize(input);
}

void HouseLockFromInsideRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseLockFromInsideRequestMessage(tree);
}

void HouseLockFromInsideRequestMessage::deserializeAsyncAs_HouseLockFromInsideRequestMessage(FuncTree tree)
{
  LockableChangeCodeMessage::deserializeAsync(tree);
}

HouseLockFromInsideRequestMessage::HouseLockFromInsideRequestMessage()
{
  m_type = MessageEnum::HOUSELOCKFROMINSIDEREQUESTMESSAGE;
}

