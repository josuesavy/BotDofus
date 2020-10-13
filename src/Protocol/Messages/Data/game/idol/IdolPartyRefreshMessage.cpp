#include "IdolPartyRefreshMessage.h"

void IdolPartyRefreshMessage::serialize(Writer *output)
{
  this->serializeAs_IdolPartyRefreshMessage(output);
}

void IdolPartyRefreshMessage::serializeAs_IdolPartyRefreshMessage(Writer *output)
{
  this->partyIdol->serializeAs_PartyIdol(output);
}

void IdolPartyRefreshMessage::deserialize(Reader *input)
{
  this->deserializeAs_IdolPartyRefreshMessage(input);
}

void IdolPartyRefreshMessage::deserializeAs_IdolPartyRefreshMessage(Reader *input)
{
  this->partyIdol = QSharedPointer<PartyIdol>(new PartyIdol() );
  this->partyIdol->deserialize(input);
}

void IdolPartyRefreshMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IdolPartyRefreshMessage(tree);
}

void IdolPartyRefreshMessage::deserializeAsyncAs_IdolPartyRefreshMessage(FuncTree tree)
{
  this->_partyIdoltree = tree.addChild(std::bind(&IdolPartyRefreshMessage::_partyIdoltreeFunc, this, std::placeholders::_1));
}

void IdolPartyRefreshMessage::_partyIdoltreeFunc(Reader *input)
{
  this->partyIdol = QSharedPointer<PartyIdol>(new PartyIdol() );
  this->partyIdol->deserializeAsync(this->_partyIdoltree);
}

IdolPartyRefreshMessage::IdolPartyRefreshMessage()
{
  m_type = MessageEnum::IDOLPARTYREFRESHMESSAGE;
}

