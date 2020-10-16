#include "NewMailMessage.h"

void NewMailMessage::serialize(Writer *output)
{
  this->serializeAs_NewMailMessage(output);
}

void NewMailMessage::serializeAs_NewMailMessage(Writer *output)
{
  MailStatusMessage::serializeAs_MailStatusMessage(output);
  output->writeShort((short)this->sendersAccountId.size());
  for(uint _i1 = 0; _i1 < this->sendersAccountId.size(); _i1++)
  {
    if(this->sendersAccountId[_i1] < 0)
    {
      qDebug()<<"ERREUR - NewMailMessage -"<<"Forbidden value (" << this->sendersAccountId[_i1] << ") on element 1 (starting at 1) of sendersAccountId.";
    }
    output->writeInt((int)this->sendersAccountId[_i1]);
  }
}

void NewMailMessage::deserialize(Reader *input)
{
  this->deserializeAs_NewMailMessage(input);
}

void NewMailMessage::deserializeAs_NewMailMessage(Reader *input)
{
  uint _val1 = 0;
  MailStatusMessage::deserialize(input);
  uint _sendersAccountIdLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _sendersAccountIdLen; _i1++)
  {
    _val1 = input->readInt();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - NewMailMessage -"<<"Forbidden value (" << _val1 << ") on elements of sendersAccountId.";
    }
    this->sendersAccountId.append(_val1);
  }
}

void NewMailMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_NewMailMessage(tree);
}

void NewMailMessage::deserializeAsyncAs_NewMailMessage(FuncTree tree)
{
  MailStatusMessage::deserializeAsync(tree);
  this->_sendersAccountIdtree = tree.addChild(std::bind(&NewMailMessage::_sendersAccountIdtreeFunc, this, std::placeholders::_1));
}

void NewMailMessage::_sendersAccountIdtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_sendersAccountIdtree.addChild(std::bind(&NewMailMessage::_sendersAccountIdFunc, this, std::placeholders::_1));
  }
}

void NewMailMessage::_sendersAccountIdFunc(Reader *input)
{
  uint _val = input->readInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - NewMailMessage -"<<"Forbidden value (" << _val << ") on elements of sendersAccountId.";
  }
  this->sendersAccountId.append(_val);
}

NewMailMessage::NewMailMessage()
{
  m_type = MessageEnum::NEWMAILMESSAGE;
}

