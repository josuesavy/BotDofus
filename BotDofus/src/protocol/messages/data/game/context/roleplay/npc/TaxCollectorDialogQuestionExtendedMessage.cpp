#include "TaxCollectorDialogQuestionExtendedMessage.h"

void TaxCollectorDialogQuestionExtendedMessage::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorDialogQuestionExtendedMessage(output);
}

void TaxCollectorDialogQuestionExtendedMessage::serializeAs_TaxCollectorDialogQuestionExtendedMessage(Writer *output)
{
  TaxCollectorDialogQuestionBasicMessage::serializeAs_TaxCollectorDialogQuestionBasicMessage(output);
  if(this->maxPods < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->maxPods << ") on element maxPods.";
  }
  output->writeVarShort((int)this->maxPods);
  if(this->prospecting < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->prospecting << ") on element prospecting.";
  }
  output->writeVarShort((int)this->prospecting);
  if(this->wisdom < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->wisdom << ") on element wisdom.";
  }
  output->writeVarShort((int)this->wisdom);
  if(this->taxCollectorsCount < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->taxCollectorsCount << ") on element taxCollectorsCount.";
  }
  output->writeByte(this->taxCollectorsCount);
  output->writeInt((int)this->taxCollectorAttack);
  if(this->kamas < 0 || this->kamas > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->kamas << ") on element kamas.";
  }
  output->writeVarLong((double)this->kamas);
  if(this->experience < 0 || this->experience > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->experience << ") on element experience.";
  }
  output->writeVarLong((double)this->experience);
  if(this->pods < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->pods << ") on element pods.";
  }
  output->writeVarInt((int)this->pods);
  if(this->itemsValue < 0 || this->itemsValue > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->itemsValue << ") on element itemsValue.";
  }
  output->writeVarLong((double)this->itemsValue);
}

void TaxCollectorDialogQuestionExtendedMessage::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorDialogQuestionExtendedMessage(input);
}

void TaxCollectorDialogQuestionExtendedMessage::deserializeAs_TaxCollectorDialogQuestionExtendedMessage(Reader *input)
{
  TaxCollectorDialogQuestionBasicMessage::deserialize(input);
  this->_maxPodsFunc(input);
  this->_prospectingFunc(input);
  this->_wisdomFunc(input);
  this->_taxCollectorsCountFunc(input);
  this->_taxCollectorAttackFunc(input);
  this->_kamasFunc(input);
  this->_experienceFunc(input);
  this->_podsFunc(input);
  this->_itemsValueFunc(input);
}

void TaxCollectorDialogQuestionExtendedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorDialogQuestionExtendedMessage(tree);
}

void TaxCollectorDialogQuestionExtendedMessage::deserializeAsyncAs_TaxCollectorDialogQuestionExtendedMessage(FuncTree tree)
{
  TaxCollectorDialogQuestionBasicMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&TaxCollectorDialogQuestionExtendedMessage::_maxPodsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorDialogQuestionExtendedMessage::_prospectingFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorDialogQuestionExtendedMessage::_wisdomFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorDialogQuestionExtendedMessage::_taxCollectorsCountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorDialogQuestionExtendedMessage::_taxCollectorAttackFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorDialogQuestionExtendedMessage::_kamasFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorDialogQuestionExtendedMessage::_experienceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorDialogQuestionExtendedMessage::_podsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorDialogQuestionExtendedMessage::_itemsValueFunc, this, std::placeholders::_1));
}

void TaxCollectorDialogQuestionExtendedMessage::_maxPodsFunc(Reader *input)
{
  this->maxPods = input->readVarUhShort();
  if(this->maxPods < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->maxPods << ") on element of TaxCollectorDialogQuestionExtendedMessage.maxPods.";
  }
}

void TaxCollectorDialogQuestionExtendedMessage::_prospectingFunc(Reader *input)
{
  this->prospecting = input->readVarUhShort();
  if(this->prospecting < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->prospecting << ") on element of TaxCollectorDialogQuestionExtendedMessage.prospecting.";
  }
}

void TaxCollectorDialogQuestionExtendedMessage::_wisdomFunc(Reader *input)
{
  this->wisdom = input->readVarUhShort();
  if(this->wisdom < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->wisdom << ") on element of TaxCollectorDialogQuestionExtendedMessage.wisdom.";
  }
}

void TaxCollectorDialogQuestionExtendedMessage::_taxCollectorsCountFunc(Reader *input)
{
  this->taxCollectorsCount = input->readByte();
  if(this->taxCollectorsCount < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->taxCollectorsCount << ") on element of TaxCollectorDialogQuestionExtendedMessage.taxCollectorsCount.";
  }
}

void TaxCollectorDialogQuestionExtendedMessage::_taxCollectorAttackFunc(Reader *input)
{
  this->taxCollectorAttack = input->readInt();
}

void TaxCollectorDialogQuestionExtendedMessage::_kamasFunc(Reader *input)
{
  this->kamas = input->readVarUhLong();
  if(this->kamas < 0 || this->kamas > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->kamas << ") on element of TaxCollectorDialogQuestionExtendedMessage.kamas.";
  }
}

void TaxCollectorDialogQuestionExtendedMessage::_experienceFunc(Reader *input)
{
  this->experience = input->readVarUhLong();
  if(this->experience < 0 || this->experience > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->experience << ") on element of TaxCollectorDialogQuestionExtendedMessage.experience.";
  }
}

void TaxCollectorDialogQuestionExtendedMessage::_podsFunc(Reader *input)
{
  this->pods = input->readVarUhInt();
  if(this->pods < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->pods << ") on element of TaxCollectorDialogQuestionExtendedMessage.pods.";
  }
}

void TaxCollectorDialogQuestionExtendedMessage::_itemsValueFunc(Reader *input)
{
  this->itemsValue = input->readVarUhLong();
  if(this->itemsValue < 0 || this->itemsValue > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->itemsValue << ") on element of TaxCollectorDialogQuestionExtendedMessage.itemsValue.";
  }
}

TaxCollectorDialogQuestionExtendedMessage::TaxCollectorDialogQuestionExtendedMessage()
{
  m_type = MessageEnum::TAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE;
}

