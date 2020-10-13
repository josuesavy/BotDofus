#include "GuildPaddockBoughtMessage.h"

void GuildPaddockBoughtMessage::serialize(Writer *output)
{
  this->serializeAs_GuildPaddockBoughtMessage(output);
}

void GuildPaddockBoughtMessage::serializeAs_GuildPaddockBoughtMessage(Writer *output)
{
  this->paddockInfo.serializeAs_PaddockContentInformations(output);
}

void GuildPaddockBoughtMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildPaddockBoughtMessage(input);
}

void GuildPaddockBoughtMessage::deserializeAs_GuildPaddockBoughtMessage(Reader *input)
{
  this->paddockInfo = PaddockContentInformations();
  this->paddockInfo.deserialize(input);
}

void GuildPaddockBoughtMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildPaddockBoughtMessage(tree);
}

void GuildPaddockBoughtMessage::deserializeAsyncAs_GuildPaddockBoughtMessage(FuncTree tree)
{
  this->_paddockInfotree = tree.addChild(std::bind(&GuildPaddockBoughtMessage::_paddockInfotreeFunc, this, std::placeholders::_1));
}

void GuildPaddockBoughtMessage::_paddockInfotreeFunc(Reader *input)
{
  this->paddockInfo = PaddockContentInformations();
  this->paddockInfo.deserializeAsync(this->_paddockInfotree);
}

GuildPaddockBoughtMessage::GuildPaddockBoughtMessage()
{
  m_type = MessageEnum::GUILDPADDOCKBOUGHTMESSAGE;
}

