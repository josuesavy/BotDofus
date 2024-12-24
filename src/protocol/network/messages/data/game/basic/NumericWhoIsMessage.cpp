#include "NumericWhoIsMessage.h"

void NumericWhoIsMessage::serialize(Writer *output)
{
  this->serializeAs_NumericWhoIsMessage(output);
}

void NumericWhoIsMessage::serializeAs_NumericWhoIsMessage(Writer *output)
{
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - NumericWhoIsMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - NumericWhoIsMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  output->writeInt((int)this->accountId);
}

void NumericWhoIsMessage::deserialize(Reader *input)
{
  this->deserializeAs_NumericWhoIsMessage(input);
}

void NumericWhoIsMessage::deserializeAs_NumericWhoIsMessage(Reader *input)
{
  this->_playerIdFunc(input);
  this->_accountIdFunc(input);
}

void NumericWhoIsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_NumericWhoIsMessage(tree);
}

void NumericWhoIsMessage::deserializeAsyncAs_NumericWhoIsMessage(FuncTree tree)
{
  tree.addChild(std::bind(&NumericWhoIsMessage::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&NumericWhoIsMessage::_accountIdFunc, this, std::placeholders::_1));
}

void NumericWhoIsMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - NumericWhoIsMessage -"<<"Forbidden value (" << this->playerId << ") on element of NumericWhoIsMessage.playerId.";
  }
}

void NumericWhoIsMessage::_accountIdFunc(Reader *input)
{
  this->accountId = input->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - NumericWhoIsMessage -"<<"Forbidden value (" << this->accountId << ") on element of NumericWhoIsMessage.accountId.";
  }
}

NumericWhoIsMessage::NumericWhoIsMessage()
{
  m_type = MessageEnum::NUMERICWHOISMESSAGE;
}

