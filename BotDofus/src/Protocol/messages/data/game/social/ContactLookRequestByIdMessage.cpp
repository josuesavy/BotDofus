#include "ContactLookRequestByIdMessage.h"

void ContactLookRequestByIdMessage::serialize(Writer *output)
{
  this->serializeAs_ContactLookRequestByIdMessage(output);
}

void ContactLookRequestByIdMessage::serializeAs_ContactLookRequestByIdMessage(Writer *output)
{
  ContactLookRequestMessage::serializeAs_ContactLookRequestMessage(output);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ContactLookRequestByIdMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void ContactLookRequestByIdMessage::deserialize(Reader *input)
{
  this->deserializeAs_ContactLookRequestByIdMessage(input);
}

void ContactLookRequestByIdMessage::deserializeAs_ContactLookRequestByIdMessage(Reader *input)
{
  ContactLookRequestMessage::deserialize(input);
  this->_playerIdFunc(input);
}

void ContactLookRequestByIdMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ContactLookRequestByIdMessage(tree);
}

void ContactLookRequestByIdMessage::deserializeAsyncAs_ContactLookRequestByIdMessage(FuncTree tree)
{
  ContactLookRequestMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ContactLookRequestByIdMessage::_playerIdFunc, this, std::placeholders::_1));
}

void ContactLookRequestByIdMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ContactLookRequestByIdMessage -"<<"Forbidden value (" << this->playerId << ") on element of ContactLookRequestByIdMessage.playerId.";
  }
}

ContactLookRequestByIdMessage::ContactLookRequestByIdMessage()
{
  m_type = MessageEnum::CONTACTLOOKREQUESTBYIDMESSAGE;
}

