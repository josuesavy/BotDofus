#include "AllianceCreationValidMessage.h"

void AllianceCreationValidMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceCreationValidMessage(output);
}

void AllianceCreationValidMessage::serializeAs_AllianceCreationValidMessage(Writer *output)
{
  output->writeUTF(this->allianceName);
  output->writeUTF(this->allianceTag);
  this->allianceEmblem.serializeAs_GuildEmblem(output);
}

void AllianceCreationValidMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceCreationValidMessage(input);
}

void AllianceCreationValidMessage::deserializeAs_AllianceCreationValidMessage(Reader *input)
{
  this->_allianceNameFunc(input);
  this->_allianceTagFunc(input);
  this->allianceEmblem = GuildEmblem();
  this->allianceEmblem.deserialize(input);
}

void AllianceCreationValidMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceCreationValidMessage(tree);
}

void AllianceCreationValidMessage::deserializeAsyncAs_AllianceCreationValidMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceCreationValidMessage::_allianceNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceCreationValidMessage::_allianceTagFunc, this, std::placeholders::_1));
  this->_allianceEmblemtree = tree.addChild(std::bind(&AllianceCreationValidMessage::_allianceEmblemtreeFunc, this, std::placeholders::_1));
}

void AllianceCreationValidMessage::_allianceNameFunc(Reader *input)
{
  this->allianceName = input->readUTF();
}

void AllianceCreationValidMessage::_allianceTagFunc(Reader *input)
{
  this->allianceTag = input->readUTF();
}

void AllianceCreationValidMessage::_allianceEmblemtreeFunc(Reader *input)
{
  this->allianceEmblem = GuildEmblem();
  this->allianceEmblem.deserializeAsync(this->_allianceEmblemtree);
}

AllianceCreationValidMessage::AllianceCreationValidMessage()
{
  m_type = MessageEnum::ALLIANCECREATIONVALIDMESSAGE;
}

