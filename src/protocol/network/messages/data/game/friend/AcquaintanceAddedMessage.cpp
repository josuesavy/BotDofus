#include "AcquaintanceAddedMessage.h"

void AcquaintanceAddedMessage::serialize(Writer *output)
{
  this->serializeAs_AcquaintanceAddedMessage(output);
}

void AcquaintanceAddedMessage::serializeAs_AcquaintanceAddedMessage(Writer *output)
{
  output->writeShort((short)this->acquaintanceAdded->getTypes().last());
  this->acquaintanceAdded->serialize(output);
}

void AcquaintanceAddedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AcquaintanceAddedMessage(input);
}

void AcquaintanceAddedMessage::deserializeAs_AcquaintanceAddedMessage(Reader *input)
{
  uint _id1 = uint(input->readUShort());
  this->acquaintanceAdded = qSharedPointerCast<AcquaintanceInformation>(ClassManagerSingleton::get()->getClass(_id1));
  this->acquaintanceAdded->deserialize(input);
}

void AcquaintanceAddedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AcquaintanceAddedMessage(tree);
}

void AcquaintanceAddedMessage::deserializeAsyncAs_AcquaintanceAddedMessage(FuncTree tree)
{
  this->_acquaintanceAddedtree = tree.addChild(std::bind(&AcquaintanceAddedMessage::_acquaintanceAddedtreeFunc, this, std::placeholders::_1));
}

void AcquaintanceAddedMessage::_acquaintanceAddedtreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->acquaintanceAdded = qSharedPointerCast<AcquaintanceInformation>(ClassManagerSingleton::get()->getClass(_id));
  this->acquaintanceAdded->deserializeAsync(this->_acquaintanceAddedtree);
}

AcquaintanceAddedMessage::AcquaintanceAddedMessage()
{
  m_type = MessageEnum::ACQUAINTANCEADDEDMESSAGE;
}

