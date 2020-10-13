#include "StartupActionAddMessage.h"

void StartupActionAddMessage::serialize(Writer *output)
{
  this->serializeAs_StartupActionAddMessage(output);
}

void StartupActionAddMessage::serializeAs_StartupActionAddMessage(Writer *output)
{
  this->newAction->serializeAs_StartupActionAddObject(output);
}

void StartupActionAddMessage::deserialize(Reader *input)
{
  this->deserializeAs_StartupActionAddMessage(input);
}

void StartupActionAddMessage::deserializeAs_StartupActionAddMessage(Reader *input)
{
  this->newAction = QSharedPointer<StartupActionAddObject>(new StartupActionAddObject() );
  this->newAction->deserialize(input);
}

void StartupActionAddMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StartupActionAddMessage(tree);
}

void StartupActionAddMessage::deserializeAsyncAs_StartupActionAddMessage(FuncTree tree)
{
  this->_newActiontree = tree.addChild(std::bind(&StartupActionAddMessage::_newActiontreeFunc, this, std::placeholders::_1));
}

void StartupActionAddMessage::_newActiontreeFunc(Reader *input)
{
  this->newAction = QSharedPointer<StartupActionAddObject>(new StartupActionAddObject() );
  this->newAction->deserializeAsync(this->_newActiontree);
}

StartupActionAddMessage::StartupActionAddMessage()
{
  m_type = MessageEnum::STARTUPACTIONADDMESSAGE;
}

