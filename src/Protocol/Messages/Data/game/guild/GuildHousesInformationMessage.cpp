#include "GuildHousesInformationMessage.h"

void GuildHousesInformationMessage::serialize(Writer *output)
{
  this->serializeAs_GuildHousesInformationMessage(output);
}

void GuildHousesInformationMessage::serializeAs_GuildHousesInformationMessage(Writer *output)
{
  output->writeShort((short)this->housesInformations.size());
  for(uint _i1 = 0; _i1 < this->housesInformations.size(); _i1++)
  {
    qSharedPointerCast<HouseInformationsForGuild>(this->housesInformations[_i1])->serializeAs_HouseInformationsForGuild(output);
  }
}

void GuildHousesInformationMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildHousesInformationMessage(input);
}

void GuildHousesInformationMessage::deserializeAs_GuildHousesInformationMessage(Reader *input)
{
  QSharedPointer<HouseInformationsForGuild> _item1 ;
  uint _housesInformationsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _housesInformationsLen; _i1++)
  {
    _item1 = QSharedPointer<HouseInformationsForGuild>(new HouseInformationsForGuild() );
    _item1->deserialize(input);
    this->housesInformations.append(_item1);
  }
}

void GuildHousesInformationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildHousesInformationMessage(tree);
}

void GuildHousesInformationMessage::deserializeAsyncAs_GuildHousesInformationMessage(FuncTree tree)
{
  this->_housesInformationstree = tree.addChild(std::bind(&GuildHousesInformationMessage::_housesInformationstreeFunc, this, std::placeholders::_1));
}

void GuildHousesInformationMessage::_housesInformationstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_housesInformationstree.addChild(std::bind(&GuildHousesInformationMessage::_housesInformationsFunc, this, std::placeholders::_1));
  }
}

void GuildHousesInformationMessage::_housesInformationsFunc(Reader *input)
{
  QSharedPointer<HouseInformationsForGuild> _item = QSharedPointer<HouseInformationsForGuild>(new HouseInformationsForGuild() );
  _item->deserialize(input);
  this->housesInformations.append(_item);
}

GuildHousesInformationMessage::GuildHousesInformationMessage()
{
  m_type = MessageEnum::GUILDHOUSESINFORMATIONMESSAGE;
}

