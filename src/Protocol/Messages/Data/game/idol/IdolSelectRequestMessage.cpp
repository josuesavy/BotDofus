#include "IdolSelectRequestMessage.h"

void IdolSelectRequestMessage::serialize(Writer *output)
{
  this->serializeAs_IdolSelectRequestMessage(output);
}

void IdolSelectRequestMessage::serializeAs_IdolSelectRequestMessage(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->activate);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->party);
  output->writeByte(_box0);
  if(this->idolId < 0)
  {
    qDebug()<<"ERREUR - IdolSelectRequestMessage -"<<"Forbidden value (" << this->idolId << ") on element idolId.";
  }
  output->writeVarShort((int)this->idolId);
}

void IdolSelectRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_IdolSelectRequestMessage(input);
}

void IdolSelectRequestMessage::deserializeAs_IdolSelectRequestMessage(Reader *input)
{
  this->deserializeByteBoxes(input);
  this->_idolIdFunc(input);
}

void IdolSelectRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IdolSelectRequestMessage(tree);
}

void IdolSelectRequestMessage::deserializeAsyncAs_IdolSelectRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&IdolSelectRequestMessage::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&IdolSelectRequestMessage::_idolIdFunc, this, std::placeholders::_1));
}

void IdolSelectRequestMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->activate = BooleanByteWrapper::getFlag(_box0, 0);
  this->party = BooleanByteWrapper::getFlag(_box0, 1);
}

void IdolSelectRequestMessage::_idolIdFunc(Reader *input)
{
  this->idolId = input->readVarUhShort();
  if(this->idolId < 0)
  {
    qDebug()<<"ERREUR - IdolSelectRequestMessage -"<<"Forbidden value (" << this->idolId << ") on element of IdolSelectRequestMessage.idolId.";
  }
}

IdolSelectRequestMessage::IdolSelectRequestMessage()
{
  m_type = MessageEnum::IDOLSELECTREQUESTMESSAGE;
}

