#include "GuildUpdateChestTabRequestMessage.h"

void GuildUpdateChestTabRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GuildUpdateChestTabRequestMessage(output);
}

void GuildUpdateChestTabRequestMessage::serializeAs_GuildUpdateChestTabRequestMessage(Writer *output)
{
  this->tab.serializeAs_UpdatedStorageTabInformation(output);
}

void GuildUpdateChestTabRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildUpdateChestTabRequestMessage(input);
}

void GuildUpdateChestTabRequestMessage::deserializeAs_GuildUpdateChestTabRequestMessage(Reader *input)
{
  this->tab = UpdatedStorageTabInformation();
  this->tab.deserialize(input);
}

void GuildUpdateChestTabRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildUpdateChestTabRequestMessage(tree);
}

void GuildUpdateChestTabRequestMessage::deserializeAsyncAs_GuildUpdateChestTabRequestMessage(FuncTree tree)
{
  this->_tabtree = tree.addChild(std::bind(&GuildUpdateChestTabRequestMessage::_tabtreeFunc, this, std::placeholders::_1));
}

void GuildUpdateChestTabRequestMessage::_tabtreeFunc(Reader *input)
{
  this->tab = UpdatedStorageTabInformation();
  this->tab.deserializeAsync(this->_tabtree);
}

GuildUpdateChestTabRequestMessage::GuildUpdateChestTabRequestMessage()
{
  m_type = MessageEnum::GUILDUPDATECHESTTABREQUESTMESSAGE;
}

