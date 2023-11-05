#include "TaxCollectorEquipmentUpdateMessage.h"

void TaxCollectorEquipmentUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorEquipmentUpdateMessage(output);
}

void TaxCollectorEquipmentUpdateMessage::serializeAs_TaxCollectorEquipmentUpdateMessage(Writer *output)
{
  if(this->uniqueId < 0 || this->uniqueId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TaxCollectorEquipmentUpdateMessage -"<<"Forbidden value (" << this->uniqueId << ") on element uniqueId.";
  }
  output->writeDouble(this->uniqueId);
  this->object->serializeAs_ObjectItem(output);
  output->writeBool(this->added);
  this->characteristics.serializeAs_CharacterCharacteristics(output);
}

void TaxCollectorEquipmentUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorEquipmentUpdateMessage(input);
}

void TaxCollectorEquipmentUpdateMessage::deserializeAs_TaxCollectorEquipmentUpdateMessage(Reader *input)
{
  this->_uniqueIdFunc(input);
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserialize(input);
  this->_addedFunc(input);
  this->characteristics = CharacterCharacteristics();
  this->characteristics.deserialize(input);
}

void TaxCollectorEquipmentUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorEquipmentUpdateMessage(tree);
}

void TaxCollectorEquipmentUpdateMessage::deserializeAsyncAs_TaxCollectorEquipmentUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TaxCollectorEquipmentUpdateMessage::_uniqueIdFunc, this, std::placeholders::_1));
  this->_objecttree = tree.addChild(std::bind(&TaxCollectorEquipmentUpdateMessage::_objecttreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorEquipmentUpdateMessage::_addedFunc, this, std::placeholders::_1));
  this->_characteristicstree = tree.addChild(std::bind(&TaxCollectorEquipmentUpdateMessage::_characteristicstreeFunc, this, std::placeholders::_1));
}

void TaxCollectorEquipmentUpdateMessage::_uniqueIdFunc(Reader *input)
{
  this->uniqueId = input->readDouble();
  if(this->uniqueId < 0 || this->uniqueId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TaxCollectorEquipmentUpdateMessage -"<<"Forbidden value (" << this->uniqueId << ") on element of TaxCollectorEquipmentUpdateMessage.uniqueId.";
  }
}

void TaxCollectorEquipmentUpdateMessage::_objecttreeFunc(Reader *input)
{
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserializeAsync(this->_objecttree);
}

void TaxCollectorEquipmentUpdateMessage::_addedFunc(Reader *input)
{
  this->added = input->readBool();
}

void TaxCollectorEquipmentUpdateMessage::_characteristicstreeFunc(Reader *input)
{
  this->characteristics = CharacterCharacteristics();
  this->characteristics.deserializeAsync(this->_characteristicstree);
}

TaxCollectorEquipmentUpdateMessage::TaxCollectorEquipmentUpdateMessage()
{
  m_type = MessageEnum::TAXCOLLECTOREQUIPMENTUPDATEMESSAGE;
}

