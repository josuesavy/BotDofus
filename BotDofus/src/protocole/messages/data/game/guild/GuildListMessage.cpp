#include "GuildListMessage.h"

void GuildListMessage::serialize(Writer *output)
{
  this->serializeAs_GuildListMessage(output);
}

void GuildListMessage::serializeAs_GuildListMessage(Writer *output)
{
  output->writeShort((short)this->guilds.size());
  for(uint _i1 = 0; _i1 < this->guilds.size(); _i1++)
  {
    qSharedPointerCast<GuildInformations>(this->guilds[_i1])->serializeAs_GuildInformations(output);
  }
}

void GuildListMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildListMessage(input);
}

void GuildListMessage::deserializeAs_GuildListMessage(Reader *input)
{
  QSharedPointer<GuildInformations> _item1 ;
  uint _guildsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _guildsLen; _i1++)
  {
    _item1 = QSharedPointer<GuildInformations>(new GuildInformations() );
    _item1->deserialize(input);
    this->guilds.append(_item1);
  }
}

void GuildListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildListMessage(tree);
}

void GuildListMessage::deserializeAsyncAs_GuildListMessage(FuncTree tree)
{
  this->_guildstree = tree.addChild(std::bind(&GuildListMessage::_guildstreeFunc, this, std::placeholders::_1));
}

void GuildListMessage::_guildstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_guildstree.addChild(std::bind(&GuildListMessage::_guildsFunc, this, std::placeholders::_1));
  }
}

void GuildListMessage::_guildsFunc(Reader *input)
{
  QSharedPointer<GuildInformations> _item = QSharedPointer<GuildInformations>(new GuildInformations() );
  _item->deserialize(input);
  this->guilds.append(_item);
}

GuildListMessage::GuildListMessage()
{
  m_type = MessageEnum::GUILDLISTMESSAGE;
}

