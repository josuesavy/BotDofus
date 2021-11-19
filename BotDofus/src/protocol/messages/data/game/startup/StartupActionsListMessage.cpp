#include "StartupActionsListMessage.h"

void StartupActionsListMessage::serialize(Writer *output)
{
  this->serializeAs_StartupActionsListMessage(output);
}

void StartupActionsListMessage::serializeAs_StartupActionsListMessage(Writer *output)
{
  output->writeShort((short)this->actions.size());
  for(uint _i1 = 0; _i1 < this->actions.size(); _i1++)
  {
    qSharedPointerCast<StartupActionAddObject>(this->actions[_i1])->serializeAs_StartupActionAddObject(output);
  }
}

void StartupActionsListMessage::deserialize(Reader *input)
{
  this->deserializeAs_StartupActionsListMessage(input);
}

void StartupActionsListMessage::deserializeAs_StartupActionsListMessage(Reader *input)
{
  QSharedPointer<StartupActionAddObject> _item1 ;
  uint _actionsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _actionsLen; _i1++)
  {
    _item1 = QSharedPointer<StartupActionAddObject>(new StartupActionAddObject() );
    _item1->deserialize(input);
    this->actions.append(_item1);
  }
}

void StartupActionsListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StartupActionsListMessage(tree);
}

void StartupActionsListMessage::deserializeAsyncAs_StartupActionsListMessage(FuncTree tree)
{
  this->_actionstree = tree.addChild(std::bind(&StartupActionsListMessage::_actionstreeFunc, this, std::placeholders::_1));
}

void StartupActionsListMessage::_actionstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_actionstree.addChild(std::bind(&StartupActionsListMessage::_actionsFunc, this, std::placeholders::_1));
  }
}

void StartupActionsListMessage::_actionsFunc(Reader *input)
{
  QSharedPointer<StartupActionAddObject> _item = QSharedPointer<StartupActionAddObject>(new StartupActionAddObject() );
  _item->deserialize(input);
  this->actions.append(_item);
}

StartupActionsListMessage::StartupActionsListMessage()
{
  m_type = MessageEnum::STARTUPACTIONSLISTMESSAGE;
}

