#include "TreasureHuntShowLegendaryUIMessage.h"

void TreasureHuntShowLegendaryUIMessage::serialize(Writer *output)
{
  this->serializeAs_TreasureHuntShowLegendaryUIMessage(output);
}

void TreasureHuntShowLegendaryUIMessage::serializeAs_TreasureHuntShowLegendaryUIMessage(Writer *output)
{
  output->writeShort((short)this->availableLegendaryIds.size());
  for(uint _i1 = 0; _i1 < this->availableLegendaryIds.size(); _i1++)
  {
    if(this->availableLegendaryIds[_i1] < 0)
    {
      qDebug()<<"ERREUR - TreasureHuntShowLegendaryUIMessage -"<<"Forbidden value (" << this->availableLegendaryIds[_i1] << ") on element 1 (starting at 1) of availableLegendaryIds.";
    }
    output->writeVarShort((int)this->availableLegendaryIds[_i1]);
  }
}

void TreasureHuntShowLegendaryUIMessage::deserialize(Reader *input)
{
  this->deserializeAs_TreasureHuntShowLegendaryUIMessage(input);
}

void TreasureHuntShowLegendaryUIMessage::deserializeAs_TreasureHuntShowLegendaryUIMessage(Reader *input)
{
  uint _val1 = 0;
  uint _availableLegendaryIdsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _availableLegendaryIdsLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - TreasureHuntShowLegendaryUIMessage -"<<"Forbidden value (" << _val1 << ") on elements of availableLegendaryIds.";
    }
    this->availableLegendaryIds.append(_val1);
  }
}

void TreasureHuntShowLegendaryUIMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TreasureHuntShowLegendaryUIMessage(tree);
}

void TreasureHuntShowLegendaryUIMessage::deserializeAsyncAs_TreasureHuntShowLegendaryUIMessage(FuncTree tree)
{
  this->_availableLegendaryIdstree = tree.addChild(std::bind(&TreasureHuntShowLegendaryUIMessage::_availableLegendaryIdstreeFunc, this, std::placeholders::_1));
}

void TreasureHuntShowLegendaryUIMessage::_availableLegendaryIdstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_availableLegendaryIdstree.addChild(std::bind(&TreasureHuntShowLegendaryUIMessage::_availableLegendaryIdsFunc, this, std::placeholders::_1));
  }
}

void TreasureHuntShowLegendaryUIMessage::_availableLegendaryIdsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntShowLegendaryUIMessage -"<<"Forbidden value (" << _val << ") on elements of availableLegendaryIds.";
  }
  this->availableLegendaryIds.append(_val);
}

TreasureHuntShowLegendaryUIMessage::TreasureHuntShowLegendaryUIMessage()
{
  m_type = MessageEnum::TREASUREHUNTSHOWLEGENDARYUIMESSAGE;
}

