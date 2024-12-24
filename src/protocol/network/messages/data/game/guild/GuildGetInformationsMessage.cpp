#include "GuildGetInformationsMessage.h"

void GuildGetInformationsMessage::serialize(Writer *output)
{
  this->serializeAs_GuildGetInformationsMessage(output);
}

void GuildGetInformationsMessage::serializeAs_GuildGetInformationsMessage(Writer *output)
{
  output->writeByte(this->infoType);
}

void GuildGetInformationsMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildGetInformationsMessage(input);
}

void GuildGetInformationsMessage::deserializeAs_GuildGetInformationsMessage(Reader *input)
{
  this->_infoTypeFunc(input);
}

void GuildGetInformationsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildGetInformationsMessage(tree);
}

void GuildGetInformationsMessage::deserializeAsyncAs_GuildGetInformationsMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildGetInformationsMessage::_infoTypeFunc, this, std::placeholders::_1));
}

void GuildGetInformationsMessage::_infoTypeFunc(Reader *input)
{
  this->infoType = input->readByte();
  if(this->infoType < 0)
  {
    qDebug()<<"ERREUR - GuildGetInformationsMessage -"<<"Forbidden value (" << this->infoType << ") on element of GuildGetInformationsMessage.infoType.";
  }
}

GuildGetInformationsMessage::GuildGetInformationsMessage()
{
  m_type = MessageEnum::GUILDGETINFORMATIONSMESSAGE;
}

