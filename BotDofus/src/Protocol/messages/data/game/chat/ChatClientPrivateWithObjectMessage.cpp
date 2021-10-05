#include "ChatClientPrivateWithObjectMessage.h"

void ChatClientPrivateWithObjectMessage::serialize(Writer *output)
{
  this->serializeAs_ChatClientPrivateWithObjectMessage(output);
}

void ChatClientPrivateWithObjectMessage::serializeAs_ChatClientPrivateWithObjectMessage(Writer *output)
{
  ChatClientPrivateMessage::serializeAs_ChatClientPrivateMessage(output);
  output->writeShort((short)this->objects.size());
  for(uint _i1 = 0; _i1 < this->objects.size(); _i1++)
  {
    qSharedPointerCast<ObjectItem>(this->objects[_i1])->serializeAs_ObjectItem(output);
  }
}

void ChatClientPrivateWithObjectMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChatClientPrivateWithObjectMessage(input);
}

void ChatClientPrivateWithObjectMessage::deserializeAs_ChatClientPrivateWithObjectMessage(Reader *input)
{
  QSharedPointer<ObjectItem> _item1 ;
  ChatClientPrivateMessage::deserialize(input);
  uint _objectsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _objectsLen; _i1++)
  {
    _item1 = QSharedPointer<ObjectItem>(new ObjectItem() );
    _item1->deserialize(input);
    this->objects.append(_item1);
  }
}

void ChatClientPrivateWithObjectMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChatClientPrivateWithObjectMessage(tree);
}

void ChatClientPrivateWithObjectMessage::deserializeAsyncAs_ChatClientPrivateWithObjectMessage(FuncTree tree)
{
  ChatClientPrivateMessage::deserializeAsync(tree);
  this->_objectstree = tree.addChild(std::bind(&ChatClientPrivateWithObjectMessage::_objectstreeFunc, this, std::placeholders::_1));
}

void ChatClientPrivateWithObjectMessage::_objectstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_objectstree.addChild(std::bind(&ChatClientPrivateWithObjectMessage::_objectsFunc, this, std::placeholders::_1));
  }
}

void ChatClientPrivateWithObjectMessage::_objectsFunc(Reader *input)
{
  QSharedPointer<ObjectItem> _item = QSharedPointer<ObjectItem>(new ObjectItem() );
  _item->deserialize(input);
  this->objects.append(_item);
}

ChatClientPrivateWithObjectMessage::ChatClientPrivateWithObjectMessage()
{
  m_type = MessageEnum::CHATCLIENTPRIVATEWITHOBJECTMESSAGE;
  m_needsHash = true;
}

