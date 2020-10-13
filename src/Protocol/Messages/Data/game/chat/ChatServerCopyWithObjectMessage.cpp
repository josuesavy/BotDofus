#include "ChatServerCopyWithObjectMessage.h"

void ChatServerCopyWithObjectMessage::serialize(Writer *output)
{
  this->serializeAs_ChatServerCopyWithObjectMessage(output);
}

void ChatServerCopyWithObjectMessage::serializeAs_ChatServerCopyWithObjectMessage(Writer *output)
{
  ChatServerCopyMessage::serializeAs_ChatServerCopyMessage(output);
  output->writeShort((short)this->objects.size());
  for(uint _i1 = 0; _i1 < this->objects.size(); _i1++)
  {
    qSharedPointerCast<ObjectItem>(this->objects[_i1])->serializeAs_ObjectItem(output);
  }
}

void ChatServerCopyWithObjectMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChatServerCopyWithObjectMessage(input);
}

void ChatServerCopyWithObjectMessage::deserializeAs_ChatServerCopyWithObjectMessage(Reader *input)
{
  QSharedPointer<ObjectItem> _item1 ;
  ChatServerCopyMessage::deserialize(input);
  uint _objectsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _objectsLen; _i1++)
  {
    _item1 = QSharedPointer<ObjectItem>(new ObjectItem() );
    _item1->deserialize(input);
    this->objects.append(_item1);
  }
}

void ChatServerCopyWithObjectMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChatServerCopyWithObjectMessage(tree);
}

void ChatServerCopyWithObjectMessage::deserializeAsyncAs_ChatServerCopyWithObjectMessage(FuncTree tree)
{
  ChatServerCopyMessage::deserializeAsync(tree);
  this->_objectstree = tree.addChild(std::bind(&ChatServerCopyWithObjectMessage::_objectstreeFunc, this, std::placeholders::_1));
}

void ChatServerCopyWithObjectMessage::_objectstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_objectstree.addChild(std::bind(&ChatServerCopyWithObjectMessage::_objectsFunc, this, std::placeholders::_1));
  }
}

void ChatServerCopyWithObjectMessage::_objectsFunc(Reader *input)
{
  QSharedPointer<ObjectItem> _item = QSharedPointer<ObjectItem>(new ObjectItem() );
  _item->deserialize(input);
  this->objects.append(_item);
}

ChatServerCopyWithObjectMessage::ChatServerCopyWithObjectMessage()
{
  m_type = MessageEnum::CHATSERVERCOPYWITHOBJECTMESSAGE;
}

