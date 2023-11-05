#include "AllianceApplicationListenMessage.h"

void AllianceApplicationListenMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceApplicationListenMessage(output);
}

void AllianceApplicationListenMessage::serializeAs_AllianceApplicationListenMessage(Writer *output)
{
  output->writeBool(this->listen);
}

void AllianceApplicationListenMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceApplicationListenMessage(input);
}

void AllianceApplicationListenMessage::deserializeAs_AllianceApplicationListenMessage(Reader *input)
{
  this->_listenFunc(input);
}

void AllianceApplicationListenMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceApplicationListenMessage(tree);
}

void AllianceApplicationListenMessage::deserializeAsyncAs_AllianceApplicationListenMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceApplicationListenMessage::_listenFunc, this, std::placeholders::_1));
}

void AllianceApplicationListenMessage::_listenFunc(Reader *input)
{
  this->listen = input->readBool();
}

AllianceApplicationListenMessage::AllianceApplicationListenMessage()
{
  m_type = MessageEnum::ALLIANCEAPPLICATIONLISTENMESSAGE;
}

