#include "AllianceJoinAutomaticallyRequestMessage.h"

void AllianceJoinAutomaticallyRequestMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceJoinAutomaticallyRequestMessage(output);
}

void AllianceJoinAutomaticallyRequestMessage::serializeAs_AllianceJoinAutomaticallyRequestMessage(Writer *output)
{
  output->writeInt((int)this->allianceId);
}

void AllianceJoinAutomaticallyRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceJoinAutomaticallyRequestMessage(input);
}

void AllianceJoinAutomaticallyRequestMessage::deserializeAs_AllianceJoinAutomaticallyRequestMessage(Reader *input)
{
  this->_allianceIdFunc(input);
}

void AllianceJoinAutomaticallyRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceJoinAutomaticallyRequestMessage(tree);
}

void AllianceJoinAutomaticallyRequestMessage::deserializeAsyncAs_AllianceJoinAutomaticallyRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceJoinAutomaticallyRequestMessage::_allianceIdFunc, this, std::placeholders::_1));
}

void AllianceJoinAutomaticallyRequestMessage::_allianceIdFunc(Reader *input)
{
  this->allianceId = input->readInt();
}

AllianceJoinAutomaticallyRequestMessage::AllianceJoinAutomaticallyRequestMessage()
{
  m_type = MessageEnum::ALLIANCEJOINAUTOMATICALLYREQUESTMESSAGE;
}

