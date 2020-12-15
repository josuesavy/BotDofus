#include "PlayerStatusUpdateRequestMessage.h"

void PlayerStatusUpdateRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PlayerStatusUpdateRequestMessage(output);
}

void PlayerStatusUpdateRequestMessage::serializeAs_PlayerStatusUpdateRequestMessage(Writer *output)
{
  output->writeShort((short)this->status->getTypes().last());
  this->status->serialize(output);
}

void PlayerStatusUpdateRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PlayerStatusUpdateRequestMessage(input);
}

void PlayerStatusUpdateRequestMessage::deserializeAs_PlayerStatusUpdateRequestMessage(Reader *input)
{
  uint _id1 = input->readUShort();
  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_id1));
  this->status->deserialize(input);
}

void PlayerStatusUpdateRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PlayerStatusUpdateRequestMessage(tree);
}

void PlayerStatusUpdateRequestMessage::deserializeAsyncAs_PlayerStatusUpdateRequestMessage(FuncTree tree)
{
  this->_statustree = tree.addChild(std::bind(&PlayerStatusUpdateRequestMessage::_statustreeFunc, this, std::placeholders::_1));
}

void PlayerStatusUpdateRequestMessage::_statustreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_id));
  this->status->deserializeAsync(this->_statustree);
}

PlayerStatusUpdateRequestMessage::PlayerStatusUpdateRequestMessage()
{
  m_type = MessageEnum::PLAYERSTATUSUPDATEREQUESTMESSAGE;
}

