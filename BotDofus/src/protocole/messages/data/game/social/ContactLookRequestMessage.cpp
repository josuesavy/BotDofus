#include "ContactLookRequestMessage.h"

void ContactLookRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ContactLookRequestMessage(output);
}

void ContactLookRequestMessage::serializeAs_ContactLookRequestMessage(Writer *output)
{
  if(this->requestId < 0 || this->requestId > 255)
  {
    qDebug()<<"ERREUR - ContactLookRequestMessage -"<<"Forbidden value (" << this->requestId << ") on element requestId.";
  }
  output->writeByte(this->requestId);
  output->writeByte(this->contactType);
}

void ContactLookRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ContactLookRequestMessage(input);
}

void ContactLookRequestMessage::deserializeAs_ContactLookRequestMessage(Reader *input)
{
  this->_requestIdFunc(input);
  this->_contactTypeFunc(input);
}

void ContactLookRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ContactLookRequestMessage(tree);
}

void ContactLookRequestMessage::deserializeAsyncAs_ContactLookRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ContactLookRequestMessage::_requestIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ContactLookRequestMessage::_contactTypeFunc, this, std::placeholders::_1));
}

void ContactLookRequestMessage::_requestIdFunc(Reader *input)
{
  this->requestId = input->readUByte();
  if(this->requestId < 0 || this->requestId > 255)
  {
    qDebug()<<"ERREUR - ContactLookRequestMessage -"<<"Forbidden value (" << this->requestId << ") on element of ContactLookRequestMessage.requestId.";
  }
}

void ContactLookRequestMessage::_contactTypeFunc(Reader *input)
{
  this->contactType = input->readByte();
  if(this->contactType < 0)
  {
    qDebug()<<"ERREUR - ContactLookRequestMessage -"<<"Forbidden value (" << this->contactType << ") on element of ContactLookRequestMessage.contactType.";
  }
}

ContactLookRequestMessage::ContactLookRequestMessage()
{
  m_type = MessageEnum::CONTACTLOOKREQUESTMESSAGE;
}

