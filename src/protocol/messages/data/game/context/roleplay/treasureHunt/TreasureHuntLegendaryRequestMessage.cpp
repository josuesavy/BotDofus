#include "TreasureHuntLegendaryRequestMessage.h"

void TreasureHuntLegendaryRequestMessage::serialize(Writer *output)
{
  this->serializeAs_TreasureHuntLegendaryRequestMessage(output);
}

void TreasureHuntLegendaryRequestMessage::serializeAs_TreasureHuntLegendaryRequestMessage(Writer *output)
{
  if(this->legendaryId < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntLegendaryRequestMessage -"<<"Forbidden value (" << this->legendaryId << ") on element legendaryId.";
  }
  output->writeVarShort((int)this->legendaryId);
}

void TreasureHuntLegendaryRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_TreasureHuntLegendaryRequestMessage(input);
}

void TreasureHuntLegendaryRequestMessage::deserializeAs_TreasureHuntLegendaryRequestMessage(Reader *input)
{
  this->_legendaryIdFunc(input);
}

void TreasureHuntLegendaryRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TreasureHuntLegendaryRequestMessage(tree);
}

void TreasureHuntLegendaryRequestMessage::deserializeAsyncAs_TreasureHuntLegendaryRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TreasureHuntLegendaryRequestMessage::_legendaryIdFunc, this, std::placeholders::_1));
}

void TreasureHuntLegendaryRequestMessage::_legendaryIdFunc(Reader *input)
{
  this->legendaryId = input->readVarUhShort();
  if(this->legendaryId < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntLegendaryRequestMessage -"<<"Forbidden value (" << this->legendaryId << ") on element of TreasureHuntLegendaryRequestMessage.legendaryId.";
  }
}

TreasureHuntLegendaryRequestMessage::TreasureHuntLegendaryRequestMessage()
{
  m_type = MessageEnum::TREASUREHUNTLEGENDARYREQUESTMESSAGE;
}

