#include "GuildVersatileInfoListMessage.h"

void GuildVersatileInfoListMessage::serialize(Writer *output)
{
  this->serializeAs_GuildVersatileInfoListMessage(output);
}

void GuildVersatileInfoListMessage::serializeAs_GuildVersatileInfoListMessage(Writer *output)
{
  output->writeShort((short)this->guilds.size());
  for(uint _i1 = 0; _i1 < this->guilds.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<GuildVersatileInformations>(this->guilds[_i1])->getTypes().last());
    qSharedPointerCast<GuildVersatileInformations>(this->guilds[_i1])->serialize(output);
  }
}

void GuildVersatileInfoListMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildVersatileInfoListMessage(input);
}

void GuildVersatileInfoListMessage::deserializeAs_GuildVersatileInfoListMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<GuildVersatileInformations> _item1 ;
  uint _guildsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _guildsLen; _i1++)
  {
    _id1 = input->readUShort();
    _item1 = qSharedPointerCast<GuildVersatileInformations>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->guilds.append(_item1);
  }
}

void GuildVersatileInfoListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildVersatileInfoListMessage(tree);
}

void GuildVersatileInfoListMessage::deserializeAsyncAs_GuildVersatileInfoListMessage(FuncTree tree)
{
  this->_guildstree = tree.addChild(std::bind(&GuildVersatileInfoListMessage::_guildstreeFunc, this, std::placeholders::_1));
}

void GuildVersatileInfoListMessage::_guildstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_guildstree.addChild(std::bind(&GuildVersatileInfoListMessage::_guildsFunc, this, std::placeholders::_1));
  }
}

void GuildVersatileInfoListMessage::_guildsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<GuildVersatileInformations> _item = qSharedPointerCast<GuildVersatileInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->guilds.append(_item);
}

GuildVersatileInfoListMessage::GuildVersatileInfoListMessage()
{
  m_type = MessageEnum::GUILDVERSATILEINFOLISTMESSAGE;
}

