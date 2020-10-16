#include "GuildSpellUpgradeRequestMessage.h"

void GuildSpellUpgradeRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GuildSpellUpgradeRequestMessage(output);
}

void GuildSpellUpgradeRequestMessage::serializeAs_GuildSpellUpgradeRequestMessage(Writer *output)
{
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GuildSpellUpgradeRequestMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  output->writeInt((int)this->spellId);
}

void GuildSpellUpgradeRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildSpellUpgradeRequestMessage(input);
}

void GuildSpellUpgradeRequestMessage::deserializeAs_GuildSpellUpgradeRequestMessage(Reader *input)
{
  this->_spellIdFunc(input);
}

void GuildSpellUpgradeRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildSpellUpgradeRequestMessage(tree);
}

void GuildSpellUpgradeRequestMessage::deserializeAsyncAs_GuildSpellUpgradeRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildSpellUpgradeRequestMessage::_spellIdFunc, this, std::placeholders::_1));
}

void GuildSpellUpgradeRequestMessage::_spellIdFunc(Reader *input)
{
  this->spellId = input->readInt();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GuildSpellUpgradeRequestMessage -"<<"Forbidden value (" << this->spellId << ") on element of GuildSpellUpgradeRequestMessage.spellId.";
  }
}

GuildSpellUpgradeRequestMessage::GuildSpellUpgradeRequestMessage()
{
  m_type = MessageEnum::GUILDSPELLUPGRADEREQUESTMESSAGE;
}

