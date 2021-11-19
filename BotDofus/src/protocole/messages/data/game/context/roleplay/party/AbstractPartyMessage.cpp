#include "AbstractPartyMessage.h"

void AbstractPartyMessage::serialize(Writer *output)
{
  this->serializeAs_AbstractPartyMessage(output);
}

void AbstractPartyMessage::serializeAs_AbstractPartyMessage(Writer *output)
{
  if(this->partyId < 0)
  {
    qDebug()<<"ERREUR - AbstractPartyMessage -"<<"Forbidden value (" << this->partyId << ") on element partyId.";
  }
  output->writeVarInt((int)this->partyId);
}

void AbstractPartyMessage::deserialize(Reader *input)
{
  this->deserializeAs_AbstractPartyMessage(input);
}

void AbstractPartyMessage::deserializeAs_AbstractPartyMessage(Reader *input)
{
  this->_partyIdFunc(input);
}

void AbstractPartyMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AbstractPartyMessage(tree);
}

void AbstractPartyMessage::deserializeAsyncAs_AbstractPartyMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AbstractPartyMessage::_partyIdFunc, this, std::placeholders::_1));
}

void AbstractPartyMessage::_partyIdFunc(Reader *input)
{
  this->partyId = input->readVarUhInt();
  if(this->partyId < 0)
  {
    qDebug()<<"ERREUR - AbstractPartyMessage -"<<"Forbidden value (" << this->partyId << ") on element of AbstractPartyMessage.partyId.";
  }
}

AbstractPartyMessage::AbstractPartyMessage()
{
  m_type = MessageEnum::ABSTRACTPARTYMESSAGE;
}

