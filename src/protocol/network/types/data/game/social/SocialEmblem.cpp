#include "SocialEmblem.h"

void SocialEmblem::serialize(Writer *output)
{
  this->serializeAs_SocialEmblem(output);
}

void SocialEmblem::serializeAs_SocialEmblem(Writer *output)
{
  if(this->symbolShape < 0)
  {
    qDebug()<<"ERREUR - SocialEmblem -"<<"Forbidden value (" << this->symbolShape << ") on element symbolShape.";
  }
  output->writeVarShort((int)this->symbolShape);
  output->writeInt((int)this->symbolColor);
  if(this->backgroundShape < 0)
  {
    qDebug()<<"ERREUR - SocialEmblem -"<<"Forbidden value (" << this->backgroundShape << ") on element backgroundShape.";
  }
  output->writeByte(this->backgroundShape);
  output->writeInt((int)this->backgroundColor);
}

void SocialEmblem::deserialize(Reader *input)
{
  this->deserializeAs_SocialEmblem(input);
}

void SocialEmblem::deserializeAs_SocialEmblem(Reader *input)
{
  this->_symbolShapeFunc(input);
  this->_symbolColorFunc(input);
  this->_backgroundShapeFunc(input);
  this->_backgroundColorFunc(input);
}

void SocialEmblem::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SocialEmblem(tree);
}

void SocialEmblem::deserializeAsyncAs_SocialEmblem(FuncTree tree)
{
  tree.addChild(std::bind(&SocialEmblem::_symbolShapeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialEmblem::_symbolColorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialEmblem::_backgroundShapeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialEmblem::_backgroundColorFunc, this, std::placeholders::_1));
}

void SocialEmblem::_symbolShapeFunc(Reader *input)
{
  this->symbolShape = input->readVarUhShort();
  if(this->symbolShape < 0)
  {
    qDebug()<<"ERREUR - SocialEmblem -"<<"Forbidden value (" << this->symbolShape << ") on element of SocialEmblem.symbolShape.";
  }
}

void SocialEmblem::_symbolColorFunc(Reader *input)
{
  this->symbolColor = input->readInt();
}

void SocialEmblem::_backgroundShapeFunc(Reader *input)
{
  this->backgroundShape = input->readByte();
  if(this->backgroundShape < 0)
  {
    qDebug()<<"ERREUR - SocialEmblem -"<<"Forbidden value (" << this->backgroundShape << ") on element of SocialEmblem.backgroundShape.";
  }
}

void SocialEmblem::_backgroundColorFunc(Reader *input)
{
  this->backgroundColor = input->readInt();
}

SocialEmblem::SocialEmblem()
{
  m_types<<ClassEnum::SOCIALEMBLEM;
}

bool SocialEmblem::operator==(const SocialEmblem &compared)
{
  if(symbolShape == compared.symbolShape)
  if(symbolColor == compared.symbolColor)
  if(backgroundShape == compared.backgroundShape)
  if(backgroundColor == compared.backgroundColor)
  return true;
  
  return false;
}

