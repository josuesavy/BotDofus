#include "ShortcutSmiley.h"

void ShortcutSmiley::serialize(Writer *output)
{
  this->serializeAs_ShortcutSmiley(output);
}

void ShortcutSmiley::serializeAs_ShortcutSmiley(Writer *output)
{
  Shortcut::serializeAs_Shortcut(output);
  if(this->smileyId < 0)
  {
    qDebug()<<"ERREUR - ShortcutSmiley -"<<"Forbidden value (" << this->smileyId << ") on element smileyId.";
  }
  output->writeVarShort((int)this->smileyId);
}

void ShortcutSmiley::deserialize(Reader *input)
{
  this->deserializeAs_ShortcutSmiley(input);
}

void ShortcutSmiley::deserializeAs_ShortcutSmiley(Reader *input)
{
  Shortcut::deserialize(input);
  this->_smileyIdFunc(input);
}

void ShortcutSmiley::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShortcutSmiley(tree);
}

void ShortcutSmiley::deserializeAsyncAs_ShortcutSmiley(FuncTree tree)
{
  Shortcut::deserializeAsync(tree);
  tree.addChild(std::bind(&ShortcutSmiley::_smileyIdFunc, this, std::placeholders::_1));
}

void ShortcutSmiley::_smileyIdFunc(Reader *input)
{
  this->smileyId = input->readVarUhShort();
  if(this->smileyId < 0)
  {
    qDebug()<<"ERREUR - ShortcutSmiley -"<<"Forbidden value (" << this->smileyId << ") on element of ShortcutSmiley.smileyId.";
  }
}

ShortcutSmiley::ShortcutSmiley()
{
  m_types<<ClassEnum::SHORTCUTSMILEY;
}

bool ShortcutSmiley::operator==(const ShortcutSmiley &compared)
{
  if(smileyId == compared.smileyId)
  return true;
  
  return false;
}

