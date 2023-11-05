#include "NicknameChoiceRequestMessage.h"

void NicknameChoiceRequestMessage::serialize(Writer *output)
{
  this->serializeAs_NicknameChoiceRequestMessage(output);
}

void NicknameChoiceRequestMessage::serializeAs_NicknameChoiceRequestMessage(Writer *output)
{
  output->writeUTF(this->nickname);
}

void NicknameChoiceRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_NicknameChoiceRequestMessage(input);
}

void NicknameChoiceRequestMessage::deserializeAs_NicknameChoiceRequestMessage(Reader *input)
{
  this->_nicknameFunc(input);
}

void NicknameChoiceRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_NicknameChoiceRequestMessage(tree);
}

void NicknameChoiceRequestMessage::deserializeAsyncAs_NicknameChoiceRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&NicknameChoiceRequestMessage::_nicknameFunc, this, std::placeholders::_1));
}

void NicknameChoiceRequestMessage::_nicknameFunc(Reader *input)
{
  this->nickname = input->readUTF();
}

NicknameChoiceRequestMessage::NicknameChoiceRequestMessage()
{
  m_type = MessageEnum::NICKNAMECHOICEREQUESTMESSAGE;
}

