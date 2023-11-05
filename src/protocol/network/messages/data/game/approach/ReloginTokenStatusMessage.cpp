#include "ReloginTokenStatusMessage.h"

void ReloginTokenStatusMessage::serialize(Writer *output)
{
  this->serializeAs_ReloginTokenStatusMessage(output);
}

void ReloginTokenStatusMessage::serializeAs_ReloginTokenStatusMessage(Writer *output)
{
  output->writeBool(this->validToken);
  output->writeUTF(this->token);
}

void ReloginTokenStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_ReloginTokenStatusMessage(input);
}

void ReloginTokenStatusMessage::deserializeAs_ReloginTokenStatusMessage(Reader *input)
{
  this->_validTokenFunc(input);
  this->_tokenFunc(input);
}

void ReloginTokenStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ReloginTokenStatusMessage(tree);
}

void ReloginTokenStatusMessage::deserializeAsyncAs_ReloginTokenStatusMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ReloginTokenStatusMessage::_validTokenFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ReloginTokenStatusMessage::_tokenFunc, this, std::placeholders::_1));
}

void ReloginTokenStatusMessage::_validTokenFunc(Reader *input)
{
  this->validToken = input->readBool();
}

void ReloginTokenStatusMessage::_tokenFunc(Reader *input)
{
  this->token = input->readUTF();
}

ReloginTokenStatusMessage::ReloginTokenStatusMessage()
{
  m_type = MessageEnum::RELOGINTOKENSTATUSMESSAGE;
}

