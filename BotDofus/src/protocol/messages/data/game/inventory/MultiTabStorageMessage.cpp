#include "MultiTabStorageMessage.h"

void MultiTabStorageMessage::serialize(Writer *output)
{
  this->serializeAs_MultiTabStorageMessage(output);
}

void MultiTabStorageMessage::serializeAs_MultiTabStorageMessage(Writer *output)
{
  output->writeShort((short)this->tabs.size());
  for(uint _i1 = 0; _i1 < this->tabs.size(); _i1++)
  {
    (this->tabs[_i1]).serializeAs_StorageTabInformation(output);
  }
}

void MultiTabStorageMessage::deserialize(Reader *input)
{
  this->deserializeAs_MultiTabStorageMessage(input);
}

void MultiTabStorageMessage::deserializeAs_MultiTabStorageMessage(Reader *input)
{
  StorageTabInformation _item1 ;
  uint _tabsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _tabsLen; _i1++)
  {
    _item1 = StorageTabInformation();
    _item1.deserialize(input);
    this->tabs.append(_item1);
  }
}

void MultiTabStorageMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MultiTabStorageMessage(tree);
}

void MultiTabStorageMessage::deserializeAsyncAs_MultiTabStorageMessage(FuncTree tree)
{
  this->_tabstree = tree.addChild(std::bind(&MultiTabStorageMessage::_tabstreeFunc, this, std::placeholders::_1));
}

void MultiTabStorageMessage::_tabstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_tabstree.addChild(std::bind(&MultiTabStorageMessage::_tabsFunc, this, std::placeholders::_1));
  }
}

void MultiTabStorageMessage::_tabsFunc(Reader *input)
{
  StorageTabInformation _item = StorageTabInformation();
  _item.deserialize(input);
  this->tabs.append(_item);
}

MultiTabStorageMessage::MultiTabStorageMessage()
{
  m_type = MessageEnum::MULTITABSTORAGEMESSAGE;
}

