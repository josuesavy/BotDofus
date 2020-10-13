#include "ObjectAddedMessage.h"

void ObjectAddedMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectAddedMessage(output);
}

void ObjectAddedMessage::serializeAs_ObjectAddedMessage(Writer *output)
{
  this->object->serializeAs_ObjectItem(output);
  output->writeByte(this->origin);
}

void ObjectAddedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectAddedMessage(input);
}

void ObjectAddedMessage::deserializeAs_ObjectAddedMessage(Reader *input)
{
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserialize(input);
  this->_originFunc(input);
}

void ObjectAddedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectAddedMessage(tree);
}

void ObjectAddedMessage::deserializeAsyncAs_ObjectAddedMessage(FuncTree tree)
{
  this->_objecttree = tree.addChild(std::bind(&ObjectAddedMessage::_objecttreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectAddedMessage::_originFunc, this, std::placeholders::_1));
}

void ObjectAddedMessage::_objecttreeFunc(Reader *input)
{
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserializeAsync(this->_objecttree);
}

void ObjectAddedMessage::_originFunc(Reader *input)
{
  this->origin = input->readByte();
  if(this->origin < 0)
  {
    qDebug()<<"ERREUR - ObjectAddedMessage -"<<"Forbidden value (" << this->origin << ") on element of ObjectAddedMessage.origin.";
  }
}

ObjectAddedMessage::ObjectAddedMessage()
{
  m_type = MessageEnum::OBJECTADDEDMESSAGE;
}

