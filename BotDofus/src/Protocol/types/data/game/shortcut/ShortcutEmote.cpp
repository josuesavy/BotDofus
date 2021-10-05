#include "ShortcutEmote.h"

void ShortcutEmote::serialize(Writer *output)
{
  this->serializeAs_ShortcutEmote(output);
}

void ShortcutEmote::serializeAs_ShortcutEmote(Writer *output)
{
  Shortcut::serializeAs_Shortcut(output);
  if(this->emoteId < 0 || this->emoteId > 255)
  {
    qDebug()<<"ERREUR - ShortcutEmote -"<<"Forbidden value (" << this->emoteId << ") on element emoteId.";
  }
  output->writeByte(this->emoteId);
}

void ShortcutEmote::deserialize(Reader *input)
{
  this->deserializeAs_ShortcutEmote(input);
}

void ShortcutEmote::deserializeAs_ShortcutEmote(Reader *input)
{
  Shortcut::deserialize(input);
  this->_emoteIdFunc(input);
}

void ShortcutEmote::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShortcutEmote(tree);
}

void ShortcutEmote::deserializeAsyncAs_ShortcutEmote(FuncTree tree)
{
  Shortcut::deserializeAsync(tree);
  tree.addChild(std::bind(&ShortcutEmote::_emoteIdFunc, this, std::placeholders::_1));
}

void ShortcutEmote::_emoteIdFunc(Reader *input)
{
  this->emoteId = input->readUByte();
  if(this->emoteId < 0 || this->emoteId > 255)
  {
    qDebug()<<"ERREUR - ShortcutEmote -"<<"Forbidden value (" << this->emoteId << ") on element of ShortcutEmote.emoteId.";
  }
}

ShortcutEmote::ShortcutEmote()
{
  m_types<<ClassEnum::SHORTCUTEMOTE;
}

bool ShortcutEmote::operator==(const ShortcutEmote &compared)
{
  if(emoteId == compared.emoteId)
  return true;
  
  return false;
}

