#include "RecycleResultMessage.h"

void RecycleResultMessage::serialize(Writer *output)
{
  this->serializeAs_RecycleResultMessage(output);
}

void RecycleResultMessage::serializeAs_RecycleResultMessage(Writer *output)
{
  if(this->nuggetsForPrism < 0)
  {
    qDebug()<<"ERREUR - RecycleResultMessage -"<<"Forbidden value (" << this->nuggetsForPrism << ") on element nuggetsForPrism.";
  }
  output->writeVarInt((int)this->nuggetsForPrism);
  if(this->nuggetsForPlayer < 0)
  {
    qDebug()<<"ERREUR - RecycleResultMessage -"<<"Forbidden value (" << this->nuggetsForPlayer << ") on element nuggetsForPlayer.";
  }
  output->writeVarInt((int)this->nuggetsForPlayer);
}

void RecycleResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_RecycleResultMessage(input);
}

void RecycleResultMessage::deserializeAs_RecycleResultMessage(Reader *input)
{
  this->_nuggetsForPrismFunc(input);
  this->_nuggetsForPlayerFunc(input);
}

void RecycleResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_RecycleResultMessage(tree);
}

void RecycleResultMessage::deserializeAsyncAs_RecycleResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&RecycleResultMessage::_nuggetsForPrismFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&RecycleResultMessage::_nuggetsForPlayerFunc, this, std::placeholders::_1));
}

void RecycleResultMessage::_nuggetsForPrismFunc(Reader *input)
{
  this->nuggetsForPrism = input->readVarUhInt();
  if(this->nuggetsForPrism < 0)
  {
    qDebug()<<"ERREUR - RecycleResultMessage -"<<"Forbidden value (" << this->nuggetsForPrism << ") on element of RecycleResultMessage.nuggetsForPrism.";
  }
}

void RecycleResultMessage::_nuggetsForPlayerFunc(Reader *input)
{
  this->nuggetsForPlayer = input->readVarUhInt();
  if(this->nuggetsForPlayer < 0)
  {
    qDebug()<<"ERREUR - RecycleResultMessage -"<<"Forbidden value (" << this->nuggetsForPlayer << ") on element of RecycleResultMessage.nuggetsForPlayer.";
  }
}

RecycleResultMessage::RecycleResultMessage()
{
  m_type = MessageEnum::RECYCLERESULTMESSAGE;
}

