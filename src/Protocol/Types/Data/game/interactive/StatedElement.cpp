#include "StatedElement.h"

void StatedElement::serialize(Writer *output)
{
  this->serializeAs_StatedElement(output);
}

void StatedElement::serializeAs_StatedElement(Writer *output)
{
  if(this->elementId < 0)
  {
    qDebug()<<"ERREUR - StatedElement -"<<"Forbidden value (" << this->elementId << ") on element elementId.";
  }
  output->writeInt((int)this->elementId);
  if(this->elementCellId < 0 || this->elementCellId > 559)
  {
    qDebug()<<"ERREUR - StatedElement -"<<"Forbidden value (" << this->elementCellId << ") on element elementCellId.";
  }
  output->writeVarShort((int)this->elementCellId);
  if(this->elementState < 0)
  {
    qDebug()<<"ERREUR - StatedElement -"<<"Forbidden value (" << this->elementState << ") on element elementState.";
  }
  output->writeVarInt((int)this->elementState);
  output->writeBool(this->onCurrentMap);
}

void StatedElement::deserialize(Reader *input)
{
  this->deserializeAs_StatedElement(input);
}

void StatedElement::deserializeAs_StatedElement(Reader *input)
{
  this->_elementIdFunc(input);
  this->_elementCellIdFunc(input);
  this->_elementStateFunc(input);
  this->_onCurrentMapFunc(input);
}

void StatedElement::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StatedElement(tree);
}

void StatedElement::deserializeAsyncAs_StatedElement(FuncTree tree)
{
  tree.addChild(std::bind(&StatedElement::_elementIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&StatedElement::_elementCellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&StatedElement::_elementStateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&StatedElement::_onCurrentMapFunc, this, std::placeholders::_1));
}

void StatedElement::_elementIdFunc(Reader *input)
{
  this->elementId = input->readInt();
  if(this->elementId < 0)
  {
    qDebug()<<"ERREUR - StatedElement -"<<"Forbidden value (" << this->elementId << ") on element of StatedElement.elementId.";
  }
}

void StatedElement::_elementCellIdFunc(Reader *input)
{
  this->elementCellId = input->readVarUhShort();
  if(this->elementCellId < 0 || this->elementCellId > 559)
  {
    qDebug()<<"ERREUR - StatedElement -"<<"Forbidden value (" << this->elementCellId << ") on element of StatedElement.elementCellId.";
  }
}

void StatedElement::_elementStateFunc(Reader *input)
{
  this->elementState = input->readVarUhInt();
  if(this->elementState < 0)
  {
    qDebug()<<"ERREUR - StatedElement -"<<"Forbidden value (" << this->elementState << ") on element of StatedElement.elementState.";
  }
}

void StatedElement::_onCurrentMapFunc(Reader *input)
{
  this->onCurrentMap = input->readBool();
}

StatedElement::StatedElement()
{
  m_types<<ClassEnum::STATEDELEMENT;
}

bool StatedElement::operator==(const StatedElement &compared)
{
  if(elementId == compared.elementId)
  if(elementCellId == compared.elementCellId)
  if(elementState == compared.elementState)
  if(onCurrentMap == compared.onCurrentMap)
  return true;
  
  return false;
}

