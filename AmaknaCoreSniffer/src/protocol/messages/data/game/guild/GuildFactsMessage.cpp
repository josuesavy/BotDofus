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
  if(this->nbTaxCollectors < 0)
  {
    qDebug()<<"ERREUR - GuildFactsMessage -"<<"Forbidden value (" << this->nbTaxCollectors << ") on element nbTaxCollectors.";
  }
  output->writeVarShort((int)this->nbTaxCollectors);
  output->writeShort((short)this->members.size());
  for(uint _i4 = 0; _i4 < this->members.size(); _i4++)
  {
    (this->members[_i4]).serializeAs_CharacterMinimalGuildPublicInformations(output);
  }
}

void GuildFactsMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildFactsMessage(input);
}

void GuildFactsMessage::deserializeAs_GuildFactsMessage(Reader *input)
{
  CharacterMinimalGuildPublicInformations _item4 ;
  uint _id1 = input->readUShort();
  this->infos = qSharedPointerCast<GuildFactSheetInformations>(ClassManagerSingleton::get()->getClass(_id1));
  this->infos->deserialize(input);
  this->_creationDateFunc(input);
  this->_nbTaxCollectorsFunc(input);
  uint _membersLen = input->readUShort();
  for(uint _i4 = 0; _i4 < _membersLen; _i4++)
  {
    _item4 = CharacterMinimalGuildPublicInformations();
    _item4.deserialize(input);
    this->members.append(_item4);
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
  tree.addChild(std::bind(&GuildFactsMessage::_nbTaxCollectorsFunc, this, std::placeholders::_1));
  this->_memberstree = tree.addChild(std::bind(&GuildFactsMessage::_memberstreeFunc, this, std::placeholders::_1));
}

void GuildFactsMessage::_infostreeFunc(Reader *input)
{
  uint _id = input->readUShort();
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

void GuildFactsMessage::_nbTaxCollectorsFunc(Reader *input)
{
  this->nbTaxCollectors = input->readVarUhShort();
  if(this->nbTaxCollectors < 0)
  {
    qDebug()<<"ERREUR - GuildFactsMessage -"<<"Forbidden value (" << this->nbTaxCollectors << ") on element of GuildFactsMessage.nbTaxCollectors.";
  }
}

void GuildFactsMessage::_memberstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_memberstree.addChild(std::bind(&GuildFactsMessage::_membersFunc, this, std::placeholders::_1));
  }
}

void GuildFactsMessage::_membersFunc(Reader *input)
{
  CharacterMinimalGuildPublicInformations _item = CharacterMinimalGuildPublicInformations();
  _item.deserialize(input);
  this->members.append(_item);
}

GuildFactsMessage::GuildFactsMessage()
{
  m_type = MessageEnum::GUILDFACTSMESSAGE;
}

