#include "IdentifiedEntityDispositionInformations.h"

void IdentifiedEntityDispositionInformations::serialize(Writer *output)
{
  this->serializeAs_IdentifiedEntityDispositionInformations(output);
}

void IdentifiedEntityDispositionInformations::serializeAs_IdentifiedEntityDispositionInformations(Writer *output)
{
  EntityDispositionInformations::serializeAs_EntityDispositionInformations(output);
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IdentifiedEntityDispositionInformations -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeDouble(this->id);
}

void IdentifiedEntityDispositionInformations::deserialize(Reader *input)
{
  this->deserializeAs_IdentifiedEntityDispositionInformations(input);
}

void IdentifiedEntityDispositionInformations::deserializeAs_IdentifiedEntityDispositionInformations(Reader *input)
{
  EntityDispositionInformations::deserialize(input);
  this->_idFunc(input);
}

void IdentifiedEntityDispositionInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IdentifiedEntityDispositionInformations(tree);
}

void IdentifiedEntityDispositionInformations::deserializeAsyncAs_IdentifiedEntityDispositionInformations(FuncTree tree)
{
  EntityDispositionInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&IdentifiedEntityDispositionInformations::_idFunc, this, std::placeholders::_1));
}

void IdentifiedEntityDispositionInformations::_idFunc(Reader *input)
{
  this->id = input->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IdentifiedEntityDispositionInformations -"<<"Forbidden value (" << this->id << ") on element of IdentifiedEntityDispositionInformations.id.";
  }
}

IdentifiedEntityDispositionInformations::IdentifiedEntityDispositionInformations()
{
  m_types<<ClassEnum::IDENTIFIEDENTITYDISPOSITIONINFORMATIONS;
}

bool IdentifiedEntityDispositionInformations::operator==(const IdentifiedEntityDispositionInformations &compared)
{
  if(id == compared.id)
  return true;
  
  return false;
}

