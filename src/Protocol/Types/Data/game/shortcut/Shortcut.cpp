#include "Shortcut.h"

void Shortcut::serialize(Writer *output)
{
  this->serializeAs_Shortcut(output);
}

void Shortcut::serializeAs_Shortcut(Writer *output)
{
  if(this->slot < 0 || this->slot > 99)
  {
    qDebug()<<"ERREUR - Shortcut -"<<"Forbidden value (" << this->slot << ") on element slot.";
  }
  output->writeByte(this->slot);
}

void Shortcut::deserialize(Reader *input)
{
  this->deserializeAs_Shortcut(input);
}

void Shortcut::deserializeAs_Shortcut(Reader *input)
{
  this->_slotFunc(input);
}

void Shortcut::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_Shortcut(tree);
}

void Shortcut::deserializeAsyncAs_Shortcut(FuncTree tree)
{
  tree.addChild(std::bind(&Shortcut::_slotFunc, this, std::placeholders::_1));
}

void Shortcut::_slotFunc(Reader *input)
{
  this->slot = input->readByte();
  if(this->slot < 0 || this->slot > 99)
  {
    qDebug()<<"ERREUR - Shortcut -"<<"Forbidden value (" << this->slot << ") on element of Shortcut.slot.";
  }
}

Shortcut::Shortcut()
{
  m_types<<ClassEnum::SHORTCUT;
}

bool Shortcut::operator==(const Shortcut &compared)
{
  if(slot == compared.slot)
  return true;
  
  return false;
}

