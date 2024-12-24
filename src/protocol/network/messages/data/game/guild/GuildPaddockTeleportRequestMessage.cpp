#include "GuildPaddockTeleportRequestMessage.h"

void GuildPaddockTeleportRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GuildPaddockTeleportRequestMessage(output);
}

void GuildPaddockTeleportRequestMessage::serializeAs_GuildPaddockTeleportRequestMessage(Writer *output)
{
  if(this->paddockId < 0 || this->paddockId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildPaddockTeleportRequestMessage -"<<"Forbidden value (" << this->paddockId << ") on element paddockId.";
  }
  output->writeDouble(this->paddockId);
}

void GuildPaddockTeleportRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildPaddockTeleportRequestMessage(input);
}

void GuildPaddockTeleportRequestMessage::deserializeAs_GuildPaddockTeleportRequestMessage(Reader *input)
{
  this->_paddockIdFunc(input);
}

void GuildPaddockTeleportRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildPaddockTeleportRequestMessage(tree);
}

void GuildPaddockTeleportRequestMessage::deserializeAsyncAs_GuildPaddockTeleportRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildPaddockTeleportRequestMessage::_paddockIdFunc, this, std::placeholders::_1));
}

void GuildPaddockTeleportRequestMessage::_paddockIdFunc(Reader *input)
{
  this->paddockId = input->readDouble();
  if(this->paddockId < 0 || this->paddockId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildPaddockTeleportRequestMessage -"<<"Forbidden value (" << this->paddockId << ") on element of GuildPaddockTeleportRequestMessage.paddockId.";
  }
}

GuildPaddockTeleportRequestMessage::GuildPaddockTeleportRequestMessage()
{
  m_type = MessageEnum::GUILDPADDOCKTELEPORTREQUESTMESSAGE;
}

