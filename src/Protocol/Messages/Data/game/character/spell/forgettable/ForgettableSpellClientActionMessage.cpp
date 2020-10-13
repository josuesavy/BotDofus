#include "ForgettableSpellClientActionMessage.h"

void ForgettableSpellClientActionMessage::serialize(Writer *output)
{
  this->serializeAs_ForgettableSpellClientActionMessage(output);
}

void ForgettableSpellClientActionMessage::serializeAs_ForgettableSpellClientActionMessage(Writer *output)
{
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - ForgettableSpellClientActionMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  output->writeInt((int)this->spellId);
  output->writeByte(this->action);
}

void ForgettableSpellClientActionMessage::deserialize(Reader *input)
{
  this->deserializeAs_ForgettableSpellClientActionMessage(input);
}

void ForgettableSpellClientActionMessage::deserializeAs_ForgettableSpellClientActionMessage(Reader *input)
{
  this->_spellIdFunc(input);
  this->_actionFunc(input);
}

void ForgettableSpellClientActionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ForgettableSpellClientActionMessage(tree);
}

void ForgettableSpellClientActionMessage::deserializeAsyncAs_ForgettableSpellClientActionMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ForgettableSpellClientActionMessage::_spellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ForgettableSpellClientActionMessage::_actionFunc, this, std::placeholders::_1));
}

void ForgettableSpellClientActionMessage::_spellIdFunc(Reader *input)
{
  this->spellId = input->readInt();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - ForgettableSpellClientActionMessage -"<<"Forbidden value (" << this->spellId << ") on element of ForgettableSpellClientActionMessage.spellId.";
  }
}

void ForgettableSpellClientActionMessage::_actionFunc(Reader *input)
{
  this->action = input->readByte();
  if(this->action < 0)
  {
    qDebug()<<"ERREUR - ForgettableSpellClientActionMessage -"<<"Forbidden value (" << this->action << ") on element of ForgettableSpellClientActionMessage.action.";
  }
}

ForgettableSpellClientActionMessage::ForgettableSpellClientActionMessage()
{
  m_type = MessageEnum::FORGETTABLESPELLCLIENTACTIONMESSAGE;
}

