#include "PartyFollowStatusUpdateMessage.h"

void PartyFollowStatusUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_PartyFollowStatusUpdateMessage(output);
}

void PartyFollowStatusUpdateMessage::serializeAs_PartyFollowStatusUpdateMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->success);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->isFollowed);
  output->writeByte(_box0);
  if(this->followedId < 0 || this->followedId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyFollowStatusUpdateMessage -"<<"Forbidden value (" << this->followedId << ") on element followedId.";
  }
  output->writeVarLong((double)this->followedId);
}

void PartyFollowStatusUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyFollowStatusUpdateMessage(input);
}

void PartyFollowStatusUpdateMessage::deserializeAs_PartyFollowStatusUpdateMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
  this->deserializeByteBoxes(input);
  this->_followedIdFunc(input);
}

void PartyFollowStatusUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyFollowStatusUpdateMessage(tree);
}

void PartyFollowStatusUpdateMessage::deserializeAsyncAs_PartyFollowStatusUpdateMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyFollowStatusUpdateMessage::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyFollowStatusUpdateMessage::_followedIdFunc, this, std::placeholders::_1));
}

void PartyFollowStatusUpdateMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->success = BooleanByteWrapper::getFlag(_box0, 0);
  this->isFollowed = BooleanByteWrapper::getFlag(_box0, 1);
}

void PartyFollowStatusUpdateMessage::_followedIdFunc(Reader *input)
{
  this->followedId = input->readVarUhLong();
  if(this->followedId < 0 || this->followedId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyFollowStatusUpdateMessage -"<<"Forbidden value (" << this->followedId << ") on element of PartyFollowStatusUpdateMessage.followedId.";
  }
}

PartyFollowStatusUpdateMessage::PartyFollowStatusUpdateMessage()
{
  m_type = MessageEnum::PARTYFOLLOWSTATUSUPDATEMESSAGE;
}

