#include "NumericWhoIsRequestMessage.h"

void NumericWhoIsRequestMessage::serialize(Writer *output)
{
  this->serializeAs_NumericWhoIsRequestMessage(output);
}

void NumericWhoIsRequestMessage::serializeAs_NumericWhoIsRequestMessage(Writer *output)
{
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - NumericWhoIsRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void NumericWhoIsRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_NumericWhoIsRequestMessage(input);
}

void NumericWhoIsRequestMessage::deserializeAs_NumericWhoIsRequestMessage(Reader *input)
{
  this->_playerIdFunc(input);
}

void NumericWhoIsRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_NumericWhoIsRequestMessage(tree);
}

void NumericWhoIsRequestMessage::deserializeAsyncAs_NumericWhoIsRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&NumericWhoIsRequestMessage::_playerIdFunc, this, std::placeholders::_1));
}

void NumericWhoIsRequestMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - NumericWhoIsRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element of NumericWhoIsRequestMessage.playerId.";
  }
}

NumericWhoIsRequestMessage::NumericWhoIsRequestMessage()
{
  m_type = MessageEnum::NUMERICWHOISREQUESTMESSAGE;
}

