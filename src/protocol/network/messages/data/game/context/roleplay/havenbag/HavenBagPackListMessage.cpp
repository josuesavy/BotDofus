#include "HavenBagPackListMessage.h"

void HavenBagPackListMessage::serialize(Writer *output)
{
  this->serializeAs_HavenBagPackListMessage(output);
}

void HavenBagPackListMessage::serializeAs_HavenBagPackListMessage(Writer *output)
{
  output->writeShort((short)this->packIds.size());
  for(uint _i1 = 0; _i1 < this->packIds.size(); _i1++)
  {
    output->writeByte(this->packIds[_i1]);
  }
}

void HavenBagPackListMessage::deserialize(Reader *input)
{
  this->deserializeAs_HavenBagPackListMessage(input);
}

void HavenBagPackListMessage::deserializeAs_HavenBagPackListMessage(Reader *input)
{
  int _val1 = 0;
  uint _packIdsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _packIdsLen; _i1++)
  {
    _val1 = int(input->readByte());
    this->packIds.append(_val1);
  }
}

void HavenBagPackListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HavenBagPackListMessage(tree);
}

void HavenBagPackListMessage::deserializeAsyncAs_HavenBagPackListMessage(FuncTree tree)
{
  this->_packIdstree = tree.addChild(std::bind(&HavenBagPackListMessage::_packIdstreeFunc, this, std::placeholders::_1));
}

void HavenBagPackListMessage::_packIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_packIdstree.addChild(std::bind(&HavenBagPackListMessage::_packIdsFunc, this, std::placeholders::_1));
  }
}

void HavenBagPackListMessage::_packIdsFunc(Reader *input)
{
  int _val = int(input->readByte());
  this->packIds.append(_val);
}

HavenBagPackListMessage::HavenBagPackListMessage()
{
  m_type = MessageEnum::HAVENBAGPACKLISTMESSAGE;
}

