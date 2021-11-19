#include "CharacterCapabilitiesMessage.h"

void CharacterCapabilitiesMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterCapabilitiesMessage(output);
}

void CharacterCapabilitiesMessage::serializeAs_CharacterCapabilitiesMessage(Writer *output)
{
  if(this->guildEmblemSymbolCategories < 0)
  {
    qDebug()<<"ERREUR - CharacterCapabilitiesMessage -"<<"Forbidden value (" << this->guildEmblemSymbolCategories << ") on element guildEmblemSymbolCategories.";
  }
  output->writeVarInt((int)this->guildEmblemSymbolCategories);
}

void CharacterCapabilitiesMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterCapabilitiesMessage(input);
}

void CharacterCapabilitiesMessage::deserializeAs_CharacterCapabilitiesMessage(Reader *input)
{
  this->_guildEmblemSymbolCategoriesFunc(input);
}

void CharacterCapabilitiesMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterCapabilitiesMessage(tree);
}

void CharacterCapabilitiesMessage::deserializeAsyncAs_CharacterCapabilitiesMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterCapabilitiesMessage::_guildEmblemSymbolCategoriesFunc, this, std::placeholders::_1));
}

void CharacterCapabilitiesMessage::_guildEmblemSymbolCategoriesFunc(Reader *input)
{
  this->guildEmblemSymbolCategories = input->readVarUhInt();
  if(this->guildEmblemSymbolCategories < 0)
  {
    qDebug()<<"ERREUR - CharacterCapabilitiesMessage -"<<"Forbidden value (" << this->guildEmblemSymbolCategories << ") on element of CharacterCapabilitiesMessage.guildEmblemSymbolCategories.";
  }
}

CharacterCapabilitiesMessage::CharacterCapabilitiesMessage()
{
  m_type = MessageEnum::CHARACTERCAPABILITIESMESSAGE;
}

