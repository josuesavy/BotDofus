#include "AllianceMotdSetRequestMessage.h"

void AllianceMotdSetRequestMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceMotdSetRequestMessage(output);
}

void AllianceMotdSetRequestMessage::serializeAs_AllianceMotdSetRequestMessage(Writer *output)
{
  SocialNoticeSetRequestMessage::serializeAs_SocialNoticeSetRequestMessage(output);
  output->writeUTF(this->content);
}

void AllianceMotdSetRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceMotdSetRequestMessage(input);
}

void AllianceMotdSetRequestMessage::deserializeAs_AllianceMotdSetRequestMessage(Reader *input)
{
  SocialNoticeSetRequestMessage::deserialize(input);
  this->_contentFunc(input);
}

void AllianceMotdSetRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceMotdSetRequestMessage(tree);
}

void AllianceMotdSetRequestMessage::deserializeAsyncAs_AllianceMotdSetRequestMessage(FuncTree tree)
{
  SocialNoticeSetRequestMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&AllianceMotdSetRequestMessage::_contentFunc, this, std::placeholders::_1));
}

void AllianceMotdSetRequestMessage::_contentFunc(Reader *input)
{
  this->content = input->readUTF();
}

AllianceMotdSetRequestMessage::AllianceMotdSetRequestMessage()
{
  m_type = MessageEnum::ALLIANCEMOTDSETREQUESTMESSAGE;
}

