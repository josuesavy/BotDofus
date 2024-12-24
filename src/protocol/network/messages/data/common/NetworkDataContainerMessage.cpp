#include "NetworkDataContainerMessage.h"

void NetworkDataContainerMessage::serialize(Writer *output)
{
  this->serializeAs_NetworkDataContainerMessage(output);
}

void NetworkDataContainerMessage::serializeAs_NetworkDataContainerMessage(Writer *output)
{
  output->writeBytes(this->content);
  qDebug()<<"ERREUR - NetworkDataContainerMessage -"<<"Not implemented";
}

void NetworkDataContainerMessage::deserialize(Reader *input)
{
  this->deserializeAs_NetworkDataContainerMessage(input);
}

void NetworkDataContainerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_RawDataMessage(tree);
}

void NetworkDataContainerMessage::deserializeAs_NetworkDataContainerMessage(Reader *input)
{
  uint _contentLen = uint(input->readVarInt());
  QByteArray tmpBuffer = QByteArray();
  tmpBuffer = input->readBytes();
  tmpBuffer = gUncompress(tmpBuffer);
  this->content = tmpBuffer;
}

void NetworkDataContainerMessage::deserializeAsyncAs_RawDataMessage(FuncTree tree)
{
  tree.addChild(std::bind(&NetworkDataContainerMessage::deserializeAs_NetworkDataContainerMessage, this, std::placeholders::_1));
}

NetworkDataContainerMessage::NetworkDataContainerMessage()
{
  m_type = MessageEnum::NETWORKDATACONTAINERMESSAGE;
}

