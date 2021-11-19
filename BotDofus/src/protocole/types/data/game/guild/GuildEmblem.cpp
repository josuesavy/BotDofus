#include "GuildEmblem.h"

void GuildEmblem::serialize(Writer *output)
{
  this->serializeAs_GuildEmblem(output);
}

void GuildEmblem::serializeAs_GuildEmblem(Writer *output)
{
  if(this->symbolShape < 0)
  {
    qDebug()<<"ERREUR - GuildEmblem -"<<"Forbidden value (" << this->symbolShape << ") on element symbolShape.";
  }
  output->writeVarShort((int)this->symbolShape);
  output->writeInt((int)this->symbolColor);
  if(this->backgroundShape < 0)
  {
    qDebug()<<"ERREUR - GuildEmblem -"<<"Forbidden value (" << this->backgroundShape << ") on element backgroundShape.";
  }
  output->writeByte(this->backgroundShape);
  output->writeInt((int)this->backgroundColor);
}

void GuildEmblem::deserialize(Reader *input)
{
  this->deserializeAs_GuildEmblem(input);
}

void GuildEmblem::deserializeAs_GuildEmblem(Reader *input)
{
  this->_symbolShapeFunc(input);
  this->_symbolColorFunc(input);
  this->_backgroundShapeFunc(input);
  this->_backgroundColorFunc(input);
}

void GuildEmblem::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildEmblem(tree);
}

void GuildEmblem::deserializeAsyncAs_GuildEmblem(FuncTree tree)
{
  tree.addChild(std::bind(&GuildEmblem::_symbolShapeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildEmblem::_symbolColorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildEmblem::_backgroundShapeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildEmblem::_backgroundColorFunc, this, std::placeholders::_1));
}

void GuildEmblem::_symbolShapeFunc(Reader *input)
{
  this->symbolShape = input->readVarUhShort();
  if(this->symbolShape < 0)
  {
    qDebug()<<"ERREUR - GuildEmblem -"<<"Forbidden value (" << this->symbolShape << ") on element of GuildEmblem.symbolShape.";
  }
}

void GuildEmblem::_symbolColorFunc(Reader *input)
{
  this->symbolColor = input->readInt();
}

void GuildEmblem::_backgroundShapeFunc(Reader *input)
{
  this->backgroundShape = input->readByte();
  if(this->backgroundShape < 0)
  {
    qDebug()<<"ERREUR - GuildEmblem -"<<"Forbidden value (" << this->backgroundShape << ") on element of GuildEmblem.backgroundShape.";
  }
}

void GuildEmblem::_backgroundColorFunc(Reader *input)
{
  this->backgroundColor = input->readInt();
}

GuildEmblem::GuildEmblem()
{
  m_types<<ClassEnum::GUILDEMBLEM;
}

bool GuildEmblem::operator==(const GuildEmblem &compared)
{
  if(symbolShape == compared.symbolShape)
  if(symbolColor == compared.symbolColor)
  if(backgroundShape == compared.backgroundShape)
  if(backgroundColor == compared.backgroundColor)
  return true;
  
  return false;
}

