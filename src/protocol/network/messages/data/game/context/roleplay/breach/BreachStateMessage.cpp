#include "BreachStateMessage.h"

void BreachStateMessage::serialize(Writer *output)
{
  this->serializeAs_BreachStateMessage(output);
}

void BreachStateMessage::serializeAs_BreachStateMessage(Writer *output)
{
  this->owner.serializeAs_CharacterMinimalInformations(output);
  output->writeShort((short)this->bonuses.size());
  for(uint _i2 = 0; _i2 < this->bonuses.size(); _i2++)
  {
    qSharedPointerCast<ObjectEffectInteger>(this->bonuses[_i2])->serializeAs_ObjectEffectInteger(output);
  }
  if(this->bugdet < 0)
  {
    qDebug()<<"ERREUR - BreachStateMessage -"<<"Forbidden value (" << this->bugdet << ") on element bugdet.";
  }
  output->writeVarInt((int)this->bugdet);
  output->writeBool(this->saved);
}

void BreachStateMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachStateMessage(input);
}

void BreachStateMessage::deserializeAs_BreachStateMessage(Reader *input)
{
  QSharedPointer<ObjectEffectInteger> _item2 ;
  this->owner = CharacterMinimalInformations();
  this->owner.deserialize(input);
  uint _bonusesLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _bonusesLen; _i2++)
  {
    _item2 = QSharedPointer<ObjectEffectInteger>(new ObjectEffectInteger() );
    _item2->deserialize(input);
    this->bonuses.append(_item2);
  }
  this->_bugdetFunc(input);
  this->_savedFunc(input);
}

void BreachStateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachStateMessage(tree);
}

void BreachStateMessage::deserializeAsyncAs_BreachStateMessage(FuncTree tree)
{
  this->_ownertree = tree.addChild(std::bind(&BreachStateMessage::_ownertreeFunc, this, std::placeholders::_1));
  this->_bonusestree = tree.addChild(std::bind(&BreachStateMessage::_bonusestreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BreachStateMessage::_bugdetFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BreachStateMessage::_savedFunc, this, std::placeholders::_1));
}

void BreachStateMessage::_ownertreeFunc(Reader *input)
{
  this->owner = CharacterMinimalInformations();
  this->owner.deserializeAsync(this->_ownertree);
}

void BreachStateMessage::_bonusestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_bonusestree.addChild(std::bind(&BreachStateMessage::_bonusesFunc, this, std::placeholders::_1));
  }
}

void BreachStateMessage::_bonusesFunc(Reader *input)
{
  QSharedPointer<ObjectEffectInteger> _item = QSharedPointer<ObjectEffectInteger>(new ObjectEffectInteger() );
  _item->deserialize(input);
  this->bonuses.append(_item);
}

void BreachStateMessage::_bugdetFunc(Reader *input)
{
  this->bugdet = input->readVarUhInt();
  if(this->bugdet < 0)
  {
    qDebug()<<"ERREUR - BreachStateMessage -"<<"Forbidden value (" << this->bugdet << ") on element of BreachStateMessage.bugdet.";
  }
}

void BreachStateMessage::_savedFunc(Reader *input)
{
  this->saved = input->readBool();
}

BreachStateMessage::BreachStateMessage()
{
  m_type = MessageEnum::BREACHSTATEMESSAGE;
}

