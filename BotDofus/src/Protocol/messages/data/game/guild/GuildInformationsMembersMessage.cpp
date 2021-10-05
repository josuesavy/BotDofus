#include "GuildInformationsMembersMessage.h"

void GuildInformationsMembersMessage::serialize(Writer *output)
{
  this->serializeAs_GuildInformationsMembersMessage(output);
}

void GuildInformationsMembersMessage::serializeAs_GuildInformationsMembersMessage(Writer *output)
{
  output->writeShort((short)this->members.size());
  for(uint _i1 = 0; _i1 < this->members.size(); _i1++)
  {
    qSharedPointerCast<GuildMember>(this->members[_i1])->serializeAs_GuildMember(output);
  }
}

void GuildInformationsMembersMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildInformationsMembersMessage(input);
}

void GuildInformationsMembersMessage::deserializeAs_GuildInformationsMembersMessage(Reader *input)
{
  QSharedPointer<GuildMember> _item1 ;
  uint _membersLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _membersLen; _i1++)
  {
    _item1 = QSharedPointer<GuildMember>(new GuildMember() );
    _item1->deserialize(input);
    this->members.append(_item1);
  }
}

void GuildInformationsMembersMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildInformationsMembersMessage(tree);
}

void GuildInformationsMembersMessage::deserializeAsyncAs_GuildInformationsMembersMessage(FuncTree tree)
{
  this->_memberstree = tree.addChild(std::bind(&GuildInformationsMembersMessage::_memberstreeFunc, this, std::placeholders::_1));
}

void GuildInformationsMembersMessage::_memberstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_memberstree.addChild(std::bind(&GuildInformationsMembersMessage::_membersFunc, this, std::placeholders::_1));
  }
}

void GuildInformationsMembersMessage::_membersFunc(Reader *input)
{
  QSharedPointer<GuildMember> _item = QSharedPointer<GuildMember>(new GuildMember() );
  _item->deserialize(input);
  this->members.append(_item);
}

GuildInformationsMembersMessage::GuildInformationsMembersMessage()
{
  m_type = MessageEnum::GUILDINFORMATIONSMEMBERSMESSAGE;
}

