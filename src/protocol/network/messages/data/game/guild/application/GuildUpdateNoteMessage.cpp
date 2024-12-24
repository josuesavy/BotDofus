#include "GuildUpdateNoteMessage.h"

void GuildUpdateNoteMessage::serialize(Writer *output)
{
  this->serializeAs_GuildUpdateNoteMessage(output);
}

void GuildUpdateNoteMessage::serializeAs_GuildUpdateNoteMessage(Writer *output)
{
  if(this->memberId < 0 || this->memberId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildUpdateNoteMessage -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  output->writeVarLong((double)this->memberId);
  output->writeUTF(this->note);
}

void GuildUpdateNoteMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildUpdateNoteMessage(input);
}

void GuildUpdateNoteMessage::deserializeAs_GuildUpdateNoteMessage(Reader *input)
{
  this->_memberIdFunc(input);
  this->_noteFunc(input);
}

void GuildUpdateNoteMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildUpdateNoteMessage(tree);
}

void GuildUpdateNoteMessage::deserializeAsyncAs_GuildUpdateNoteMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildUpdateNoteMessage::_memberIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildUpdateNoteMessage::_noteFunc, this, std::placeholders::_1));
}

void GuildUpdateNoteMessage::_memberIdFunc(Reader *input)
{
  this->memberId = input->readVarUhLong();
  if(this->memberId < 0 || this->memberId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildUpdateNoteMessage -"<<"Forbidden value (" << this->memberId << ") on element of GuildUpdateNoteMessage.memberId.";
  }
}

void GuildUpdateNoteMessage::_noteFunc(Reader *input)
{
  this->note = input->readUTF();
}

GuildUpdateNoteMessage::GuildUpdateNoteMessage()
{
  m_type = MessageEnum::GUILDUPDATENOTEMESSAGE;
}

