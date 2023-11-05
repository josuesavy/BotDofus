#include "AllianceApplicationReceivedMessage.h"

void AllianceApplicationReceivedMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceApplicationReceivedMessage(output);
}

void AllianceApplicationReceivedMessage::serializeAs_AllianceApplicationReceivedMessage(Writer *output)
{
  output->writeUTF(this->playerName);
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AllianceApplicationReceivedMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void AllianceApplicationReceivedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceApplicationReceivedMessage(input);
}

void AllianceApplicationReceivedMessage::deserializeAs_AllianceApplicationReceivedMessage(Reader *input)
{
  this->_playerNameFunc(input);
  this->_playerIdFunc(input);
}

void AllianceApplicationReceivedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceApplicationReceivedMessage(tree);
}

void AllianceApplicationReceivedMessage::deserializeAsyncAs_AllianceApplicationReceivedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceApplicationReceivedMessage::_playerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceApplicationReceivedMessage::_playerIdFunc, this, std::placeholders::_1));
}

void AllianceApplicationReceivedMessage::_playerNameFunc(Reader *input)
{
  this->playerName = input->readUTF();
}

void AllianceApplicationReceivedMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AllianceApplicationReceivedMessage -"<<"Forbidden value (" << this->playerId << ") on element of AllianceApplicationReceivedMessage.playerId.";
  }
}

AllianceApplicationReceivedMessage::AllianceApplicationReceivedMessage()
{
  m_type = MessageEnum::ALLIANCEAPPLICATIONRECEIVEDMESSAGE;
}

