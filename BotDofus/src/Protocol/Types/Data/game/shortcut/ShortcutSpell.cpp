#include "ShortcutSpell.h"

void ShortcutSpell::serialize(Writer *output)
{
  this->serializeAs_ShortcutSpell(output);
}

void ShortcutSpell::serializeAs_ShortcutSpell(Writer *output)
{
  Shortcut::serializeAs_Shortcut(output);
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - ShortcutSpell -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  output->writeVarShort((int)this->spellId);
}

void ShortcutSpell::deserialize(Reader *input)
{
  this->deserializeAs_ShortcutSpell(input);
}

void ShortcutSpell::deserializeAs_ShortcutSpell(Reader *input)
{
  Shortcut::deserialize(input);
  this->_spellIdFunc(input);
}

void ShortcutSpell::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShortcutSpell(tree);
}

void ShortcutSpell::deserializeAsyncAs_ShortcutSpell(FuncTree tree)
{
  Shortcut::deserializeAsync(tree);
  tree.addChild(std::bind(&ShortcutSpell::_spellIdFunc, this, std::placeholders::_1));
}

void ShortcutSpell::_spellIdFunc(Reader *input)
{
  this->spellId = input->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - ShortcutSpell -"<<"Forbidden value (" << this->spellId << ") on element of ShortcutSpell.spellId.";
  }
}

ShortcutSpell::ShortcutSpell()
{
  m_types<<ClassEnum::SHORTCUTSPELL;
}

bool ShortcutSpell::operator==(const ShortcutSpell &compared)
{
  if(spellId == compared.spellId)
  return true;
  
  return false;
}

