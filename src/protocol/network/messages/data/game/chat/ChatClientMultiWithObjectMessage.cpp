#include "ChatClientMultiWithObjectMessage.h"

void ChatClientMultiWithObjectMessage::serialize(Writer *output)
{
  this->serializeAs_ChatClientMultiWithObjectMessage(output);
}

void ChatClientMultiWithObjectMessage::serializeAs_ChatClientMultiWithObjectMessage(Writer *output)
{
  ChatClientMultiMessage::serializeAs_ChatClientMultiMessage(output);
  output->writeShort((short)this->objects.size());
  for(uint _i1 = 0; _i1 < this->objects.size(); _i1++)
  {
    qSharedPointerCast<ObjectItem>(this->objects[_i1])->serializeAs_ObjectItem(output);
  }
}

void ChatClientMultiWithObjectMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChatClientMultiWithObjectMessage(input);
}

void ChatClientMultiWithObjectMessage::deserializeAs_ChatClientMultiWithObjectMessage(Reader *input)
{
  QSharedPointer<ObjectItem> _item1 ;
  ChatClientMultiMessage::deserialize(input);
  uint _objectsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _objectsLen; _i1++)
  {
    _item1 = QSharedPointer<ObjectItem>(new ObjectItem() );
    _item1->deserialize(input);
    this->objects.append(_item1);
  }
}

void ChatClientMultiWithObjectMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChatClientMultiWithObjectMessage(tree);
}

void ChatClientMultiWithObjectMessage::deserializeAsyncAs_ChatClientMultiWithObjectMessage(FuncTree tree)
{
  ChatClientMultiMessage::deserializeAsync(tree);
  this->_objectstree = tree.addChild(std::bind(&ChatClientMultiWithObjectMessage::_objectstreeFunc, this, std::placeholders::_1));
}

void ChatClientMultiWithObjectMessage::_objectstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_objectstree.addChild(std::bind(&ChatClientMultiWithObjectMessage::_objectsFunc, this, std::placeholders::_1));
  }
}

void ChatClientMultiWithObjectMessage::_objectsFunc(Reader *input)
{
  QSharedPointer<ObjectItem> _item = QSharedPointer<ObjectItem>(new ObjectItem() );
  _item->deserialize(input);
  this->objects.append(_item);
}

ChatClientMultiWithObjectMessage::ChatClientMultiWithObjectMessage()
{
  m_type = MessageEnum::CHATCLIENTMULTIWITHOBJECTMESSAGE;
  m_needsHash = true;
}

