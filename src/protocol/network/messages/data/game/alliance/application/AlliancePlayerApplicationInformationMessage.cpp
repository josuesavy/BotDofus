#include "AlliancePlayerApplicationInformationMessage.h"

void AlliancePlayerApplicationInformationMessage::serialize(Writer *output)
{
  this->serializeAs_AlliancePlayerApplicationInformationMessage(output);
}

void AlliancePlayerApplicationInformationMessage::serializeAs_AlliancePlayerApplicationInformationMessage(Writer *output)
{
  AlliancePlayerApplicationAbstractMessage::serializeAs_AlliancePlayerApplicationAbstractMessage(output);
  this->allianceInformation->serializeAs_AllianceInformation(output);
  this->apply->serializeAs_SocialApplicationInformation(output);
}

void AlliancePlayerApplicationInformationMessage::deserialize(Reader *input)
{
  this->deserializeAs_AlliancePlayerApplicationInformationMessage(input);
}

void AlliancePlayerApplicationInformationMessage::deserializeAs_AlliancePlayerApplicationInformationMessage(Reader *input)
{
  AlliancePlayerApplicationAbstractMessage::deserialize(input);
  this->allianceInformation = QSharedPointer<AllianceInformation>(new AllianceInformation() );
  this->allianceInformation->deserialize(input);
  this->apply = QSharedPointer<SocialApplicationInformation>(new SocialApplicationInformation() );
  this->apply->deserialize(input);
}

void AlliancePlayerApplicationInformationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AlliancePlayerApplicationInformationMessage(tree);
}

void AlliancePlayerApplicationInformationMessage::deserializeAsyncAs_AlliancePlayerApplicationInformationMessage(FuncTree tree)
{
  AlliancePlayerApplicationAbstractMessage::deserializeAsync(tree);
  this->_allianceInformationtree = tree.addChild(std::bind(&AlliancePlayerApplicationInformationMessage::_allianceInformationtreeFunc, this, std::placeholders::_1));
  this->_applytree = tree.addChild(std::bind(&AlliancePlayerApplicationInformationMessage::_applytreeFunc, this, std::placeholders::_1));
}

void AlliancePlayerApplicationInformationMessage::_allianceInformationtreeFunc(Reader *input)
{
  this->allianceInformation = QSharedPointer<AllianceInformation>(new AllianceInformation() );
  this->allianceInformation->deserializeAsync(this->_allianceInformationtree);
}

void AlliancePlayerApplicationInformationMessage::_applytreeFunc(Reader *input)
{
  this->apply = QSharedPointer<SocialApplicationInformation>(new SocialApplicationInformation() );
  this->apply->deserializeAsync(this->_applytree);
}

AlliancePlayerApplicationInformationMessage::AlliancePlayerApplicationInformationMessage()
{
  m_type = MessageEnum::ALLIANCEPLAYERAPPLICATIONINFORMATIONMESSAGE;
}

