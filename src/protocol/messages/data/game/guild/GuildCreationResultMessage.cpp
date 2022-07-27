#include "GuildCreationResultMessage.h"

void GuildCreationResultMessage::serialize(Writer *output)
{
  this->serializeAs_GuildCreationResultMessage(output);
}

void GuildCreationResultMessage::serializeAs_GuildCreationResultMessage(Writer *output)
{
  output->writeByte(this->result);
}

void GuildCreationResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildCreationResultMessage(input);
}

void GuildCreationResultMessage::deserializeAs_GuildCreationResultMessage(Reader *input)
{
  this->_resultFunc(input);
}

void GuildCreationResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildCreationResultMessage(tree);
}

void GuildCreationResultMessage::deserializeAsyncAs_GuildCreationResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildCreationResultMessage::_resultFunc, this, std::placeholders::_1));
}

void GuildCreationResultMessage::_resultFunc(Reader *input)
{
  this->result = input->readByte();
  if(this->result < 0)
  {
    qDebug()<<"ERREUR - GuildCreationResultMessage -"<<"Forbidden value (" << this->result << ") on element of GuildCreationResultMessage.result.";
  }
}

GuildCreationResultMessage::GuildCreationResultMessage()
{
  m_type = MessageEnum::GUILDCREATIONRESULTMESSAGE;
}

