#include "ChatServerWithObjectMessage.h"

void ChatServerWithObjectMessage::serialize(Writer *output)
{
  this->serializeAs_ChatServerWithObjectMessage(output);
}

void ChatServerWithObjectMessage::serializeAs_ChatServerWithObjectMessage(Writer *output)
{
  ChatServerMessage::serializeAs_ChatServerMessage(output);
  output->writeShort((short)this->objects.size());
  for(uint _i1 = 0; _i1 < this->objects.size(); _i1++)
  {
    qSharedPointerCast<ObjectItem>(this->objects[_i1])->serializeAs_ObjectItem(output);
  }
}

void ChatServerWithObjectMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChatServerWithObjectMessage(input);
}

void ChatServerWithObjectMessage::deserializeAs_ChatServerWithObjectMessage(Reader *input)
{
  QSharedPointer<ObjectItem> _item1 ;
  ChatServerMessage::deserialize(input);
  uint _objectsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _objectsLen; _i1++)
  {
    _item1 = QSharedPointer<ObjectItem>(new ObjectItem() );
    _item1->deserialize(input);
    this->objects.append(_item1);
  }
}

void ChatServerWithObjectMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChatServerWithObjectMessage(tree);
}

void ChatServerWithObjectMessage::deserializeAsyncAs_ChatServerWithObjectMessage(FuncTree tree)
{
  ChatServerMessage::deserializeAsync(tree);
  this->_objectstree = tree.addChild(std::bind(&ChatServerWithObjectMessage::_objectstreeFunc, this, std::placeholders::_1));
}

void ChatServerWithObjectMessage::_objectstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_objectstree.addChild(std::bind(&ChatServerWithObjectMessage::_objectsFunc, this, std::placeholders::_1));
  }
}

void ChatServerWithObjectMessage::_objectsFunc(Reader *input)
{
  QSharedPointer<ObjectItem> _item = QSharedPointer<ObjectItem>(new ObjectItem() );
  _item->deserialize(input);
  this->objects.append(_item);
}

ChatServerWithObjectMessage::ChatServerWithObjectMessage()
{
  m_type = MessageEnum::CHATSERVERWITHOBJECTMESSAGE;
}

