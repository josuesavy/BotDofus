#include "ChallengeFightJoinRefusedMessage.h"

void ChallengeFightJoinRefusedMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeFightJoinRefusedMessage(output);
}

void ChallengeFightJoinRefusedMessage::serializeAs_ChallengeFightJoinRefusedMessage(Writer *output)
{
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ChallengeFightJoinRefusedMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  output->writeByte(this->reason);
}

void ChallengeFightJoinRefusedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeFightJoinRefusedMessage(input);
}

void ChallengeFightJoinRefusedMessage::deserializeAs_ChallengeFightJoinRefusedMessage(Reader *input)
{
  this->_playerIdFunc(input);
  this->_reasonFunc(input);
}

void ChallengeFightJoinRefusedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeFightJoinRefusedMessage(tree);
}

void ChallengeFightJoinRefusedMessage::deserializeAsyncAs_ChallengeFightJoinRefusedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChallengeFightJoinRefusedMessage::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChallengeFightJoinRefusedMessage::_reasonFunc, this, std::placeholders::_1));
}

void ChallengeFightJoinRefusedMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ChallengeFightJoinRefusedMessage -"<<"Forbidden value (" << this->playerId << ") on element of ChallengeFightJoinRefusedMessage.playerId.";
  }
}

void ChallengeFightJoinRefusedMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
}

ChallengeFightJoinRefusedMessage::ChallengeFightJoinRefusedMessage()
{
  m_type = MessageEnum::CHALLENGEFIGHTJOINREFUSEDMESSAGE;
}

