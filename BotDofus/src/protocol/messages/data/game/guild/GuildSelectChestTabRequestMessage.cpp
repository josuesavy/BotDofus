#include "GuildSelectChestTabRequestMessage.h"

void GuildSelectChestTabRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GuildSelectChestTabRequestMessage(output);
}

void GuildSelectChestTabRequestMessage::serializeAs_GuildSelectChestTabRequestMessage(Writer *output)
{
  if(this->tabNumber < 0)
  {
    qDebug()<<"ERREUR - GuildSelectChestTabRequestMessage -"<<"Forbidden value (" << this->tabNumber << ") on element tabNumber.";
  }
  output->writeVarInt((int)this->tabNumber);
}

void GuildSelectChestTabRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildSelectChestTabRequestMessage(input);
}

void GuildSelectChestTabRequestMessage::deserializeAs_GuildSelectChestTabRequestMessage(Reader *input)
{
  this->_tabNumberFunc(input);
}

void GuildSelectChestTabRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildSelectChestTabRequestMessage(tree);
}

void GuildSelectChestTabRequestMessage::deserializeAsyncAs_GuildSelectChestTabRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildSelectChestTabRequestMessage::_tabNumberFunc, this, std::placeholders::_1));
}

void GuildSelectChestTabRequestMessage::_tabNumberFunc(Reader *input)
{
  this->tabNumber = input->readVarUhInt();
  if(this->tabNumber < 0)
  {
    qDebug()<<"ERREUR - GuildSelectChestTabRequestMessage -"<<"Forbidden value (" << this->tabNumber << ") on element of GuildSelectChestTabRequestMessage.tabNumber.";
  }
}

GuildSelectChestTabRequestMessage::GuildSelectChestTabRequestMessage()
{
  m_type = MessageEnum::GUILDSELECTCHESTTABREQUESTMESSAGE;
}

