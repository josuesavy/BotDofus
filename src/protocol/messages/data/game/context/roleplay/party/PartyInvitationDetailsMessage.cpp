#include "PartyInvitationDetailsMessage.h"

void PartyInvitationDetailsMessage::serialize(Writer *output)
{
  this->serializeAs_PartyInvitationDetailsMessage(output);
}

void PartyInvitationDetailsMessage::serializeAs_PartyInvitationDetailsMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  output->writeByte(this->partyType);
  output->writeUTF(this->partyName);
  if(this->fromId < 0 || this->fromId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyInvitationDetailsMessage -"<<"Forbidden value (" << this->fromId << ") on element fromId.";
  }
  output->writeVarLong((double)this->fromId);
  output->writeUTF(this->fromName);
  if(this->leaderId < 0 || this->leaderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyInvitationDetailsMessage -"<<"Forbidden value (" << this->leaderId << ") on element leaderId.";
  }
  output->writeVarLong((double)this->leaderId);
  output->writeShort((short)this->members.size());
  for(uint _i6 = 0; _i6 < this->members.size(); _i6++)
  {
    output->writeShort((short)qSharedPointerCast<PartyInvitationMemberInformations>(this->members[_i6])->getTypes().last());
    qSharedPointerCast<PartyInvitationMemberInformations>(this->members[_i6])->serialize(output);
  }
  output->writeShort((short)this->guests.size());
  for(uint _i7 = 0; _i7 < this->guests.size(); _i7++)
  {
    qSharedPointerCast<PartyGuestInformations>(this->guests[_i7])->serializeAs_PartyGuestInformations(output);
  }
}

void PartyInvitationDetailsMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyInvitationDetailsMessage(input);
}

void PartyInvitationDetailsMessage::deserializeAs_PartyInvitationDetailsMessage(Reader *input)
{
  uint _id6 = 0;
  QSharedPointer<PartyInvitationMemberInformations> _item6 ;
  QSharedPointer<PartyGuestInformations> _item7 ;
  AbstractPartyMessage::deserialize(input);
  this->_partyTypeFunc(input);
  this->_partyNameFunc(input);
  this->_fromIdFunc(input);
  this->_fromNameFunc(input);
  this->_leaderIdFunc(input);
  uint _membersLen = input->readUShort();
  for(uint _i6 = 0; _i6 < _membersLen; _i6++)
  {
    _id6 = input->readUShort();
    _item6 = qSharedPointerCast<PartyInvitationMemberInformations>(ClassManagerSingleton::get()->getClass(_id6));
    _item6->deserialize(input);
    this->members.append(_item6);
  }
  uint _guestsLen = input->readUShort();
  for(uint _i7 = 0; _i7 < _guestsLen; _i7++)
  {
    _item7 = QSharedPointer<PartyGuestInformations>(new PartyGuestInformations() );
    _item7->deserialize(input);
    this->guests.append(_item7);
  }
}

void PartyInvitationDetailsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyInvitationDetailsMessage(tree);
}

void PartyInvitationDetailsMessage::deserializeAsyncAs_PartyInvitationDetailsMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyInvitationDetailsMessage::_partyTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyInvitationDetailsMessage::_partyNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyInvitationDetailsMessage::_fromIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyInvitationDetailsMessage::_fromNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyInvitationDetailsMessage::_leaderIdFunc, this, std::placeholders::_1));
  this->_memberstree = tree.addChild(std::bind(&PartyInvitationDetailsMessage::_memberstreeFunc, this, std::placeholders::_1));
  this->_gueststree = tree.addChild(std::bind(&PartyInvitationDetailsMessage::_gueststreeFunc, this, std::placeholders::_1));
}

void PartyInvitationDetailsMessage::_partyTypeFunc(Reader *input)
{
  this->partyType = input->readByte();
  if(this->partyType < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationDetailsMessage -"<<"Forbidden value (" << this->partyType << ") on element of PartyInvitationDetailsMessage.partyType.";
  }
}

void PartyInvitationDetailsMessage::_partyNameFunc(Reader *input)
{
  this->partyName = input->readUTF();
}

void PartyInvitationDetailsMessage::_fromIdFunc(Reader *input)
{
  this->fromId = input->readVarUhLong();
  if(this->fromId < 0 || this->fromId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyInvitationDetailsMessage -"<<"Forbidden value (" << this->fromId << ") on element of PartyInvitationDetailsMessage.fromId.";
  }
}

void PartyInvitationDetailsMessage::_fromNameFunc(Reader *input)
{
  this->fromName = input->readUTF();
}

void PartyInvitationDetailsMessage::_leaderIdFunc(Reader *input)
{
  this->leaderId = input->readVarUhLong();
  if(this->leaderId < 0 || this->leaderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyInvitationDetailsMessage -"<<"Forbidden value (" << this->leaderId << ") on element of PartyInvitationDetailsMessage.leaderId.";
  }
}

void PartyInvitationDetailsMessage::_memberstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_memberstree.addChild(std::bind(&PartyInvitationDetailsMessage::_membersFunc, this, std::placeholders::_1));
  }
}

void PartyInvitationDetailsMessage::_membersFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<PartyInvitationMemberInformations> _item = qSharedPointerCast<PartyInvitationMemberInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->members.append(_item);
}

void PartyInvitationDetailsMessage::_gueststreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_gueststree.addChild(std::bind(&PartyInvitationDetailsMessage::_guestsFunc, this, std::placeholders::_1));
  }
}

void PartyInvitationDetailsMessage::_guestsFunc(Reader *input)
{
  QSharedPointer<PartyGuestInformations> _item = QSharedPointer<PartyGuestInformations>(new PartyGuestInformations() );
  _item->deserialize(input);
  this->guests.append(_item);
}

PartyInvitationDetailsMessage::PartyInvitationDetailsMessage()
{
  m_type = MessageEnum::PARTYINVITATIONDETAILSMESSAGE;
}

