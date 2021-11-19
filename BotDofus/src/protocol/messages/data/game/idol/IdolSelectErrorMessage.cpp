#include "IdolSelectErrorMessage.h"

void IdolSelectErrorMessage::serialize(Writer *output)
{
  this->serializeAs_IdolSelectErrorMessage(output);
}

void IdolSelectErrorMessage::serializeAs_IdolSelectErrorMessage(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->activate);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->party);
  output->writeByte(_box0);
  output->writeByte(this->reason);
  if(this->idolId < 0)
  {
    qDebug()<<"ERREUR - IdolSelectErrorMessage -"<<"Forbidden value (" << this->idolId << ") on element idolId.";
  }
  output->writeVarShort((int)this->idolId);
}

void IdolSelectErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_IdolSelectErrorMessage(input);
}

void IdolSelectErrorMessage::deserializeAs_IdolSelectErrorMessage(Reader *input)
{
  this->deserializeByteBoxes(input);
  this->_reasonFunc(input);
  this->_idolIdFunc(input);
}

void IdolSelectErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IdolSelectErrorMessage(tree);
}

void IdolSelectErrorMessage::deserializeAsyncAs_IdolSelectErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&IdolSelectErrorMessage::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&IdolSelectErrorMessage::_reasonFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IdolSelectErrorMessage::_idolIdFunc, this, std::placeholders::_1));
}

void IdolSelectErrorMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->activate = BooleanByteWrapper::getFlag(_box0, 0);
  this->party = BooleanByteWrapper::getFlag(_box0, 1);
}

void IdolSelectErrorMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - IdolSelectErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of IdolSelectErrorMessage.reason.";
  }
}

void IdolSelectErrorMessage::_idolIdFunc(Reader *input)
{
  this->idolId = input->readVarUhShort();
  if(this->idolId < 0)
  {
    qDebug()<<"ERREUR - IdolSelectErrorMessage -"<<"Forbidden value (" << this->idolId << ") on element of IdolSelectErrorMessage.idolId.";
  }
}

IdolSelectErrorMessage::IdolSelectErrorMessage()
{
  m_type = MessageEnum::IDOLSELECTERRORMESSAGE;
}

