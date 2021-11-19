#include "TaxCollectorListMessage.h"

void TaxCollectorListMessage::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorListMessage(output);
}

void TaxCollectorListMessage::serializeAs_TaxCollectorListMessage(Writer *output)
{
  AbstractTaxCollectorListMessage::serializeAs_AbstractTaxCollectorListMessage(output);
  if(this->nbcollectorMax < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorListMessage -"<<"Forbidden value (" << this->nbcollectorMax << ") on element nbcollectorMax.";
  }
  output->writeByte(this->nbcollectorMax);
  output->writeShort((short)this->fightersInformations.size());
  for(uint _i2 = 0; _i2 < this->fightersInformations.size(); _i2++)
  {
    qSharedPointerCast<TaxCollectorFightersInformation>(this->fightersInformations[_i2])->serializeAs_TaxCollectorFightersInformation(output);
  }
  output->writeByte(this->infoType);
}

void TaxCollectorListMessage::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorListMessage(input);
}

void TaxCollectorListMessage::deserializeAs_TaxCollectorListMessage(Reader *input)
{
  QSharedPointer<TaxCollectorFightersInformation> _item2 ;
  AbstractTaxCollectorListMessage::deserialize(input);
  this->_nbcollectorMaxFunc(input);
  uint _fightersInformationsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _fightersInformationsLen; _i2++)
  {
    _item2 = QSharedPointer<TaxCollectorFightersInformation>(new TaxCollectorFightersInformation() );
    _item2->deserialize(input);
    this->fightersInformations.append(_item2);
  }
  this->_infoTypeFunc(input);
}

void TaxCollectorListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorListMessage(tree);
}

void TaxCollectorListMessage::deserializeAsyncAs_TaxCollectorListMessage(FuncTree tree)
{
  AbstractTaxCollectorListMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&TaxCollectorListMessage::_nbcollectorMaxFunc, this, std::placeholders::_1));
  this->_fightersInformationstree = tree.addChild(std::bind(&TaxCollectorListMessage::_fightersInformationstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorListMessage::_infoTypeFunc, this, std::placeholders::_1));
}

void TaxCollectorListMessage::_nbcollectorMaxFunc(Reader *input)
{
  this->nbcollectorMax = input->readByte();
  if(this->nbcollectorMax < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorListMessage -"<<"Forbidden value (" << this->nbcollectorMax << ") on element of TaxCollectorListMessage.nbcollectorMax.";
  }
}

void TaxCollectorListMessage::_fightersInformationstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_fightersInformationstree.addChild(std::bind(&TaxCollectorListMessage::_fightersInformationsFunc, this, std::placeholders::_1));
  }
}

void TaxCollectorListMessage::_fightersInformationsFunc(Reader *input)
{
  QSharedPointer<TaxCollectorFightersInformation> _item = QSharedPointer<TaxCollectorFightersInformation>(new TaxCollectorFightersInformation() );
  _item->deserialize(input);
  this->fightersInformations.append(_item);
}

void TaxCollectorListMessage::_infoTypeFunc(Reader *input)
{
  this->infoType = input->readByte();
  if(this->infoType < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorListMessage -"<<"Forbidden value (" << this->infoType << ") on element of TaxCollectorListMessage.infoType.";
  }
}

TaxCollectorListMessage::TaxCollectorListMessage()
{
  m_type = MessageEnum::TAXCOLLECTORLISTMESSAGE;
}

