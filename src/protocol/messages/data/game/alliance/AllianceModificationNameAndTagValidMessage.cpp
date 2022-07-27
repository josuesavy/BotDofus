#include "AllianceModificationNameAndTagValidMessage.h"

void AllianceModificationNameAndTagValidMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceModificationNameAndTagValidMessage(output);
}

void AllianceModificationNameAndTagValidMessage::serializeAs_AllianceModificationNameAndTagValidMessage(Writer *output)
{
  output->writeUTF(this->allianceName);
  output->writeUTF(this->allianceTag);
}

void AllianceModificationNameAndTagValidMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceModificationNameAndTagValidMessage(input);
}

void AllianceModificationNameAndTagValidMessage::deserializeAs_AllianceModificationNameAndTagValidMessage(Reader *input)
{
  this->_allianceNameFunc(input);
  this->_allianceTagFunc(input);
}

void AllianceModificationNameAndTagValidMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceModificationNameAndTagValidMessage(tree);
}

void AllianceModificationNameAndTagValidMessage::deserializeAsyncAs_AllianceModificationNameAndTagValidMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceModificationNameAndTagValidMessage::_allianceNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceModificationNameAndTagValidMessage::_allianceTagFunc, this, std::placeholders::_1));
}

void AllianceModificationNameAndTagValidMessage::_allianceNameFunc(Reader *input)
{
  this->allianceName = input->readUTF();
}

void AllianceModificationNameAndTagValidMessage::_allianceTagFunc(Reader *input)
{
  this->allianceTag = input->readUTF();
}

AllianceModificationNameAndTagValidMessage::AllianceModificationNameAndTagValidMessage()
{
  m_type = MessageEnum::ALLIANCEMODIFICATIONNAMEANDTAGVALIDMESSAGE;
}

