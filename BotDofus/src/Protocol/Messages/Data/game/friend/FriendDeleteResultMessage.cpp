#include "FriendDeleteResultMessage.h"

void FriendDeleteResultMessage::serialize(Writer *output)
{
  this->serializeAs_FriendDeleteResultMessage(output);
}

void FriendDeleteResultMessage::serializeAs_FriendDeleteResultMessage(Writer *output)
{
  output->writeBool(this->success);
  output->writeUTF(this->name);
}

void FriendDeleteResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendDeleteResultMessage(input);
}

void FriendDeleteResultMessage::deserializeAs_FriendDeleteResultMessage(Reader *input)
{
  this->_successFunc(input);
  this->_nameFunc(input);
}

void FriendDeleteResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendDeleteResultMessage(tree);
}

void FriendDeleteResultMessage::deserializeAsyncAs_FriendDeleteResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&FriendDeleteResultMessage::_successFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FriendDeleteResultMessage::_nameFunc, this, std::placeholders::_1));
}

void FriendDeleteResultMessage::_successFunc(Reader *input)
{
  this->success = input->readBool();
}

void FriendDeleteResultMessage::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

FriendDeleteResultMessage::FriendDeleteResultMessage()
{
  m_type = MessageEnum::FRIENDDELETERESULTMESSAGE;
}

