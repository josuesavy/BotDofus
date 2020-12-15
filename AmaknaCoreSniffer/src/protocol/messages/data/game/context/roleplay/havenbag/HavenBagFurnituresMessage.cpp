#include "HavenBagFurnituresMessage.h"

void HavenBagFurnituresMessage::serialize(Writer *output)
{
  this->serializeAs_HavenBagFurnituresMessage(output);
}

void HavenBagFurnituresMessage::serializeAs_HavenBagFurnituresMessage(Writer *output)
{
  output->writeShort((short)this->furnituresInfos.size());
  for(uint _i1 = 0; _i1 < this->furnituresInfos.size(); _i1++)
  {
    (this->furnituresInfos[_i1]).serializeAs_HavenBagFurnitureInformation(output);
  }
}

void HavenBagFurnituresMessage::deserialize(Reader *input)
{
  this->deserializeAs_HavenBagFurnituresMessage(input);
}

void HavenBagFurnituresMessage::deserializeAs_HavenBagFurnituresMessage(Reader *input)
{
  HavenBagFurnitureInformation _item1 ;
  uint _furnituresInfosLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _furnituresInfosLen; _i1++)
  {
    _item1 = HavenBagFurnitureInformation();
    _item1.deserialize(input);
    this->furnituresInfos.append(_item1);
  }
}

void HavenBagFurnituresMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HavenBagFurnituresMessage(tree);
}

void HavenBagFurnituresMessage::deserializeAsyncAs_HavenBagFurnituresMessage(FuncTree tree)
{
  this->_furnituresInfostree = tree.addChild(std::bind(&HavenBagFurnituresMessage::_furnituresInfostreeFunc, this, std::placeholders::_1));
}

void HavenBagFurnituresMessage::_furnituresInfostreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_furnituresInfostree.addChild(std::bind(&HavenBagFurnituresMessage::_furnituresInfosFunc, this, std::placeholders::_1));
  }
}

void HavenBagFurnituresMessage::_furnituresInfosFunc(Reader *input)
{
  HavenBagFurnitureInformation _item = HavenBagFurnitureInformation();
  _item.deserialize(input);
  this->furnituresInfos.append(_item);
}

HavenBagFurnituresMessage::HavenBagFurnituresMessage()
{
  m_type = MessageEnum::HAVENBAGFURNITURESMESSAGE;
}

