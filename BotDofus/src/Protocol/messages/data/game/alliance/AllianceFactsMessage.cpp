#include "AllianceFactsMessage.h"

void AllianceFactsMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceFactsMessage(output);
}

void AllianceFactsMessage::serializeAs_AllianceFactsMessage(Writer *output)
{
  output->writeShort((short)this->infos->getTypes().last());
  this->infos->serialize(output);
  output->writeShort((short)this->guilds.size());
  for(uint _i2 = 0; _i2 < this->guilds.size(); _i2++)
  {
    qSharedPointerCast<GuildInAllianceInformations>(this->guilds[_i2])->serializeAs_GuildInAllianceInformations(output);
  }
  output->writeShort((short)this->controlledSubareaIds.size());
  for(uint _i3 = 0; _i3 < this->controlledSubareaIds.size(); _i3++)
  {
    if(this->controlledSubareaIds[_i3] < 0)
    {
      qDebug()<<"ERREUR - AllianceFactsMessage -"<<"Forbidden value (" << this->controlledSubareaIds[_i3] << ") on element 3 (starting at 1) of controlledSubareaIds.";
    }
    output->writeVarShort((int)this->controlledSubareaIds[_i3]);
  }
  if(this->leaderCharacterId < 0 || this->leaderCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AllianceFactsMessage -"<<"Forbidden value (" << this->leaderCharacterId << ") on element leaderCharacterId.";
  }
  output->writeVarLong((double)this->leaderCharacterId);
  output->writeUTF(this->leaderCharacterName);
}

void AllianceFactsMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceFactsMessage(input);
}

void AllianceFactsMessage::deserializeAs_AllianceFactsMessage(Reader *input)
{
  QSharedPointer<GuildInAllianceInformations> _item2 ;
  uint _val3 = 0;
  uint _id1 = input->readUShort();
  this->infos = qSharedPointerCast<AllianceFactSheetInformations>(ClassManagerSingleton::get()->getClass(_id1));
  this->infos->deserialize(input);
  uint _guildsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _guildsLen; _i2++)
  {
    _item2 = QSharedPointer<GuildInAllianceInformations>(new GuildInAllianceInformations() );
    _item2->deserialize(input);
    this->guilds.append(_item2);
  }
  uint _controlledSubareaIdsLen = input->readUShort();
  for(uint _i3 = 0; _i3 < _controlledSubareaIdsLen; _i3++)
  {
    _val3 = input->readVarUhShort();
    if(_val3 < 0)
    {
      qDebug()<<"ERREUR - AllianceFactsMessage -"<<"Forbidden value (" << _val3 << ") on elements of controlledSubareaIds.";
    }
    this->controlledSubareaIds.append(_val3);
  }
  this->_leaderCharacterIdFunc(input);
  this->_leaderCharacterNameFunc(input);
}

void AllianceFactsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceFactsMessage(tree);
}

void AllianceFactsMessage::deserializeAsyncAs_AllianceFactsMessage(FuncTree tree)
{
  this->_infostree = tree.addChild(std::bind(&AllianceFactsMessage::_infostreeFunc, this, std::placeholders::_1));
  this->_guildstree = tree.addChild(std::bind(&AllianceFactsMessage::_guildstreeFunc, this, std::placeholders::_1));
  this->_controlledSubareaIdstree = tree.addChild(std::bind(&AllianceFactsMessage::_controlledSubareaIdstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceFactsMessage::_leaderCharacterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceFactsMessage::_leaderCharacterNameFunc, this, std::placeholders::_1));
}

void AllianceFactsMessage::_infostreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->infos = qSharedPointerCast<AllianceFactSheetInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->infos->deserializeAsync(this->_infostree);
}

void AllianceFactsMessage::_guildstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_guildstree.addChild(std::bind(&AllianceFactsMessage::_guildsFunc, this, std::placeholders::_1));
  }
}

void AllianceFactsMessage::_guildsFunc(Reader *input)
{
  QSharedPointer<GuildInAllianceInformations> _item = QSharedPointer<GuildInAllianceInformations>(new GuildInAllianceInformations() );
  _item->deserialize(input);
  this->guilds.append(_item);
}

void AllianceFactsMessage::_controlledSubareaIdstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_controlledSubareaIdstree.addChild(std::bind(&AllianceFactsMessage::_controlledSubareaIdsFunc, this, std::placeholders::_1));
  }
}

void AllianceFactsMessage::_controlledSubareaIdsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - AllianceFactsMessage -"<<"Forbidden value (" << _val << ") on elements of controlledSubareaIds.";
  }
  this->controlledSubareaIds.append(_val);
}

void AllianceFactsMessage::_leaderCharacterIdFunc(Reader *input)
{
  this->leaderCharacterId = input->readVarUhLong();
  if(this->leaderCharacterId < 0 || this->leaderCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AllianceFactsMessage -"<<"Forbidden value (" << this->leaderCharacterId << ") on element of AllianceFactsMessage.leaderCharacterId.";
  }
}

void AllianceFactsMessage::_leaderCharacterNameFunc(Reader *input)
{
  this->leaderCharacterName = input->readUTF();
}

AllianceFactsMessage::AllianceFactsMessage()
{
  m_type = MessageEnum::ALLIANCEFACTSMESSAGE;
}

