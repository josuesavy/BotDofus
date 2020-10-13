#include "PartyNameSetErrorMessage.h"

void PartyNameSetErrorMessage::serialize(Writer *output)
{
  this->serializeAs_PartyNameSetErrorMessage(output);
}

void PartyNameSetErrorMessage::serializeAs_PartyNameSetErrorMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  output->writeByte(this->result);
}

void PartyNameSetErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyNameSetErrorMessage(input);
}

void PartyNameSetErrorMessage::deserializeAs_PartyNameSetErrorMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
  this->_resultFunc(input);
}

void PartyNameSetErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyNameSetErrorMessage(tree);
}

void PartyNameSetErrorMessage::deserializeAsyncAs_PartyNameSetErrorMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyNameSetErrorMessage::_resultFunc, this, std::placeholders::_1));
}

void PartyNameSetErrorMessage::_resultFunc(Reader *input)
{
  this->result = input->readByte();
  if(this->result < 0)
  {
    qDebug()<<"ERREUR - PartyNameSetErrorMessage -"<<"Forbidden value (" << this->result << ") on element of PartyNameSetErrorMessage.result.";
  }
}

PartyNameSetErrorMessage::PartyNameSetErrorMessage()
{
  m_type = MessageEnum::PARTYNAMESETERRORMESSAGE;
}

