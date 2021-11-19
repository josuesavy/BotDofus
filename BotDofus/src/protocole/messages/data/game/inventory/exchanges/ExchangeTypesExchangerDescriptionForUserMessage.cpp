#include "ExchangeTypesExchangerDescriptionForUserMessage.h"

void ExchangeTypesExchangerDescriptionForUserMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeTypesExchangerDescriptionForUserMessage(output);
}

void ExchangeTypesExchangerDescriptionForUserMessage::serializeAs_ExchangeTypesExchangerDescriptionForUserMessage(Writer *output)
{
  if(this->objectType < 0)
  {
    qDebug()<<"ERREUR - ExchangeTypesExchangerDescriptionForUserMessage -"<<"Forbidden value (" << this->objectType << ") on element objectType.";
  }
  output->writeInt((int)this->objectType);
  output->writeShort((short)this->typeDescription.size());
  for(uint _i2 = 0; _i2 < this->typeDescription.size(); _i2++)
  {
    if(this->typeDescription[_i2] < 0)
    {
      qDebug()<<"ERREUR - ExchangeTypesExchangerDescriptionForUserMessage -"<<"Forbidden value (" << this->typeDescription[_i2] << ") on element 2 (starting at 1) of typeDescription.";
    }
    output->writeVarInt((int)this->typeDescription[_i2]);
  }
}

void ExchangeTypesExchangerDescriptionForUserMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeTypesExchangerDescriptionForUserMessage(input);
}

void ExchangeTypesExchangerDescriptionForUserMessage::deserializeAs_ExchangeTypesExchangerDescriptionForUserMessage(Reader *input)
{
  uint _val2 = 0;
  this->_objectTypeFunc(input);
  uint _typeDescriptionLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _typeDescriptionLen; _i2++)
  {
    _val2 = input->readVarUhInt();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - ExchangeTypesExchangerDescriptionForUserMessage -"<<"Forbidden value (" << _val2 << ") on elements of typeDescription.";
    }
    this->typeDescription.append(_val2);
  }
}

void ExchangeTypesExchangerDescriptionForUserMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeTypesExchangerDescriptionForUserMessage(tree);
}

void ExchangeTypesExchangerDescriptionForUserMessage::deserializeAsyncAs_ExchangeTypesExchangerDescriptionForUserMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeTypesExchangerDescriptionForUserMessage::_objectTypeFunc, this, std::placeholders::_1));
  this->_typeDescriptiontree = tree.addChild(std::bind(&ExchangeTypesExchangerDescriptionForUserMessage::_typeDescriptiontreeFunc, this, std::placeholders::_1));
}

void ExchangeTypesExchangerDescriptionForUserMessage::_objectTypeFunc(Reader *input)
{
  this->objectType = input->readInt();
  if(this->objectType < 0)
  {
    qDebug()<<"ERREUR - ExchangeTypesExchangerDescriptionForUserMessage -"<<"Forbidden value (" << this->objectType << ") on element of ExchangeTypesExchangerDescriptionForUserMessage.objectType.";
  }
}

void ExchangeTypesExchangerDescriptionForUserMessage::_typeDescriptiontreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_typeDescriptiontree.addChild(std::bind(&ExchangeTypesExchangerDescriptionForUserMessage::_typeDescriptionFunc, this, std::placeholders::_1));
  }
}

void ExchangeTypesExchangerDescriptionForUserMessage::_typeDescriptionFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ExchangeTypesExchangerDescriptionForUserMessage -"<<"Forbidden value (" << _val << ") on elements of typeDescription.";
  }
  this->typeDescription.append(_val);
}

ExchangeTypesExchangerDescriptionForUserMessage::ExchangeTypesExchangerDescriptionForUserMessage()
{
  m_type = MessageEnum::EXCHANGETYPESEXCHANGERDESCRIPTIONFORUSERMESSAGE;
}

