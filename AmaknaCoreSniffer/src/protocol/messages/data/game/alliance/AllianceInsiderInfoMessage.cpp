#include "AllianceInsiderInfoMessage.h"

void AllianceInsiderInfoMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceInsiderInfoMessage(output);
}

void AllianceInsiderInfoMessage::serializeAs_AllianceInsiderInfoMessage(Writer *output)
{
  this->allianceInfos->serializeAs_AllianceFactSheetInformations(output);
  output->writeShort((short)this->guilds.size());
  for(uint _i2 = 0; _i2 < this->guilds.size(); _i2++)
  {
    qSharedPointerCast<GuildInsiderFactSheetInformations>(this->guilds[_i2])->serializeAs_GuildInsiderFactSheetInformations(output);
  }
  output->writeShort((short)this->prisms.size());
  for(uint _i3 = 0; _i3 < this->prisms.size(); _i3++)
  {
    output->writeShort((short)qSharedPointerCast<PrismSubareaEmptyInfo>(this->prisms[_i3])->getTypes().last());
    qSharedPointerCast<PrismSubareaEmptyInfo>(this->prisms[_i3])->serialize(output);
  }
}

void AllianceInsiderInfoMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceInsiderInfoMessage(input);
}

void AllianceInsiderInfoMessage::deserializeAs_AllianceInsiderInfoMessage(Reader *input)
{
  QSharedPointer<GuildInsiderFactSheetInformations> _item2 ;
  uint _id3 = 0;
  QSharedPointer<PrismSubareaEmptyInfo> _item3 ;
  this->allianceInfos = QSharedPointer<AllianceFactSheetInformations>(new AllianceFactSheetInformations() );
  this->allianceInfos->deserialize(input);
  uint _guildsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _guildsLen; _i2++)
  {
    _item2 = QSharedPointer<GuildInsiderFactSheetInformations>(new GuildInsiderFactSheetInformations() );
    _item2->deserialize(input);
    this->guilds.append(_item2);
  }
  uint _prismsLen = input->readUShort();
  for(uint _i3 = 0; _i3 < _prismsLen; _i3++)
  {
    _id3 = input->readUShort();
    _item3 = qSharedPointerCast<PrismSubareaEmptyInfo>(ClassManagerSingleton::get()->getClass(_id3));
    _item3->deserialize(input);
    this->prisms.append(_item3);
  }
}

void AllianceInsiderInfoMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceInsiderInfoMessage(tree);
}

void AllianceInsiderInfoMessage::deserializeAsyncAs_AllianceInsiderInfoMessage(FuncTree tree)
{
  this->_allianceInfostree = tree.addChild(std::bind(&AllianceInsiderInfoMessage::_allianceInfostreeFunc, this, std::placeholders::_1));
  this->_guildstree = tree.addChild(std::bind(&AllianceInsiderInfoMessage::_guildstreeFunc, this, std::placeholders::_1));
  this->_prismstree = tree.addChild(std::bind(&AllianceInsiderInfoMessage::_prismstreeFunc, this, std::placeholders::_1));
}

void AllianceInsiderInfoMessage::_allianceInfostreeFunc(Reader *input)
{
  this->allianceInfos = QSharedPointer<AllianceFactSheetInformations>(new AllianceFactSheetInformations() );
  this->allianceInfos->deserializeAsync(this->_allianceInfostree);
}

void AllianceInsiderInfoMessage::_guildstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_guildstree.addChild(std::bind(&AllianceInsiderInfoMessage::_guildsFunc, this, std::placeholders::_1));
  }
}

void AllianceInsiderInfoMessage::_guildsFunc(Reader *input)
{
  QSharedPointer<GuildInsiderFactSheetInformations> _item = QSharedPointer<GuildInsiderFactSheetInformations>(new GuildInsiderFactSheetInformations() );
  _item->deserialize(input);
  this->guilds.append(_item);
}

void AllianceInsiderInfoMessage::_prismstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_prismstree.addChild(std::bind(&AllianceInsiderInfoMessage::_prismsFunc, this, std::placeholders::_1));
  }
}

void AllianceInsiderInfoMessage::_prismsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<PrismSubareaEmptyInfo> _item = qSharedPointerCast<PrismSubareaEmptyInfo>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->prisms.append(_item);
}

AllianceInsiderInfoMessage::AllianceInsiderInfoMessage()
{
  m_type = MessageEnum::ALLIANCEINSIDERINFOMESSAGE;
}

