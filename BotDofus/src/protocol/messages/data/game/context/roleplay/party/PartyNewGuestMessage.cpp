#include "PartyNewGuestMessage.h"

void PartyNewGuestMessage::serialize(Writer *output)
{
  this->serializeAs_PartyNewGuestMessage(output);
}

void PartyNewGuestMessage::serializeAs_PartyNewGuestMessage(Writer *output)
{
  AbstractPartyEventMessage::serializeAs_AbstractPartyEventMessage(output);
  this->guest->serializeAs_PartyGuestInformations(output);
}

void PartyNewGuestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyNewGuestMessage(input);
}

void PartyNewGuestMessage::deserializeAs_PartyNewGuestMessage(Reader *input)
{
  AbstractPartyEventMessage::deserialize(input);
  this->guest = QSharedPointer<PartyGuestInformations>(new PartyGuestInformations() );
  this->guest->deserialize(input);
}

void PartyNewGuestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyNewGuestMessage(tree);
}

void PartyNewGuestMessage::deserializeAsyncAs_PartyNewGuestMessage(FuncTree tree)
{
  AbstractPartyEventMessage::deserializeAsync(tree);
  this->_guesttree = tree.addChild(std::bind(&PartyNewGuestMessage::_guesttreeFunc, this, std::placeholders::_1));
}

void PartyNewGuestMessage::_guesttreeFunc(Reader *input)
{
  this->guest = QSharedPointer<PartyGuestInformations>(new PartyGuestInformations() );
  this->guest->deserializeAsync(this->_guesttree);
}

PartyNewGuestMessage::PartyNewGuestMessage()
{
  m_type = MessageEnum::PARTYNEWGUESTMESSAGE;
}

