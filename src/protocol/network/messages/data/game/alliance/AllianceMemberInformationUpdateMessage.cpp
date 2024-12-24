#include "AllianceMemberInformationUpdateMessage.h"

void AllianceMemberInformationUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceMemberInformationUpdateMessage(output);
}

void AllianceMemberInformationUpdateMessage::serializeAs_AllianceMemberInformationUpdateMessage(Writer *output)
{
  this->member->serializeAs_AllianceMemberInfo(output);
}

void AllianceMemberInformationUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceMemberInformationUpdateMessage(input);
}

void AllianceMemberInformationUpdateMessage::deserializeAs_AllianceMemberInformationUpdateMessage(Reader *input)
{
  this->member = QSharedPointer<AllianceMemberInfo>(new AllianceMemberInfo() );
  this->member->deserialize(input);
}

void AllianceMemberInformationUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceMemberInformationUpdateMessage(tree);
}

void AllianceMemberInformationUpdateMessage::deserializeAsyncAs_AllianceMemberInformationUpdateMessage(FuncTree tree)
{
  this->_membertree = tree.addChild(std::bind(&AllianceMemberInformationUpdateMessage::_membertreeFunc, this, std::placeholders::_1));
}

void AllianceMemberInformationUpdateMessage::_membertreeFunc(Reader *input)
{
  this->member = QSharedPointer<AllianceMemberInfo>(new AllianceMemberInfo() );
  this->member->deserializeAsync(this->_membertree);
}

AllianceMemberInformationUpdateMessage::AllianceMemberInformationUpdateMessage()
{
  m_type = MessageEnum::ALLIANCEMEMBERINFORMATIONUPDATEMESSAGE;
}

