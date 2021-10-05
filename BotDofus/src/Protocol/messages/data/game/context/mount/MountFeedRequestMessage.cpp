#include "MountFeedRequestMessage.h"

void MountFeedRequestMessage::serialize(Writer *output)
{
  this->serializeAs_MountFeedRequestMessage(output);
}

void MountFeedRequestMessage::serializeAs_MountFeedRequestMessage(Writer *output)
{
  if(this->mountUid < 0)
  {
    qDebug()<<"ERREUR - MountFeedRequestMessage -"<<"Forbidden value (" << this->mountUid << ") on element mountUid.";
  }
  output->writeVarInt((int)this->mountUid);
  output->writeByte(this->mountLocation);
  if(this->mountFoodUid < 0)
  {
    qDebug()<<"ERREUR - MountFeedRequestMessage -"<<"Forbidden value (" << this->mountFoodUid << ") on element mountFoodUid.";
  }
  output->writeVarInt((int)this->mountFoodUid);
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - MountFeedRequestMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  output->writeVarInt((int)this->quantity);
}

void MountFeedRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_MountFeedRequestMessage(input);
}

void MountFeedRequestMessage::deserializeAs_MountFeedRequestMessage(Reader *input)
{
  this->_mountUidFunc(input);
  this->_mountLocationFunc(input);
  this->_mountFoodUidFunc(input);
  this->_quantityFunc(input);
}

void MountFeedRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MountFeedRequestMessage(tree);
}

void MountFeedRequestMessage::deserializeAsyncAs_MountFeedRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MountFeedRequestMessage::_mountUidFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountFeedRequestMessage::_mountLocationFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountFeedRequestMessage::_mountFoodUidFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountFeedRequestMessage::_quantityFunc, this, std::placeholders::_1));
}

void MountFeedRequestMessage::_mountUidFunc(Reader *input)
{
  this->mountUid = input->readVarUhInt();
  if(this->mountUid < 0)
  {
    qDebug()<<"ERREUR - MountFeedRequestMessage -"<<"Forbidden value (" << this->mountUid << ") on element of MountFeedRequestMessage.mountUid.";
  }
}

void MountFeedRequestMessage::_mountLocationFunc(Reader *input)
{
  this->mountLocation = input->readByte();
}

void MountFeedRequestMessage::_mountFoodUidFunc(Reader *input)
{
  this->mountFoodUid = input->readVarUhInt();
  if(this->mountFoodUid < 0)
  {
    qDebug()<<"ERREUR - MountFeedRequestMessage -"<<"Forbidden value (" << this->mountFoodUid << ") on element of MountFeedRequestMessage.mountFoodUid.";
  }
}

void MountFeedRequestMessage::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarUhInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - MountFeedRequestMessage -"<<"Forbidden value (" << this->quantity << ") on element of MountFeedRequestMessage.quantity.";
  }
}

MountFeedRequestMessage::MountFeedRequestMessage()
{
  m_type = MessageEnum::MOUNTFEEDREQUESTMESSAGE;
}

