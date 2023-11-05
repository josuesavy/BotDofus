#include "AllianceApplicationIsAnsweredMessage.h"

void AllianceApplicationIsAnsweredMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceApplicationIsAnsweredMessage(output);
}

void AllianceApplicationIsAnsweredMessage::serializeAs_AllianceApplicationIsAnsweredMessage(Writer *output)
{
  output->writeBool(this->accepted);
  this->allianceInformation->serializeAs_AllianceInformation(output);
}

void AllianceApplicationIsAnsweredMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceApplicationIsAnsweredMessage(input);
}

void AllianceApplicationIsAnsweredMessage::deserializeAs_AllianceApplicationIsAnsweredMessage(Reader *input)
{
  this->_acceptedFunc(input);
  this->allianceInformation = QSharedPointer<AllianceInformation>(new AllianceInformation() );
  this->allianceInformation->deserialize(input);
}

void AllianceApplicationIsAnsweredMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceApplicationIsAnsweredMessage(tree);
}

void AllianceApplicationIsAnsweredMessage::deserializeAsyncAs_AllianceApplicationIsAnsweredMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceApplicationIsAnsweredMessage::_acceptedFunc, this, std::placeholders::_1));
  this->_allianceInformationtree = tree.addChild(std::bind(&AllianceApplicationIsAnsweredMessage::_allianceInformationtreeFunc, this, std::placeholders::_1));
}

void AllianceApplicationIsAnsweredMessage::_acceptedFunc(Reader *input)
{
  this->accepted = input->readBool();
}

void AllianceApplicationIsAnsweredMessage::_allianceInformationtreeFunc(Reader *input)
{
  this->allianceInformation = QSharedPointer<AllianceInformation>(new AllianceInformation() );
  this->allianceInformation->deserializeAsync(this->_allianceInformationtree);
}

AllianceApplicationIsAnsweredMessage::AllianceApplicationIsAnsweredMessage()
{
  m_type = MessageEnum::ALLIANCEAPPLICATIONISANSWEREDMESSAGE;
}

