#include "MountSetXpRatioRequestMessage.h"

void MountSetXpRatioRequestMessage::serialize(Writer *output)
{
  this->serializeAs_MountSetXpRatioRequestMessage(output);
}

void MountSetXpRatioRequestMessage::serializeAs_MountSetXpRatioRequestMessage(Writer *output)
{
  if(this->xpRatio < 0)
  {
    qDebug()<<"ERREUR - MountSetXpRatioRequestMessage -"<<"Forbidden value (" << this->xpRatio << ") on element xpRatio.";
  }
  output->writeByte(this->xpRatio);
}

void MountSetXpRatioRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_MountSetXpRatioRequestMessage(input);
}

void MountSetXpRatioRequestMessage::deserializeAs_MountSetXpRatioRequestMessage(Reader *input)
{
  this->_xpRatioFunc(input);
}

void MountSetXpRatioRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MountSetXpRatioRequestMessage(tree);
}

void MountSetXpRatioRequestMessage::deserializeAsyncAs_MountSetXpRatioRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MountSetXpRatioRequestMessage::_xpRatioFunc, this, std::placeholders::_1));
}

void MountSetXpRatioRequestMessage::_xpRatioFunc(Reader *input)
{
  this->xpRatio = input->readByte();
  if(this->xpRatio < 0)
  {
    qDebug()<<"ERREUR - MountSetXpRatioRequestMessage -"<<"Forbidden value (" << this->xpRatio << ") on element of MountSetXpRatioRequestMessage.xpRatio.";
  }
}

MountSetXpRatioRequestMessage::MountSetXpRatioRequestMessage()
{
  m_type = MessageEnum::MOUNTSETXPRATIOREQUESTMESSAGE;
}

