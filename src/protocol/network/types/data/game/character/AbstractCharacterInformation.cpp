#include "AbstractCharacterInformation.h"

void AbstractCharacterInformation::serialize(Writer *output)
{
  this->serializeAs_AbstractCharacterInformation(output);
}

void AbstractCharacterInformation::serializeAs_AbstractCharacterInformation(Writer *output)
{
  if(this->id < 0 || this->id > 9007199254740992)
  {
    qDebug()<<"ERREUR - AbstractCharacterInformation -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarLong((double)this->id);
}

void AbstractCharacterInformation::deserialize(Reader *input)
{
  this->deserializeAs_AbstractCharacterInformation(input);
}

void AbstractCharacterInformation::deserializeAs_AbstractCharacterInformation(Reader *input)
{
  this->_idFunc(input);
}

void AbstractCharacterInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AbstractCharacterInformation(tree);
}

void AbstractCharacterInformation::deserializeAsyncAs_AbstractCharacterInformation(FuncTree tree)
{
  tree.addChild(std::bind(&AbstractCharacterInformation::_idFunc, this, std::placeholders::_1));
}

void AbstractCharacterInformation::_idFunc(Reader *input)
{
  this->id = input->readVarUhLong();
  if(this->id < 0 || this->id > 9007199254740992)
  {
    qDebug()<<"ERREUR - AbstractCharacterInformation -"<<"Forbidden value (" << this->id << ") on element of AbstractCharacterInformation.id.";
  }
}

AbstractCharacterInformation::AbstractCharacterInformation()
{
  m_types<<ClassEnum::ABSTRACTCHARACTERINFORMATION;
}

bool AbstractCharacterInformation::operator==(const AbstractCharacterInformation &compared)
{
  if(id == compared.id)
  return true;
  
  return false;
}

