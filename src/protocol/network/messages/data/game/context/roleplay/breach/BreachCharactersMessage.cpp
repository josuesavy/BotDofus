#include "BreachCharactersMessage.h"

void BreachCharactersMessage::serialize(Writer *output)
{
  this->serializeAs_BreachCharactersMessage(output);
}

void BreachCharactersMessage::serializeAs_BreachCharactersMessage(Writer *output)
{
  output->writeShort((short)this->characters.size());
  for(uint _i1 = 0; _i1 < this->characters.size(); _i1++)
  {
    if(this->characters[_i1] < 0 || this->characters[_i1] > 9007199254740992)
    {
      qDebug()<<"ERREUR - BreachCharactersMessage -"<<"Forbidden value (" << this->characters[_i1] << ") on element 1 (starting at 1) of characters.";
    }
    output->writeVarLong((double)this->characters[_i1]);
  }
}

void BreachCharactersMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachCharactersMessage(input);
}

void BreachCharactersMessage::deserializeAs_BreachCharactersMessage(Reader *input)
{
  double _val1 = NULL;
  uint _charactersLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _charactersLen; _i1++)
  {
    _val1 = input->readVarUhLong();
    if(_val1 < 0 || _val1 > 9007199254740992)
    {
      qDebug()<<"ERREUR - BreachCharactersMessage -"<<"Forbidden value (" << _val1 << ") on elements of characters.";
    }
    this->characters.append(_val1);
  }
}

void BreachCharactersMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachCharactersMessage(tree);
}

void BreachCharactersMessage::deserializeAsyncAs_BreachCharactersMessage(FuncTree tree)
{
  this->_characterstree = tree.addChild(std::bind(&BreachCharactersMessage::_characterstreeFunc, this, std::placeholders::_1));
}

void BreachCharactersMessage::_characterstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_characterstree.addChild(std::bind(&BreachCharactersMessage::_charactersFunc, this, std::placeholders::_1));
  }
}

void BreachCharactersMessage::_charactersFunc(Reader *input)
{
  double _val = input->readVarUhLong();
  if(_val < 0 || _val > 9007199254740992)
  {
    qDebug()<<"ERREUR - BreachCharactersMessage -"<<"Forbidden value (" << _val << ") on elements of characters.";
  }
  this->characters.append(_val);
}

BreachCharactersMessage::BreachCharactersMessage()
{
  m_type = MessageEnum::BREACHCHARACTERSMESSAGE;
}

