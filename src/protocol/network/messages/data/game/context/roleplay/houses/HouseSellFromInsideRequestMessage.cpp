#include "HouseSellFromInsideRequestMessage.h"

void HouseSellFromInsideRequestMessage::serialize(Writer *output)
{
  this->serializeAs_HouseSellFromInsideRequestMessage(output);
}

void HouseSellFromInsideRequestMessage::serializeAs_HouseSellFromInsideRequestMessage(Writer *output)
{
  HouseSellRequestMessage::serializeAs_HouseSellRequestMessage(output);
}

void HouseSellFromInsideRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_HouseSellFromInsideRequestMessage(input);
}

void HouseSellFromInsideRequestMessage::deserializeAs_HouseSellFromInsideRequestMessage(Reader *input)
{
  HouseSellRequestMessage::deserialize(input);
}

void HouseSellFromInsideRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseSellFromInsideRequestMessage(tree);
}

void HouseSellFromInsideRequestMessage::deserializeAsyncAs_HouseSellFromInsideRequestMessage(FuncTree tree)
{
  HouseSellRequestMessage::deserializeAsync(tree);
}

HouseSellFromInsideRequestMessage::HouseSellFromInsideRequestMessage()
{
  m_type = MessageEnum::HOUSESELLFROMINSIDEREQUESTMESSAGE;
}

