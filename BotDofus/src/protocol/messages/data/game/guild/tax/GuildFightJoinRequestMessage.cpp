#include "GuildFightJoinRequestMessage.h"

void GuildFightJoinRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GuildFightJoinRequestMessage(output);
}

void GuildFightJoinRequestMessage::serializeAs_GuildFightJoinRequestMessage(Writer *output)
{
  if(this->taxCollectorId < 0 || this->taxCollectorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightJoinRequestMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element taxCollectorId.";
  }
  output->writeDouble(this->taxCollectorId);
}

void GuildFightJoinRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildFightJoinRequestMessage(input);
}

void GuildFightJoinRequestMessage::deserializeAs_GuildFightJoinRequestMessage(Reader *input)
{
  this->_taxCollectorIdFunc(input);
}

void GuildFightJoinRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildFightJoinRequestMessage(tree);
}

void GuildFightJoinRequestMessage::deserializeAsyncAs_GuildFightJoinRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildFightJoinRequestMessage::_taxCollectorIdFunc, this, std::placeholders::_1));
}

void GuildFightJoinRequestMessage::_taxCollectorIdFunc(Reader *input)
{
  this->taxCollectorId = input->readDouble();
  if(this->taxCollectorId < 0 || this->taxCollectorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightJoinRequestMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element of GuildFightJoinRequestMessage.taxCollectorId.";
  }
}

GuildFightJoinRequestMessage::GuildFightJoinRequestMessage()
{
  m_type = MessageEnum::GUILDFIGHTJOINREQUESTMESSAGE;
}

