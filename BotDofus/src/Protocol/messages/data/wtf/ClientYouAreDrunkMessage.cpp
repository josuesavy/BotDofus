#include "ClientYouAreDrunkMessage.h"

void ClientYouAreDrunkMessage::serialize(Writer *output)
{
  this->serializeAs_ClientYouAreDrunkMessage(output);
}

void ClientYouAreDrunkMessage::serializeAs_ClientYouAreDrunkMessage(Writer *output)
{
  DebugInClientMessage::serializeAs_DebugInClientMessage(output);
}

void ClientYouAreDrunkMessage::deserialize(Reader *input)
{
  this->deserializeAs_ClientYouAreDrunkMessage(input);
}

void ClientYouAreDrunkMessage::deserializeAs_ClientYouAreDrunkMessage(Reader *input)
{
  DebugInClientMessage::deserialize(input);
}

void ClientYouAreDrunkMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ClientYouAreDrunkMessage(tree);
}

void ClientYouAreDrunkMessage::deserializeAsyncAs_ClientYouAreDrunkMessage(FuncTree tree)
{
  DebugInClientMessage::deserializeAsync(tree);
}

ClientYouAreDrunkMessage::ClientYouAreDrunkMessage()
{
  m_type = MessageEnum::CLIENTYOUAREDRUNKMESSAGE;
}

