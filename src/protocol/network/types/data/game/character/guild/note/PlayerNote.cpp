#include "PlayerNote.h"

void PlayerNote::serialize(Writer *output)
{
  this->serializeAs_PlayerNote(output);
}

void PlayerNote::serializeAs_PlayerNote(Writer *output)
{
  output->writeUTF(this->content);
  if(this->lastEditDate < -9007199254740992 || this->lastEditDate > 9007199254740992)
  {
    qDebug()<<"ERREUR - PlayerNote -"<<"Forbidden value (" << this->lastEditDate << ") on element lastEditDate.";
  }
  output->writeDouble(this->lastEditDate);
}

void PlayerNote::deserialize(Reader *input)
{
  this->deserializeAs_PlayerNote(input);
}

void PlayerNote::deserializeAs_PlayerNote(Reader *input)
{
  this->_contentFunc(input);
  this->_lastEditDateFunc(input);
}

void PlayerNote::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PlayerNote(tree);
}

void PlayerNote::deserializeAsyncAs_PlayerNote(FuncTree tree)
{
  tree.addChild(std::bind(&PlayerNote::_contentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PlayerNote::_lastEditDateFunc, this, std::placeholders::_1));
}

void PlayerNote::_contentFunc(Reader *input)
{
  this->content = input->readUTF();
}

void PlayerNote::_lastEditDateFunc(Reader *input)
{
  this->lastEditDate = input->readDouble();
  if(this->lastEditDate < -9007199254740992 || this->lastEditDate > 9007199254740992)
  {
    qDebug()<<"ERREUR - PlayerNote -"<<"Forbidden value (" << this->lastEditDate << ") on element of PlayerNote.lastEditDate.";
  }
}

PlayerNote::PlayerNote()
{
  m_types<<ClassEnum::PLAYERNOTE;
}

bool PlayerNote::operator==(const PlayerNote &compared)
{
  if(content == compared.content)
  if(lastEditDate == compared.lastEditDate)
  return true;
  
  return false;
}

