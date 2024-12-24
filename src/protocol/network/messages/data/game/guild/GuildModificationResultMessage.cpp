#include "GuildModificationResultMessage.h"

void GuildModificationResultMessage::serialize(Writer *output)
{
  this->serializeAs_GuildModificationResultMessage(output);
}

void GuildModificationResultMessage::serializeAs_GuildModificationResultMessage(Writer *output)
{
  output->writeByte(this->result);
}

void GuildModificationResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildModificationResultMessage(input);
}

void GuildModificationResultMessage::deserializeAs_GuildModificationResultMessage(Reader *input)
{
  this->_resultFunc(input);
}

void GuildModificationResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildModificationResultMessage(tree);
}

void GuildModificationResultMessage::deserializeAsyncAs_GuildModificationResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildModificationResultMessage::_resultFunc, this, std::placeholders::_1));
}

void GuildModificationResultMessage::_resultFunc(Reader *input)
{
  this->result = input->readByte();
  if(this->result < 0)
  {
    qDebug()<<"ERREUR - GuildModificationResultMessage -"<<"Forbidden value (" << this->result << ") on element of GuildModificationResultMessage.result.";
  }
}

GuildModificationResultMessage::GuildModificationResultMessage()
{
  m_type = MessageEnum::GUILDMODIFICATIONRESULTMESSAGE;
}

