#include "MountXpRatioMessage.h"

void MountXpRatioMessage::serialize(Writer *output)
{
  this->serializeAs_MountXpRatioMessage(output);
}

void MountXpRatioMessage::serializeAs_MountXpRatioMessage(Writer *output)
{
  if(this->ratio < 0)
  {
    qDebug()<<"ERREUR - MountXpRatioMessage -"<<"Forbidden value (" << this->ratio << ") on element ratio.";
  }
  output->writeByte(this->ratio);
}

void MountXpRatioMessage::deserialize(Reader *input)
{
  this->deserializeAs_MountXpRatioMessage(input);
}

void MountXpRatioMessage::deserializeAs_MountXpRatioMessage(Reader *input)
{
  this->_ratioFunc(input);
}

void MountXpRatioMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MountXpRatioMessage(tree);
}

void MountXpRatioMessage::deserializeAsyncAs_MountXpRatioMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MountXpRatioMessage::_ratioFunc, this, std::placeholders::_1));
}

void MountXpRatioMessage::_ratioFunc(Reader *input)
{
  this->ratio = input->readByte();
  if(this->ratio < 0)
  {
    qDebug()<<"ERREUR - MountXpRatioMessage -"<<"Forbidden value (" << this->ratio << ") on element of MountXpRatioMessage.ratio.";
  }
}

MountXpRatioMessage::MountXpRatioMessage()
{
  m_type = MessageEnum::MOUNTXPRATIOMESSAGE;
}

