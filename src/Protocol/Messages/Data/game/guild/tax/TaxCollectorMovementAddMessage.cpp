#include "TaxCollectorMovementAddMessage.h"

void TaxCollectorMovementAddMessage::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorMovementAddMessage(output);
}

void TaxCollectorMovementAddMessage::serializeAs_TaxCollectorMovementAddMessage(Writer *output)
{
  output->writeShort((short)this->informations->getTypes().last());
  this->informations->serialize(output);
}

void TaxCollectorMovementAddMessage::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorMovementAddMessage(input);
}

void TaxCollectorMovementAddMessage::deserializeAs_TaxCollectorMovementAddMessage(Reader *input)
{
  uint _id1 = input->readUShort();
  this->informations = qSharedPointerCast<TaxCollectorInformations>(ClassManagerSingleton::get()->getClass(_id1));
  this->informations->deserialize(input);
}

void TaxCollectorMovementAddMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorMovementAddMessage(tree);
}

void TaxCollectorMovementAddMessage::deserializeAsyncAs_TaxCollectorMovementAddMessage(FuncTree tree)
{
  this->_informationstree = tree.addChild(std::bind(&TaxCollectorMovementAddMessage::_informationstreeFunc, this, std::placeholders::_1));
}

void TaxCollectorMovementAddMessage::_informationstreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->informations = qSharedPointerCast<TaxCollectorInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->informations->deserializeAsync(this->_informationstree);
}

TaxCollectorMovementAddMessage::TaxCollectorMovementAddMessage()
{
  m_type = MessageEnum::TAXCOLLECTORMOVEMENTADDMESSAGE;
}

