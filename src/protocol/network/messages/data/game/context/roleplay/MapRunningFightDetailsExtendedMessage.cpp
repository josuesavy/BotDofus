#include "MapRunningFightDetailsExtendedMessage.h"

void MapRunningFightDetailsExtendedMessage::serialize(Writer *output)
{
  this->serializeAs_MapRunningFightDetailsExtendedMessage(output);
}

void MapRunningFightDetailsExtendedMessage::serializeAs_MapRunningFightDetailsExtendedMessage(Writer *output)
{
  MapRunningFightDetailsMessage::serializeAs_MapRunningFightDetailsMessage(output);
  output->writeShort((short)this->namedPartyTeams.size());
  for(uint _i1 = 0; _i1 < this->namedPartyTeams.size(); _i1++)
  {
    (this->namedPartyTeams[_i1]).serializeAs_NamedPartyTeam(output);
  }
}

void MapRunningFightDetailsExtendedMessage::deserialize(Reader *input)
{
  this->deserializeAs_MapRunningFightDetailsExtendedMessage(input);
}

void MapRunningFightDetailsExtendedMessage::deserializeAs_MapRunningFightDetailsExtendedMessage(Reader *input)
{
  NamedPartyTeam _item1 ;
  MapRunningFightDetailsMessage::deserialize(input);
  uint _namedPartyTeamsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _namedPartyTeamsLen; _i1++)
  {
    _item1 = NamedPartyTeam();
    _item1.deserialize(input);
    this->namedPartyTeams.append(_item1);
  }
}

void MapRunningFightDetailsExtendedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapRunningFightDetailsExtendedMessage(tree);
}

void MapRunningFightDetailsExtendedMessage::deserializeAsyncAs_MapRunningFightDetailsExtendedMessage(FuncTree tree)
{
  MapRunningFightDetailsMessage::deserializeAsync(tree);
  this->_namedPartyTeamstree = tree.addChild(std::bind(&MapRunningFightDetailsExtendedMessage::_namedPartyTeamstreeFunc, this, std::placeholders::_1));
}

void MapRunningFightDetailsExtendedMessage::_namedPartyTeamstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_namedPartyTeamstree.addChild(std::bind(&MapRunningFightDetailsExtendedMessage::_namedPartyTeamsFunc, this, std::placeholders::_1));
  }
}

void MapRunningFightDetailsExtendedMessage::_namedPartyTeamsFunc(Reader *input)
{
  NamedPartyTeam _item = NamedPartyTeam();
  _item.deserialize(input);
  this->namedPartyTeams.append(_item);
}

MapRunningFightDetailsExtendedMessage::MapRunningFightDetailsExtendedMessage()
{
  m_type = MessageEnum::MAPRUNNINGFIGHTDETAILSEXTENDEDMESSAGE;
}

