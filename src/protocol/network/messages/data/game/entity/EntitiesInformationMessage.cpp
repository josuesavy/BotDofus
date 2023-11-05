#include "EntitiesInformationMessage.h"

void EntitiesInformationMessage::serialize(Writer *output)
{
  this->serializeAs_EntitiesInformationMessage(output);
}

void EntitiesInformationMessage::serializeAs_EntitiesInformationMessage(Writer *output)
{
  output->writeShort((short)this->entities.size());
  for(uint _i1 = 0; _i1 < this->entities.size(); _i1++)
  {
    (this->entities[_i1]).serializeAs_EntityInformation(output);
  }
}

void EntitiesInformationMessage::deserialize(Reader *input)
{
  this->deserializeAs_EntitiesInformationMessage(input);
}

void EntitiesInformationMessage::deserializeAs_EntitiesInformationMessage(Reader *input)
{
  EntityInformation _item1 ;
  uint _entitiesLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _entitiesLen; _i1++)
  {
    _item1 = EntityInformation();
    _item1.deserialize(input);
    this->entities.append(_item1);
  }
}

void EntitiesInformationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_EntitiesInformationMessage(tree);
}

void EntitiesInformationMessage::deserializeAsyncAs_EntitiesInformationMessage(FuncTree tree)
{
  this->_entitiestree = tree.addChild(std::bind(&EntitiesInformationMessage::_entitiestreeFunc, this, std::placeholders::_1));
}

void EntitiesInformationMessage::_entitiestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_entitiestree.addChild(std::bind(&EntitiesInformationMessage::_entitiesFunc, this, std::placeholders::_1));
  }
}

void EntitiesInformationMessage::_entitiesFunc(Reader *input)
{
  EntityInformation _item = EntityInformation();
  _item.deserialize(input);
  this->entities.append(_item);
}

EntitiesInformationMessage::EntitiesInformationMessage()
{
  m_type = MessageEnum::ENTITIESINFORMATIONMESSAGE;
}

