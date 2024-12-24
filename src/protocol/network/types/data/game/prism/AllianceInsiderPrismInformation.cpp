#include "AllianceInsiderPrismInformation.h"

void AllianceInsiderPrismInformation::serialize(Writer *output)
{
  this->serializeAs_AllianceInsiderPrismInformation(output);
}

void AllianceInsiderPrismInformation::serializeAs_AllianceInsiderPrismInformation(Writer *output)
{
  PrismInformation::serializeAs_PrismInformation(output);
  this->moduleObject->serializeAs_ObjectItem(output);
  output->writeInt((int)this->moduleType);
  this->cristalObject->serializeAs_ObjectItem(output);
  output->writeInt((int)this->cristalType);
  if(this->cristalNumberLeft < 0)
  {
    qDebug()<<"ERREUR - AllianceInsiderPrismInformation -"<<"Forbidden value (" << this->cristalNumberLeft << ") on element cristalNumberLeft.";
  }
  output->writeInt((int)this->cristalNumberLeft);
}

void AllianceInsiderPrismInformation::deserialize(Reader *input)
{
  this->deserializeAs_AllianceInsiderPrismInformation(input);
}

void AllianceInsiderPrismInformation::deserializeAs_AllianceInsiderPrismInformation(Reader *input)
{
  PrismInformation::deserialize(input);
  this->moduleObject = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->moduleObject->deserialize(input);
  this->_moduleTypeFunc(input);
  this->cristalObject = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->cristalObject->deserialize(input);
  this->_cristalTypeFunc(input);
  this->_cristalNumberLeftFunc(input);
}

void AllianceInsiderPrismInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceInsiderPrismInformation(tree);
}

void AllianceInsiderPrismInformation::deserializeAsyncAs_AllianceInsiderPrismInformation(FuncTree tree)
{
  PrismInformation::deserializeAsync(tree);
  this->_moduleObjecttree = tree.addChild(std::bind(&AllianceInsiderPrismInformation::_moduleObjecttreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceInsiderPrismInformation::_moduleTypeFunc, this, std::placeholders::_1));
  this->_cristalObjecttree = tree.addChild(std::bind(&AllianceInsiderPrismInformation::_cristalObjecttreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceInsiderPrismInformation::_cristalTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceInsiderPrismInformation::_cristalNumberLeftFunc, this, std::placeholders::_1));
}

void AllianceInsiderPrismInformation::_moduleObjecttreeFunc(Reader *input)
{
  this->moduleObject = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->moduleObject->deserializeAsync(this->_moduleObjecttree);
}

void AllianceInsiderPrismInformation::_moduleTypeFunc(Reader *input)
{
  this->moduleType = input->readInt();
}

void AllianceInsiderPrismInformation::_cristalObjecttreeFunc(Reader *input)
{
  this->cristalObject = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->cristalObject->deserializeAsync(this->_cristalObjecttree);
}

void AllianceInsiderPrismInformation::_cristalTypeFunc(Reader *input)
{
  this->cristalType = input->readInt();
}

void AllianceInsiderPrismInformation::_cristalNumberLeftFunc(Reader *input)
{
  this->cristalNumberLeft = input->readInt();
  if(this->cristalNumberLeft < 0)
  {
    qDebug()<<"ERREUR - AllianceInsiderPrismInformation -"<<"Forbidden value (" << this->cristalNumberLeft << ") on element of AllianceInsiderPrismInformation.cristalNumberLeft.";
  }
}

AllianceInsiderPrismInformation::AllianceInsiderPrismInformation()
{
  m_types<<ClassEnum::ALLIANCEINSIDERPRISMINFORMATION;
}

bool AllianceInsiderPrismInformation::operator==(const AllianceInsiderPrismInformation &compared)
{
  if(moduleObject == compared.moduleObject)
  if(moduleType == compared.moduleType)
  if(cristalObject == compared.cristalObject)
  if(cristalType == compared.cristalType)
  if(cristalNumberLeft == compared.cristalNumberLeft)
  if(_moduleObjecttree == compared._moduleObjecttree)
  if(_cristalObjecttree == compared._cristalObjecttree)
  return true;
  
  return false;
}

