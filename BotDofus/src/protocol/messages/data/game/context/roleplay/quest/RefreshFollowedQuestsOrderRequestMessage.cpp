#include "RefreshFollowedQuestsOrderRequestMessage.h"

void RefreshFollowedQuestsOrderRequestMessage::serialize(Writer *output)
{
  this->serializeAs_RefreshFollowedQuestsOrderRequestMessage(output);
}

void RefreshFollowedQuestsOrderRequestMessage::serializeAs_RefreshFollowedQuestsOrderRequestMessage(Writer *output)
{
  output->writeShort((short)this->quests.size());
  for(uint _i1 = 0; _i1 < this->quests.size(); _i1++)
  {
    if(this->quests[_i1] < 0)
    {
      qDebug()<<"ERREUR - RefreshFollowedQuestsOrderRequestMessage -"<<"Forbidden value (" << this->quests[_i1] << ") on element 1 (starting at 1) of quests.";
    }
    output->writeVarShort((int)this->quests[_i1]);
  }
}

void RefreshFollowedQuestsOrderRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_RefreshFollowedQuestsOrderRequestMessage(input);
}

void RefreshFollowedQuestsOrderRequestMessage::deserializeAs_RefreshFollowedQuestsOrderRequestMessage(Reader *input)
{
  uint _val1 = 0;
  uint _questsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _questsLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - RefreshFollowedQuestsOrderRequestMessage -"<<"Forbidden value (" << _val1 << ") on elements of quests.";
    }
    this->quests.append(_val1);
  }
}

void RefreshFollowedQuestsOrderRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_RefreshFollowedQuestsOrderRequestMessage(tree);
}

void RefreshFollowedQuestsOrderRequestMessage::deserializeAsyncAs_RefreshFollowedQuestsOrderRequestMessage(FuncTree tree)
{
  this->_queststree = tree.addChild(std::bind(&RefreshFollowedQuestsOrderRequestMessage::_queststreeFunc, this, std::placeholders::_1));
}

void RefreshFollowedQuestsOrderRequestMessage::_queststreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_queststree.addChild(std::bind(&RefreshFollowedQuestsOrderRequestMessage::_questsFunc, this, std::placeholders::_1));
  }
}

void RefreshFollowedQuestsOrderRequestMessage::_questsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - RefreshFollowedQuestsOrderRequestMessage -"<<"Forbidden value (" << _val << ") on elements of quests.";
  }
  this->quests.append(_val);
}

RefreshFollowedQuestsOrderRequestMessage::RefreshFollowedQuestsOrderRequestMessage()
{
  m_type = MessageEnum::REFRESHFOLLOWEDQUESTSORDERREQUESTMESSAGE;
}

