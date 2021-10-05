#include "MimicryObjectFeedAndAssociateRequestMessage.h"

void MimicryObjectFeedAndAssociateRequestMessage::serialize(Writer *output)
{
  this->serializeAs_MimicryObjectFeedAndAssociateRequestMessage(output);
}

void MimicryObjectFeedAndAssociateRequestMessage::serializeAs_MimicryObjectFeedAndAssociateRequestMessage(Writer *output)
{
  SymbioticObjectAssociateRequestMessage::serializeAs_SymbioticObjectAssociateRequestMessage(output);
  if(this->foodUID < 0)
  {
    qDebug()<<"ERREUR - MimicryObjectFeedAndAssociateRequestMessage -"<<"Forbidden value (" << this->foodUID << ") on element foodUID.";
  }
  output->writeVarInt((int)this->foodUID);
  if(this->foodPos < 0 || this->foodPos > 255)
  {
    qDebug()<<"ERREUR - MimicryObjectFeedAndAssociateRequestMessage -"<<"Forbidden value (" << this->foodPos << ") on element foodPos.";
  }
  output->writeByte(this->foodPos);
  output->writeBool(this->preview);
}

void MimicryObjectFeedAndAssociateRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_MimicryObjectFeedAndAssociateRequestMessage(input);
}

void MimicryObjectFeedAndAssociateRequestMessage::deserializeAs_MimicryObjectFeedAndAssociateRequestMessage(Reader *input)
{
  SymbioticObjectAssociateRequestMessage::deserialize(input);
  this->_foodUIDFunc(input);
  this->_foodPosFunc(input);
  this->_previewFunc(input);
}

void MimicryObjectFeedAndAssociateRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MimicryObjectFeedAndAssociateRequestMessage(tree);
}

void MimicryObjectFeedAndAssociateRequestMessage::deserializeAsyncAs_MimicryObjectFeedAndAssociateRequestMessage(FuncTree tree)
{
  SymbioticObjectAssociateRequestMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&MimicryObjectFeedAndAssociateRequestMessage::_foodUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MimicryObjectFeedAndAssociateRequestMessage::_foodPosFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MimicryObjectFeedAndAssociateRequestMessage::_previewFunc, this, std::placeholders::_1));
}

void MimicryObjectFeedAndAssociateRequestMessage::_foodUIDFunc(Reader *input)
{
  this->foodUID = input->readVarUhInt();
  if(this->foodUID < 0)
  {
    qDebug()<<"ERREUR - MimicryObjectFeedAndAssociateRequestMessage -"<<"Forbidden value (" << this->foodUID << ") on element of MimicryObjectFeedAndAssociateRequestMessage.foodUID.";
  }
}

void MimicryObjectFeedAndAssociateRequestMessage::_foodPosFunc(Reader *input)
{
  this->foodPos = input->readUByte();
  if(this->foodPos < 0 || this->foodPos > 255)
  {
    qDebug()<<"ERREUR - MimicryObjectFeedAndAssociateRequestMessage -"<<"Forbidden value (" << this->foodPos << ") on element of MimicryObjectFeedAndAssociateRequestMessage.foodPos.";
  }
}

void MimicryObjectFeedAndAssociateRequestMessage::_previewFunc(Reader *input)
{
  this->preview = input->readBool();
}

MimicryObjectFeedAndAssociateRequestMessage::MimicryObjectFeedAndAssociateRequestMessage()
{
  m_type = MessageEnum::MIMICRYOBJECTFEEDANDASSOCIATEREQUESTMESSAGE;
}

