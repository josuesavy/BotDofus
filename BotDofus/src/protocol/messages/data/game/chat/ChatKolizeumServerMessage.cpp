#include "ChatKolizeumServerMessage.h"

void ChatKolizeumServerMessage::serialize(Writer *output)
{
  this->serializeAs_ChatKolizeumServerMessage(output);
}

void ChatKolizeumServerMessage::serializeAs_ChatKolizeumServerMessage(Writer *output)
{
  ChatServerMessage::serializeAs_ChatServerMessage(output);
  output->writeShort((short)this->originServerId);
}

void ChatKolizeumServerMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChatKolizeumServerMessage(input);
}

void ChatKolizeumServerMessage::deserializeAs_ChatKolizeumServerMessage(Reader *input)
{
  ChatServerMessage::deserialize(input);
  this->_originServerIdFunc(input);
}

void ChatKolizeumServerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChatKolizeumServerMessage(tree);
}

void ChatKolizeumServerMessage::deserializeAsyncAs_ChatKolizeumServerMessage(FuncTree tree)
{
  ChatServerMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ChatKolizeumServerMessage::_originServerIdFunc, this, std::placeholders::_1));
}

void ChatKolizeumServerMessage::_originServerIdFunc(Reader *input)
{
  this->originServerId = input->readShort();
}

ChatKolizeumServerMessage::ChatKolizeumServerMessage()
{
  m_type = MessageEnum::CHATKOLIZEUMSERVERMESSAGE;
}

