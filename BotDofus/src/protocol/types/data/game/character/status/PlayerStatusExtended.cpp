#include "PlayerStatusExtended.h"

void PlayerStatusExtended::serialize(Writer *output)
{
  this->serializeAs_PlayerStatusExtended(output);
}

void PlayerStatusExtended::serializeAs_PlayerStatusExtended(Writer *output)
{
  PlayerStatus::serializeAs_PlayerStatus(output);
  output->writeUTF(this->message);
}

void PlayerStatusExtended::deserialize(Reader *input)
{
  this->deserializeAs_PlayerStatusExtended(input);
}

void PlayerStatusExtended::deserializeAs_PlayerStatusExtended(Reader *input)
{
  PlayerStatus::deserialize(input);
  this->_messageFunc(input);
}

void PlayerStatusExtended::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PlayerStatusExtended(tree);
}

void PlayerStatusExtended::deserializeAsyncAs_PlayerStatusExtended(FuncTree tree)
{
  PlayerStatus::deserializeAsync(tree);
  tree.addChild(std::bind(&PlayerStatusExtended::_messageFunc, this, std::placeholders::_1));
}

void PlayerStatusExtended::_messageFunc(Reader *input)
{
  this->message = input->readUTF();
}

PlayerStatusExtended::PlayerStatusExtended()
{
  m_types<<ClassEnum::PLAYERSTATUSEXTENDED;
}

bool PlayerStatusExtended::operator==(const PlayerStatusExtended &compared)
{
  if(message == compared.message)
  return true;
  
  return false;
}

