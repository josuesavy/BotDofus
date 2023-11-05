#include "GuildFactsMessage.h"

void GuildFactsMessage::serialize(Writer *output)
{
  this->serializeAs_GuildFactsMessage(output);
}

void GuildFactsMessage::serializeAs_GuildFactsMessage(Writer *output)
{
  output->writeShort((short)this->infos->getTypes().last());
  this->infos->serialize(output);
  if(this->creationDate < 0)
  {
    qDebug()<<"ERREUR - GuildFactsMessage -"<<"Forbidden value (" << this->creationDate << ") on element creationDate.";
  }
  output->writeInt((int)this->creationDate);
  output->writeShort((short)this->members.size());
  for(uint _i3 = 0; _i3 < this->members.size(); _i3++)
  {
    (this->members[_i3]).serializeAs_CharacterMinimalSocialPublicInformations(output);
  }
}

void GuildFactsMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildFactsMessage(input);
}

void GuildFactsMessage::deserializeAs_GuildFactsMessage(Reader *input)
{
  CharacterMinimalSocialPublicInformations _item3 ;
  uint _id1 = uint(input->readUShort());
  this->infos = qSharedPointerCast<GuildFactSheetInformations>(ClassManagerSingleton::get()->getClass(_id1));
  this->infos->deserialize(input);
  this->_creationDateFunc(input);
  uint _membersLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _membersLen; _i3++)
  {
    _item3 = CharacterMinimalSocialPublicInformations();
    _item3.deserialize(input);
    this->members.append(_item3);
  }
}

void GuildFactsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildFactsMessage(tree);
}

void GuildFactsMessage::deserializeAsyncAs_GuildFactsMessage(FuncTree tree)
{
  this->_infostree = tree.addChild(std::bind(&GuildFactsMessage::_infostreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildFactsMessage::_creationDateFunc, this, std::placeholders::_1));
  this->_memberstree = tree.addChild(std::bind(&GuildFactsMessage::_memberstreeFunc, this, std::placeholders::_1));
}

void GuildFactsMessage::_infostreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->infos = qSharedPointerCast<GuildFactSheetInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->infos->deserializeAsync(this->_infostree);
}

void GuildFactsMessage::_creationDateFunc(Reader *input)
{
  this->creationDate = input->readInt();
  if(this->creationDate < 0)
  {
    qDebug()<<"ERREUR - GuildFactsMessage -"<<"Forbidden value (" << this->creationDate << ") on element of GuildFactsMessage.creationDate.";
  }
}

void GuildFactsMessage::_memberstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_memberstree.addChild(std::bind(&GuildFactsMessage::_membersFunc, this, std::placeholders::_1));
  }
}

void GuildFactsMessage::_membersFunc(Reader *input)
{
  CharacterMinimalSocialPublicInformations _item = CharacterMinimalSocialPublicInformations();
  _item.deserialize(input);
  this->members.append(_item);
}

GuildFactsMessage::GuildFactsMessage()
{
  m_type = MessageEnum::GUILDFACTSMESSAGE;
}

