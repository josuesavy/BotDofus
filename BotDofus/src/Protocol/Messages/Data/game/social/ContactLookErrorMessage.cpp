#include "ContactLookErrorMessage.h"

void ContactLookErrorMessage::serialize(Writer *output)
{
  this->serializeAs_ContactLookErrorMessage(output);
}

void ContactLookErrorMessage::serializeAs_ContactLookErrorMessage(Writer *output)
{
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - ContactLookErrorMessage -"<<"Forbidden value (" << this->requestId << ") on element requestId.";
  }
  output->writeVarInt((int)this->requestId);
}

void ContactLookErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_ContactLookErrorMessage(input);
}

void ContactLookErrorMessage::deserializeAs_ContactLookErrorMessage(Reader *input)
{
  this->_requestIdFunc(input);
}

void ContactLookErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ContactLookErrorMessage(tree);
}

void ContactLookErrorMessage::deserializeAsyncAs_ContactLookErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ContactLookErrorMessage::_requestIdFunc, this, std::placeholders::_1));
}

void ContactLookErrorMessage::_requestIdFunc(Reader *input)
{
  this->requestId = input->readVarUhInt();
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - ContactLookErrorMessage -"<<"Forbidden value (" << this->requestId << ") on element of ContactLookErrorMessage.requestId.";
  }
}

ContactLookErrorMessage::ContactLookErrorMessage()
{
  m_type = MessageEnum::CONTACTLOOKERRORMESSAGE;
}

