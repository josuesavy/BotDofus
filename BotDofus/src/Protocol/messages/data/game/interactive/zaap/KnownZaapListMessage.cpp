#include "KnownZaapListMessage.h"

void KnownZaapListMessage::serialize(Writer *output)
{
  this->serializeAs_KnownZaapListMessage(output);
}

void KnownZaapListMessage::serializeAs_KnownZaapListMessage(Writer *output)
{
  output->writeShort((short)this->destinations.size());
  for(uint _i1 = 0; _i1 < this->destinations.size(); _i1++)
  {
    if(this->destinations[_i1] < 0 || this->destinations[_i1] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - KnownZaapListMessage -"<<"Forbidden value (" << this->destinations[_i1] << ") on element 1 (starting at 1) of destinations.";
    }
    output->writeDouble(this->destinations[_i1]);
  }
}

void KnownZaapListMessage::deserialize(Reader *input)
{
  this->deserializeAs_KnownZaapListMessage(input);
}

void KnownZaapListMessage::deserializeAs_KnownZaapListMessage(Reader *input)
{
  auto _val1 = NULL;
  uint _destinationsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _destinationsLen; _i1++)
  {
    _val1 = input->readDouble();
    if(_val1 < 0 || _val1 > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - KnownZaapListMessage -"<<"Forbidden value (" << _val1 << ") on elements of destinations.";
    }
    this->destinations.append(_val1);
  }
}

void KnownZaapListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_KnownZaapListMessage(tree);
}

void KnownZaapListMessage::deserializeAsyncAs_KnownZaapListMessage(FuncTree tree)
{
  this->_destinationstree = tree.addChild(std::bind(&KnownZaapListMessage::_destinationstreeFunc, this, std::placeholders::_1));
}

void KnownZaapListMessage::_destinationstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_destinationstree.addChild(std::bind(&KnownZaapListMessage::_destinationsFunc, this, std::placeholders::_1));
  }
}

void KnownZaapListMessage::_destinationsFunc(Reader *input)
{
  double _val = input->readDouble();
  if(_val < 0 || _val > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - KnownZaapListMessage -"<<"Forbidden value (" << _val << ") on elements of destinations.";
  }
  this->destinations.append(_val);
}

KnownZaapListMessage::KnownZaapListMessage()
{
  m_type = MessageEnum::KNOWNZAAPLISTMESSAGE;
}

