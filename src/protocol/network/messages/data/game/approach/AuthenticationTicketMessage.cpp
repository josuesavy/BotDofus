#include "AuthenticationTicketMessage.h"

void AuthenticationTicketMessage::serialize(Writer *output)
{
  this->serializeAs_AuthenticationTicketMessage(output);
}

void AuthenticationTicketMessage::serializeAs_AuthenticationTicketMessage(Writer *output)
{
  output->writeUTF(this->lang);
  output->writeUTF(this->ticket);
}

void AuthenticationTicketMessage::deserialize(Reader *input)
{
  this->deserializeAs_AuthenticationTicketMessage(input);
}

void AuthenticationTicketMessage::deserializeAs_AuthenticationTicketMessage(Reader *input)
{
  this->_langFunc(input);
  this->_ticketFunc(input);
}

void AuthenticationTicketMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AuthenticationTicketMessage(tree);
}

void AuthenticationTicketMessage::deserializeAsyncAs_AuthenticationTicketMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AuthenticationTicketMessage::_langFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AuthenticationTicketMessage::_ticketFunc, this, std::placeholders::_1));
}

void AuthenticationTicketMessage::_langFunc(Reader *input)
{
  this->lang = input->readUTF();
}

void AuthenticationTicketMessage::_ticketFunc(Reader *input)
{
  this->ticket = input->readUTF();
}

AuthenticationTicketMessage::AuthenticationTicketMessage()
{
  m_type = MessageEnum::AUTHENTICATIONTICKETMESSAGE;
}

