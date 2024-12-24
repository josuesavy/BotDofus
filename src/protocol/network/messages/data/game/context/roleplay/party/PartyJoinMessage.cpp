#include "PartyJoinMessage.h"

void PartyJoinMessage::serialize(Writer *output)
{
  this->serializeAs_PartyJoinMessage(output);
}

void PartyJoinMessage::serializeAs_PartyJoinMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  output->writeByte(this->partyType);
  if(this->partyLeaderId < 0 || this->partyLeaderId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyJoinMessage -"<<"Forbidden value (" << this->partyLeaderId << ") on element partyLeaderId.";
  }
  output->writeVarLong((double)this->partyLeaderId);
  if(this->maxParticipants < 0)
  {
    qDebug()<<"ERREUR - PartyJoinMessage -"<<"Forbidden value (" << this->maxParticipants << ") on element maxParticipants.";
  }
  output->writeByte(this->maxParticipants);
  output->writeShort((short)this->members.size());
  for(uint _i4 = 0; _i4 < this->members.size(); _i4++)
  {
    output->writeShort((short)qSharedPointerCast<PartyMemberInformations>(this->members[_i4])->getTypes().last());
    qSharedPointerCast<PartyMemberInformations>(this->members[_i4])->serialize(output);
  }
  output->writeShort((short)this->guests.size());
  for(uint _i5 = 0; _i5 < this->guests.size(); _i5++)
  {
    qSharedPointerCast<PartyGuestInformations>(this->guests[_i5])->serializeAs_PartyGuestInformations(output);
  }
  output->writeBool(this->restricted);
  output->writeUTF(this->partyName);
}

void PartyJoinMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyJoinMessage(input);
}

void PartyJoinMessage::deserializeAs_PartyJoinMessage(Reader *input)
{
  uint _id4 = 0;
  QSharedPointer<PartyMemberInformations> _item4 ;
  QSharedPointer<PartyGuestInformations> _item5 ;
  AbstractPartyMessage::deserialize(input);
  this->_partyTypeFunc(input);
  this->_partyLeaderIdFunc(input);
  this->_maxParticipantsFunc(input);
  uint _membersLen = uint(input->readUShort());
  for(uint _i4 = 0; _i4 < _membersLen; _i4++)
  {
    _id4 = uint(input->readUShort());
    _item4 = qSharedPointerCast<PartyMemberInformations>(ClassManagerSingleton::get()->getClass(_id4));
    _item4->deserialize(input);
    this->members.append(_item4);
  }
  uint _guestsLen = uint(input->readUShort());
  for(uint _i5 = 0; _i5 < _guestsLen; _i5++)
  {
    _item5 = QSharedPointer<PartyGuestInformations>(new PartyGuestInformations() );
    _item5->deserialize(input);
    this->guests.append(_item5);
  }
  this->_restrictedFunc(input);
  this->_partyNameFunc(input);
}

void PartyJoinMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyJoinMessage(tree);
}

void PartyJoinMessage::deserializeAsyncAs_PartyJoinMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyJoinMessage::_partyTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyJoinMessage::_partyLeaderIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyJoinMessage::_maxParticipantsFunc, this, std::placeholders::_1));
  this->_memberstree = tree.addChild(std::bind(&PartyJoinMessage::_memberstreeFunc, this, std::placeholders::_1));
  this->_gueststree = tree.addChild(std::bind(&PartyJoinMessage::_gueststreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyJoinMessage::_restrictedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyJoinMessage::_partyNameFunc, this, std::placeholders::_1));
}

void PartyJoinMessage::_partyTypeFunc(Reader *input)
{
  this->partyType = input->readByte();
  if(this->partyType < 0)
  {
    qDebug()<<"ERREUR - PartyJoinMessage -"<<"Forbidden value (" << this->partyType << ") on element of PartyJoinMessage.partyType.";
  }
}

void PartyJoinMessage::_partyLeaderIdFunc(Reader *input)
{
  this->partyLeaderId = input->readVarUhLong();
  if(this->partyLeaderId < 0 || this->partyLeaderId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyJoinMessage -"<<"Forbidden value (" << this->partyLeaderId << ") on element of PartyJoinMessage.partyLeaderId.";
  }
}

void PartyJoinMessage::_maxParticipantsFunc(Reader *input)
{
  this->maxParticipants = input->readByte();
  if(this->maxParticipants < 0)
  {
    qDebug()<<"ERREUR - PartyJoinMessage -"<<"Forbidden value (" << this->maxParticipants << ") on element of PartyJoinMessage.maxParticipants.";
  }
}

void PartyJoinMessage::_memberstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_memberstree.addChild(std::bind(&PartyJoinMessage::_membersFunc, this, std::placeholders::_1));
  }
}

void PartyJoinMessage::_membersFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<PartyMemberInformations> _item = qSharedPointerCast<PartyMemberInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->members.append(_item);
}

void PartyJoinMessage::_gueststreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_gueststree.addChild(std::bind(&PartyJoinMessage::_guestsFunc, this, std::placeholders::_1));
  }
}

void PartyJoinMessage::_guestsFunc(Reader *input)
{
  QSharedPointer<PartyGuestInformations> _item = QSharedPointer<PartyGuestInformations>(new PartyGuestInformations() );
  _item->deserialize(input);
  this->guests.append(_item);
}

void PartyJoinMessage::_restrictedFunc(Reader *input)
{
  this->restricted = input->readBool();
}

void PartyJoinMessage::_partyNameFunc(Reader *input)
{
  this->partyName = input->readUTF();
}

PartyJoinMessage::PartyJoinMessage()
{
  m_type = MessageEnum::PARTYJOINMESSAGE;
}

