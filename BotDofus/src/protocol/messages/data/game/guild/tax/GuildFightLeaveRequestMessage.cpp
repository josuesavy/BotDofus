#include "GuildFightLeaveRequestMessage.h"

void GuildFightLeaveRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GuildFightLeaveRequestMessage(output);
}

void GuildFightLeaveRequestMessage::serializeAs_GuildFightLeaveRequestMessage(Writer *output)
{
  if(this->taxCollectorId < 0 || this->taxCollectorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightLeaveRequestMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element taxCollectorId.";
  }
  output->writeDouble(this->taxCollectorId);
  if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightLeaveRequestMessage -"<<"Forbidden value (" << this->characterId << ") on element characterId.";
  }
  output->writeVarLong((double)this->characterId);
}

void GuildFightLeaveRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildFightLeaveRequestMessage(input);
}

void GuildFightLeaveRequestMessage::deserializeAs_GuildFightLeaveRequestMessage(Reader *input)
{
  this->_taxCollectorIdFunc(input);
  this->_characterIdFunc(input);
}

void GuildFightLeaveRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildFightLeaveRequestMessage(tree);
}

void GuildFightLeaveRequestMessage::deserializeAsyncAs_GuildFightLeaveRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildFightLeaveRequestMessage::_taxCollectorIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildFightLeaveRequestMessage::_characterIdFunc, this, std::placeholders::_1));
}

void GuildFightLeaveRequestMessage::_taxCollectorIdFunc(Reader *input)
{
  this->taxCollectorId = input->readDouble();
  if(this->taxCollectorId < 0 || this->taxCollectorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightLeaveRequestMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element of GuildFightLeaveRequestMessage.taxCollectorId.";
  }
}

void GuildFightLeaveRequestMessage::_characterIdFunc(Reader *input)
{
  this->characterId = input->readVarUhLong();
  if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightLeaveRequestMessage -"<<"Forbidden value (" << this->characterId << ") on element of GuildFightLeaveRequestMessage.characterId.";
  }
}

GuildFightLeaveRequestMessage::GuildFightLeaveRequestMessage()
{
  m_type = MessageEnum::GUILDFIGHTLEAVEREQUESTMESSAGE;
}

