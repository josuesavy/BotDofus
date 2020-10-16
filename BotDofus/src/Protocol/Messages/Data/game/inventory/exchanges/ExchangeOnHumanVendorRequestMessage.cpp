#include "ExchangeOnHumanVendorRequestMessage.h"

void ExchangeOnHumanVendorRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeOnHumanVendorRequestMessage(output);
}

void ExchangeOnHumanVendorRequestMessage::serializeAs_ExchangeOnHumanVendorRequestMessage(Writer *output)
{
  if(this->humanVendorId < 0 || this->humanVendorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeOnHumanVendorRequestMessage -"<<"Forbidden value (" << this->humanVendorId << ") on element humanVendorId.";
  }
  output->writeVarLong((double)this->humanVendorId);
  if(this->humanVendorCell < 0 || this->humanVendorCell > 559)
  {
    qDebug()<<"ERREUR - ExchangeOnHumanVendorRequestMessage -"<<"Forbidden value (" << this->humanVendorCell << ") on element humanVendorCell.";
  }
  output->writeVarShort((int)this->humanVendorCell);
}

void ExchangeOnHumanVendorRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeOnHumanVendorRequestMessage(input);
}

void ExchangeOnHumanVendorRequestMessage::deserializeAs_ExchangeOnHumanVendorRequestMessage(Reader *input)
{
  this->_humanVendorIdFunc(input);
  this->_humanVendorCellFunc(input);
}

void ExchangeOnHumanVendorRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeOnHumanVendorRequestMessage(tree);
}

void ExchangeOnHumanVendorRequestMessage::deserializeAsyncAs_ExchangeOnHumanVendorRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeOnHumanVendorRequestMessage::_humanVendorIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeOnHumanVendorRequestMessage::_humanVendorCellFunc, this, std::placeholders::_1));
}

void ExchangeOnHumanVendorRequestMessage::_humanVendorIdFunc(Reader *input)
{
  this->humanVendorId = input->readVarUhLong();
  if(this->humanVendorId < 0 || this->humanVendorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeOnHumanVendorRequestMessage -"<<"Forbidden value (" << this->humanVendorId << ") on element of ExchangeOnHumanVendorRequestMessage.humanVendorId.";
  }
}

void ExchangeOnHumanVendorRequestMessage::_humanVendorCellFunc(Reader *input)
{
  this->humanVendorCell = input->readVarUhShort();
  if(this->humanVendorCell < 0 || this->humanVendorCell > 559)
  {
    qDebug()<<"ERREUR - ExchangeOnHumanVendorRequestMessage -"<<"Forbidden value (" << this->humanVendorCell << ") on element of ExchangeOnHumanVendorRequestMessage.humanVendorCell.";
  }
}

ExchangeOnHumanVendorRequestMessage::ExchangeOnHumanVendorRequestMessage()
{
  m_type = MessageEnum::EXCHANGEONHUMANVENDORREQUESTMESSAGE;
}

