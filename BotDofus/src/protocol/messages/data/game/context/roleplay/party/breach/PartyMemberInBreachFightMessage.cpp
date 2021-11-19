#include "PartyMemberInBreachFightMessage.h"

void PartyMemberInBreachFightMessage::serialize(Writer *output)
{
  this->serializeAs_PartyMemberInBreachFightMessage(output);
}

void PartyMemberInBreachFightMessage::serializeAs_PartyMemberInBreachFightMessage(Writer *output)
{
  AbstractPartyMemberInFightMessage::serializeAs_AbstractPartyMemberInFightMessage(output);
  if(this->floor < 0)
  {
    qDebug()<<"ERREUR - PartyMemberInBreachFightMessage -"<<"Forbidden value (" << this->floor << ") on element floor.";
  }
  output->writeVarInt((int)this->floor);
  if(this->room < 0)
  {
    qDebug()<<"ERREUR - PartyMemberInBreachFightMessage -"<<"Forbidden value (" << this->room << ") on element room.";
  }
  output->writeByte(this->room);
}

void PartyMemberInBreachFightMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyMemberInBreachFightMessage(input);
}

void PartyMemberInBreachFightMessage::deserializeAs_PartyMemberInBreachFightMessage(Reader *input)
{
  AbstractPartyMemberInFightMessage::deserialize(input);
  this->_floorFunc(input);
  this->_roomFunc(input);
}

void PartyMemberInBreachFightMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyMemberInBreachFightMessage(tree);
}

void PartyMemberInBreachFightMessage::deserializeAsyncAs_PartyMemberInBreachFightMessage(FuncTree tree)
{
  AbstractPartyMemberInFightMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyMemberInBreachFightMessage::_floorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyMemberInBreachFightMessage::_roomFunc, this, std::placeholders::_1));
}

void PartyMemberInBreachFightMessage::_floorFunc(Reader *input)
{
  this->floor = input->readVarUhInt();
  if(this->floor < 0)
  {
    qDebug()<<"ERREUR - PartyMemberInBreachFightMessage -"<<"Forbidden value (" << this->floor << ") on element of PartyMemberInBreachFightMessage.floor.";
  }
}

void PartyMemberInBreachFightMessage::_roomFunc(Reader *input)
{
  this->room = input->readByte();
  if(this->room < 0)
  {
    qDebug()<<"ERREUR - PartyMemberInBreachFightMessage -"<<"Forbidden value (" << this->room << ") on element of PartyMemberInBreachFightMessage.room.";
  }
}

PartyMemberInBreachFightMessage::PartyMemberInBreachFightMessage()
{
  m_type = MessageEnum::PARTYMEMBERINBREACHFIGHTMESSAGE;
}

