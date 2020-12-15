#include "GameFightSpectatorJoinMessage.h"

void GameFightSpectatorJoinMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightSpectatorJoinMessage(output);
}

void GameFightSpectatorJoinMessage::serializeAs_GameFightSpectatorJoinMessage(Writer *output)
{
  GameFightJoinMessage::serializeAs_GameFightJoinMessage(output);
  output->writeShort((short)this->namedPartyTeams.size());
  for(uint _i1 = 0; _i1 < this->namedPartyTeams.size(); _i1++)
  {
    (this->namedPartyTeams[_i1]).serializeAs_NamedPartyTeam(output);
  }
}

void GameFightSpectatorJoinMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightSpectatorJoinMessage(input);
}

void GameFightSpectatorJoinMessage::deserializeAs_GameFightSpectatorJoinMessage(Reader *input)
{
  NamedPartyTeam _item1 ;
  GameFightJoinMessage::deserialize(input);
  uint _namedPartyTeamsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _namedPartyTeamsLen; _i1++)
  {
    _item1 = NamedPartyTeam();
    _item1.deserialize(input);
    this->namedPartyTeams.append(_item1);
  }
}

void GameFightSpectatorJoinMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightSpectatorJoinMessage(tree);
}

void GameFightSpectatorJoinMessage::deserializeAsyncAs_GameFightSpectatorJoinMessage(FuncTree tree)
{
  GameFightJoinMessage::deserializeAsync(tree);
  this->_namedPartyTeamstree = tree.addChild(std::bind(&GameFightSpectatorJoinMessage::_namedPartyTeamstreeFunc, this, std::placeholders::_1));
}

void GameFightSpectatorJoinMessage::_namedPartyTeamstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_namedPartyTeamstree.addChild(std::bind(&GameFightSpectatorJoinMessage::_namedPartyTeamsFunc, this, std::placeholders::_1));
  }
}

void GameFightSpectatorJoinMessage::_namedPartyTeamsFunc(Reader *input)
{
  NamedPartyTeam _item = NamedPartyTeam();
  _item.deserialize(input);
  this->namedPartyTeams.append(_item);
}

GameFightSpectatorJoinMessage::GameFightSpectatorJoinMessage()
{
  m_type = MessageEnum::GAMEFIGHTSPECTATORJOINMESSAGE;
}

