#include "RemoveSpellModifierMessage.h"

void RemoveSpellModifierMessage::serialize(Writer *output)
{
  this->serializeAs_RemoveSpellModifierMessage(output);
}

void RemoveSpellModifierMessage::serializeAs_RemoveSpellModifierMessage(Writer *output)
{
  if(this->actorId < -9007199254740992 || this->actorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - RemoveSpellModifierMessage -"<<"Forbidden value (" << this->actorId << ") on element actorId.";
  }
  output->writeDouble(this->actorId);
  output->writeByte(this->modificationType);
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - RemoveSpellModifierMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  output->writeVarShort((int)this->spellId);
}

void RemoveSpellModifierMessage::deserialize(Reader *input)
{
  this->deserializeAs_RemoveSpellModifierMessage(input);
}

void RemoveSpellModifierMessage::deserializeAs_RemoveSpellModifierMessage(Reader *input)
{
  this->_actorIdFunc(input);
  this->_modificationTypeFunc(input);
  this->_spellIdFunc(input);
}

void RemoveSpellModifierMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_RemoveSpellModifierMessage(tree);
}

void RemoveSpellModifierMessage::deserializeAsyncAs_RemoveSpellModifierMessage(FuncTree tree)
{
  tree.addChild(std::bind(&RemoveSpellModifierMessage::_actorIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&RemoveSpellModifierMessage::_modificationTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&RemoveSpellModifierMessage::_spellIdFunc, this, std::placeholders::_1));
}

void RemoveSpellModifierMessage::_actorIdFunc(Reader *input)
{
  this->actorId = input->readDouble();
  if(this->actorId < -9007199254740992 || this->actorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - RemoveSpellModifierMessage -"<<"Forbidden value (" << this->actorId << ") on element of RemoveSpellModifierMessage.actorId.";
  }
}

void RemoveSpellModifierMessage::_modificationTypeFunc(Reader *input)
{
  this->modificationType = input->readByte();
  if(this->modificationType < 0)
  {
    qDebug()<<"ERREUR - RemoveSpellModifierMessage -"<<"Forbidden value (" << this->modificationType << ") on element of RemoveSpellModifierMessage.modificationType.";
  }
}

void RemoveSpellModifierMessage::_spellIdFunc(Reader *input)
{
  this->spellId = input->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - RemoveSpellModifierMessage -"<<"Forbidden value (" << this->spellId << ") on element of RemoveSpellModifierMessage.spellId.";
  }
}

RemoveSpellModifierMessage::RemoveSpellModifierMessage()
{
  m_type = MessageEnum::REMOVESPELLMODIFIERMESSAGE;
}

