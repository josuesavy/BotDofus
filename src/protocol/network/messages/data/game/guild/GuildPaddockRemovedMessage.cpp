#include "GuildPaddockRemovedMessage.h"

void GuildPaddockRemovedMessage::serialize(Writer *output)
{
  this->serializeAs_GuildPaddockRemovedMessage(output);
}

void GuildPaddockRemovedMessage::serializeAs_GuildPaddockRemovedMessage(Writer *output)
{
  if(this->paddockId < 0 || this->paddockId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildPaddockRemovedMessage -"<<"Forbidden value (" << this->paddockId << ") on element paddockId.";
  }
  output->writeDouble(this->paddockId);
}

void GuildPaddockRemovedMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildPaddockRemovedMessage(input);
}

void GuildPaddockRemovedMessage::deserializeAs_GuildPaddockRemovedMessage(Reader *input)
{
  this->_paddockIdFunc(input);
}

void GuildPaddockRemovedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildPaddockRemovedMessage(tree);
}

void GuildPaddockRemovedMessage::deserializeAsyncAs_GuildPaddockRemovedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildPaddockRemovedMessage::_paddockIdFunc, this, std::placeholders::_1));
}

void GuildPaddockRemovedMessage::_paddockIdFunc(Reader *input)
{
  this->paddockId = input->readDouble();
  if(this->paddockId < 0 || this->paddockId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildPaddockRemovedMessage -"<<"Forbidden value (" << this->paddockId << ") on element of GuildPaddockRemovedMessage.paddockId.";
  }
}

GuildPaddockRemovedMessage::GuildPaddockRemovedMessage()
{
  m_type = MessageEnum::GUILDPADDOCKREMOVEDMESSAGE;
}

