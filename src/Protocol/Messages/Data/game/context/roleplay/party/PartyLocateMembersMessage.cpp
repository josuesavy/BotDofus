#include "PartyLocateMembersMessage.h"

void PartyLocateMembersMessage::serialize(Writer *output)
{
  this->serializeAs_PartyLocateMembersMessage(output);
}

void PartyLocateMembersMessage::serializeAs_PartyLocateMembersMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  output->writeShort((short)this->geopositions.size());
  for(uint _i1 = 0; _i1 < this->geopositions.size(); _i1++)
  {
    (this->geopositions[_i1]).serializeAs_PartyMemberGeoPosition(output);
  }
}

void PartyLocateMembersMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyLocateMembersMessage(input);
}

void PartyLocateMembersMessage::deserializeAs_PartyLocateMembersMessage(Reader *input)
{
  PartyMemberGeoPosition _item1 ;
  AbstractPartyMessage::deserialize(input);
  uint _geopositionsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _geopositionsLen; _i1++)
  {
    _item1 = PartyMemberGeoPosition();
    _item1.deserialize(input);
    this->geopositions.append(_item1);
  }
}

void PartyLocateMembersMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyLocateMembersMessage(tree);
}

void PartyLocateMembersMessage::deserializeAsyncAs_PartyLocateMembersMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  this->_geopositionstree = tree.addChild(std::bind(&PartyLocateMembersMessage::_geopositionstreeFunc, this, std::placeholders::_1));
}

void PartyLocateMembersMessage::_geopositionstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_geopositionstree.addChild(std::bind(&PartyLocateMembersMessage::_geopositionsFunc, this, std::placeholders::_1));
  }
}

void PartyLocateMembersMessage::_geopositionsFunc(Reader *input)
{
  PartyMemberGeoPosition _item = PartyMemberGeoPosition();
  _item.deserialize(input);
  this->geopositions.append(_item);
}

PartyLocateMembersMessage::PartyLocateMembersMessage()
{
  m_type = MessageEnum::PARTYLOCATEMEMBERSMESSAGE;
}

