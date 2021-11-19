#include "ObjectUseOnCharacterMessage.h"

void ObjectUseOnCharacterMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectUseOnCharacterMessage(output);
}

void ObjectUseOnCharacterMessage::serializeAs_ObjectUseOnCharacterMessage(Writer *output)
{
  ObjectUseMessage::serializeAs_ObjectUseMessage(output);
  if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ObjectUseOnCharacterMessage -"<<"Forbidden value (" << this->characterId << ") on element characterId.";
  }
  output->writeVarLong((double)this->characterId);
}

void ObjectUseOnCharacterMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectUseOnCharacterMessage(input);
}

void ObjectUseOnCharacterMessage::deserializeAs_ObjectUseOnCharacterMessage(Reader *input)
{
  ObjectUseMessage::deserialize(input);
  this->_characterIdFunc(input);
}

void ObjectUseOnCharacterMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectUseOnCharacterMessage(tree);
}

void ObjectUseOnCharacterMessage::deserializeAsyncAs_ObjectUseOnCharacterMessage(FuncTree tree)
{
  ObjectUseMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectUseOnCharacterMessage::_characterIdFunc, this, std::placeholders::_1));
}

void ObjectUseOnCharacterMessage::_characterIdFunc(Reader *input)
{
  this->characterId = input->readVarUhLong();
  if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ObjectUseOnCharacterMessage -"<<"Forbidden value (" << this->characterId << ") on element of ObjectUseOnCharacterMessage.characterId.";
  }
}

ObjectUseOnCharacterMessage::ObjectUseOnCharacterMessage()
{
  m_type = MessageEnum::OBJECTUSEONCHARACTERMESSAGE;
}

