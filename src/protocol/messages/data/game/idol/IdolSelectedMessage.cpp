#include "IdolSelectedMessage.h"

void IdolSelectedMessage::serialize(Writer *output)
{
  this->serializeAs_IdolSelectedMessage(output);
}

void IdolSelectedMessage::serializeAs_IdolSelectedMessage(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->activate);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->party);
  output->writeByte(_box0);
  if(this->idolId < 0)
  {
    qDebug()<<"ERREUR - IdolSelectedMessage -"<<"Forbidden value (" << this->idolId << ") on element idolId.";
  }
  output->writeVarShort((int)this->idolId);
}

void IdolSelectedMessage::deserialize(Reader *input)
{
  this->deserializeAs_IdolSelectedMessage(input);
}

void IdolSelectedMessage::deserializeAs_IdolSelectedMessage(Reader *input)
{
  this->deserializeByteBoxes(input);
  this->_idolIdFunc(input);
}

void IdolSelectedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IdolSelectedMessage(tree);
}

void IdolSelectedMessage::deserializeAsyncAs_IdolSelectedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&IdolSelectedMessage::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&IdolSelectedMessage::_idolIdFunc, this, std::placeholders::_1));
}

void IdolSelectedMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->activate = BooleanByteWrapper::getFlag(_box0, 0);
  this->party = BooleanByteWrapper::getFlag(_box0, 1);
}

void IdolSelectedMessage::_idolIdFunc(Reader *input)
{
  this->idolId = input->readVarUhShort();
  if(this->idolId < 0)
  {
    qDebug()<<"ERREUR - IdolSelectedMessage -"<<"Forbidden value (" << this->idolId << ") on element of IdolSelectedMessage.idolId.";
  }
}

IdolSelectedMessage::IdolSelectedMessage()
{
  m_type = MessageEnum::IDOLSELECTEDMESSAGE;
}

