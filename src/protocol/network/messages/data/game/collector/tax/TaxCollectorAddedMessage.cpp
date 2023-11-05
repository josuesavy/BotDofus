#include "TaxCollectorAddedMessage.h"

void TaxCollectorAddedMessage::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorAddedMessage(output);
}

void TaxCollectorAddedMessage::serializeAs_TaxCollectorAddedMessage(Writer *output)
{
  if(this->callerId < 0 || this->callerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TaxCollectorAddedMessage -"<<"Forbidden value (" << this->callerId << ") on element callerId.";
  }
  output->writeVarLong((double)this->callerId);
  output->writeShort((short)this->description->getTypes().last());
  this->description->serialize(output);
}

void TaxCollectorAddedMessage::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorAddedMessage(input);
}

void TaxCollectorAddedMessage::deserializeAs_TaxCollectorAddedMessage(Reader *input)
{
  this->_callerIdFunc(input);
  uint _id2 = uint(input->readUShort());
  this->description = qSharedPointerCast<TaxCollectorInformations>(ClassManagerSingleton::get()->getClass(_id2));
  this->description->deserialize(input);
}

void TaxCollectorAddedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorAddedMessage(tree);
}

void TaxCollectorAddedMessage::deserializeAsyncAs_TaxCollectorAddedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TaxCollectorAddedMessage::_callerIdFunc, this, std::placeholders::_1));
  this->_descriptiontree = tree.addChild(std::bind(&TaxCollectorAddedMessage::_descriptiontreeFunc, this, std::placeholders::_1));
}

void TaxCollectorAddedMessage::_callerIdFunc(Reader *input)
{
  this->callerId = input->readVarUhLong();
  if(this->callerId < 0 || this->callerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TaxCollectorAddedMessage -"<<"Forbidden value (" << this->callerId << ") on element of TaxCollectorAddedMessage.callerId.";
  }
}

void TaxCollectorAddedMessage::_descriptiontreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->description = qSharedPointerCast<TaxCollectorInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->description->deserializeAsync(this->_descriptiontree);
}

TaxCollectorAddedMessage::TaxCollectorAddedMessage()
{
  m_type = MessageEnum::TAXCOLLECTORADDEDMESSAGE;
}

