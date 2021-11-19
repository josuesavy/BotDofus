#include "StorageKamasUpdateMessage.h"

void StorageKamasUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_StorageKamasUpdateMessage(output);
}

void StorageKamasUpdateMessage::serializeAs_StorageKamasUpdateMessage(Writer *output)
{
  if(this->kamasTotal < 0 || this->kamasTotal > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - StorageKamasUpdateMessage -"<<"Forbidden value (" << this->kamasTotal << ") on element kamasTotal.";
  }
  output->writeVarLong((double)this->kamasTotal);
}

void StorageKamasUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_StorageKamasUpdateMessage(input);
}

void StorageKamasUpdateMessage::deserializeAs_StorageKamasUpdateMessage(Reader *input)
{
  this->_kamasTotalFunc(input);
}

void StorageKamasUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StorageKamasUpdateMessage(tree);
}

void StorageKamasUpdateMessage::deserializeAsyncAs_StorageKamasUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&StorageKamasUpdateMessage::_kamasTotalFunc, this, std::placeholders::_1));
}

void StorageKamasUpdateMessage::_kamasTotalFunc(Reader *input)
{
  this->kamasTotal = input->readVarUhLong();
  if(this->kamasTotal < 0 || this->kamasTotal > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - StorageKamasUpdateMessage -"<<"Forbidden value (" << this->kamasTotal << ") on element of StorageKamasUpdateMessage.kamasTotal.";
  }
}

StorageKamasUpdateMessage::StorageKamasUpdateMessage()
{
  m_type = MessageEnum::STORAGEKAMASUPDATEMESSAGE;
}

