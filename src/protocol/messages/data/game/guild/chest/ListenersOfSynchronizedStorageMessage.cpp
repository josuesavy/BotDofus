#include "ListenersOfSynchronizedStorageMessage.h"

void ListenersOfSynchronizedStorageMessage::serialize(Writer *output)
{
  this->serializeAs_ListenersOfSynchronizedStorageMessage(output);
}

void ListenersOfSynchronizedStorageMessage::serializeAs_ListenersOfSynchronizedStorageMessage(Writer *output)
{
  output->writeShort((short)this->players.size());
  for(uint _i1 = 0; _i1 < this->players.size(); _i1++)
  {
    output->writeUTF(this->players[_i1]);
  }
}

void ListenersOfSynchronizedStorageMessage::deserialize(Reader *input)
{
  this->deserializeAs_ListenersOfSynchronizedStorageMessage(input);
}

void ListenersOfSynchronizedStorageMessage::deserializeAs_ListenersOfSynchronizedStorageMessage(Reader *input)
{
  QString _val1 ;
  uint _playersLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _playersLen; _i1++)
  {
    _val1 = input->readUTF();
    this->players.append(_val1);
  }
}

void ListenersOfSynchronizedStorageMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ListenersOfSynchronizedStorageMessage(tree);
}

void ListenersOfSynchronizedStorageMessage::deserializeAsyncAs_ListenersOfSynchronizedStorageMessage(FuncTree tree)
{
  this->_playerstree = tree.addChild(std::bind(&ListenersOfSynchronizedStorageMessage::_playerstreeFunc, this, std::placeholders::_1));
}

void ListenersOfSynchronizedStorageMessage::_playerstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_playerstree.addChild(std::bind(&ListenersOfSynchronizedStorageMessage::_playersFunc, this, std::placeholders::_1));
  }
}

void ListenersOfSynchronizedStorageMessage::_playersFunc(Reader *input)
{
  QString _val = input->readUTF();
  this->players.append(_val);
}

ListenersOfSynchronizedStorageMessage::ListenersOfSynchronizedStorageMessage()
{
  m_type = MessageEnum::LISTENERSOFSYNCHRONIZEDSTORAGEMESSAGE;
}

