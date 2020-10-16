#include "AbstractPartyMemberInFightMessage.h"

void AbstractPartyMemberInFightMessage::serialize(Writer *output)
{
  this->serializeAs_AbstractPartyMemberInFightMessage(output);
}

void AbstractPartyMemberInFightMessage::serializeAs_AbstractPartyMemberInFightMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  output->writeByte(this->reason);
  if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AbstractPartyMemberInFightMessage -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  output->writeVarLong((double)this->memberId);
  if(this->memberAccountId < 0)
  {
    qDebug()<<"ERREUR - AbstractPartyMemberInFightMessage -"<<"Forbidden value (" << this->memberAccountId << ") on element memberAccountId.";
  }
  output->writeInt((int)this->memberAccountId);
  output->writeUTF(this->memberName);
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - AbstractPartyMemberInFightMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  output->writeVarShort((int)this->timeBeforeFightStart);
}

void AbstractPartyMemberInFightMessage::deserialize(Reader *input)
{
  this->deserializeAs_AbstractPartyMemberInFightMessage(input);
}

void AbstractPartyMemberInFightMessage::deserializeAs_AbstractPartyMemberInFightMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
  this->_reasonFunc(input);
  this->_memberIdFunc(input);
  this->_memberAccountIdFunc(input);
  this->_memberNameFunc(input);
  this->_fightIdFunc(input);
  this->_timeBeforeFightStartFunc(input);
}

void AbstractPartyMemberInFightMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AbstractPartyMemberInFightMessage(tree);
}

void AbstractPartyMemberInFightMessage::deserializeAsyncAs_AbstractPartyMemberInFightMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&AbstractPartyMemberInFightMessage::_reasonFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractPartyMemberInFightMessage::_memberIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractPartyMemberInFightMessage::_memberAccountIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractPartyMemberInFightMessage::_memberNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractPartyMemberInFightMessage::_fightIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractPartyMemberInFightMessage::_timeBeforeFightStartFunc, this, std::placeholders::_1));
}

void AbstractPartyMemberInFightMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - AbstractPartyMemberInFightMessage -"<<"Forbidden value (" << this->reason << ") on element of AbstractPartyMemberInFightMessage.reason.";
  }
}

void AbstractPartyMemberInFightMessage::_memberIdFunc(Reader *input)
{
  this->memberId = input->readVarUhLong();
  if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AbstractPartyMemberInFightMessage -"<<"Forbidden value (" << this->memberId << ") on element of AbstractPartyMemberInFightMessage.memberId.";
  }
}

void AbstractPartyMemberInFightMessage::_memberAccountIdFunc(Reader *input)
{
  this->memberAccountId = input->readInt();
  if(this->memberAccountId < 0)
  {
    qDebug()<<"ERREUR - AbstractPartyMemberInFightMessage -"<<"Forbidden value (" << this->memberAccountId << ") on element of AbstractPartyMemberInFightMessage.memberAccountId.";
  }
}

void AbstractPartyMemberInFightMessage::_memberNameFunc(Reader *input)
{
  this->memberName = input->readUTF();
}

void AbstractPartyMemberInFightMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - AbstractPartyMemberInFightMessage -"<<"Forbidden value (" << this->fightId << ") on element of AbstractPartyMemberInFightMessage.fightId.";
  }
}

void AbstractPartyMemberInFightMessage::_timeBeforeFightStartFunc(Reader *input)
{
  this->timeBeforeFightStart = input->readVarShort();
}

AbstractPartyMemberInFightMessage::AbstractPartyMemberInFightMessage()
{
  m_type = MessageEnum::ABSTRACTPARTYMEMBERINFIGHTMESSAGE;
}

