#include "MountInformationInPaddockRequestMessage.h"

void MountInformationInPaddockRequestMessage::serialize(Writer *output)
{
  this->serializeAs_MountInformationInPaddockRequestMessage(output);
}

void MountInformationInPaddockRequestMessage::serializeAs_MountInformationInPaddockRequestMessage(Writer *output)
{
  output->writeVarInt((int)this->mapRideId);
}

void MountInformationInPaddockRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_MountInformationInPaddockRequestMessage(input);
}

void MountInformationInPaddockRequestMessage::deserializeAs_MountInformationInPaddockRequestMessage(Reader *input)
{
  this->_mapRideIdFunc(input);
}

void MountInformationInPaddockRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MountInformationInPaddockRequestMessage(tree);
}

void MountInformationInPaddockRequestMessage::deserializeAsyncAs_MountInformationInPaddockRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MountInformationInPaddockRequestMessage::_mapRideIdFunc, this, std::placeholders::_1));
}

void MountInformationInPaddockRequestMessage::_mapRideIdFunc(Reader *input)
{
  this->mapRideId = input->readVarInt();
}

MountInformationInPaddockRequestMessage::MountInformationInPaddockRequestMessage()
{
  m_type = MessageEnum::MOUNTINFORMATIONINPADDOCKREQUESTMESSAGE;
}

