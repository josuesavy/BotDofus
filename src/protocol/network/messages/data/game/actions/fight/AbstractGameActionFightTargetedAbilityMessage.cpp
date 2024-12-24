#include "AbstractGameActionFightTargetedAbilityMessage.h"

void AbstractGameActionFightTargetedAbilityMessage::serialize(Writer *output)
{
  this->serializeAs_AbstractGameActionFightTargetedAbilityMessage(output);
}

void AbstractGameActionFightTargetedAbilityMessage::serializeAs_AbstractGameActionFightTargetedAbilityMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->silentCast);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->verboseCast);
  output->writeByte(_box0);
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AbstractGameActionFightTargetedAbilityMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  if(this->destinationCellId < -1 || this->destinationCellId > 559)
  {
    qDebug()<<"ERREUR - AbstractGameActionFightTargetedAbilityMessage -"<<"Forbidden value (" << this->destinationCellId << ") on element destinationCellId.";
  }
  output->writeShort((short)this->destinationCellId);
  output->writeByte(this->critical);
}

void AbstractGameActionFightTargetedAbilityMessage::deserialize(Reader *input)
{
  this->deserializeAs_AbstractGameActionFightTargetedAbilityMessage(input);
}

void AbstractGameActionFightTargetedAbilityMessage::deserializeAs_AbstractGameActionFightTargetedAbilityMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->deserializeByteBoxes(input);
  this->_targetIdFunc(input);
  this->_destinationCellIdFunc(input);
  this->_criticalFunc(input);
}

void AbstractGameActionFightTargetedAbilityMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AbstractGameActionFightTargetedAbilityMessage(tree);
}

void AbstractGameActionFightTargetedAbilityMessage::deserializeAsyncAs_AbstractGameActionFightTargetedAbilityMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&AbstractGameActionFightTargetedAbilityMessage::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractGameActionFightTargetedAbilityMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractGameActionFightTargetedAbilityMessage::_destinationCellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractGameActionFightTargetedAbilityMessage::_criticalFunc, this, std::placeholders::_1));
}

void AbstractGameActionFightTargetedAbilityMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = uint(input->readByte());
  this->silentCast = BooleanByteWrapper::getFlag(_box0, 0);
  this->verboseCast = BooleanByteWrapper::getFlag(_box0, 1);
}

void AbstractGameActionFightTargetedAbilityMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AbstractGameActionFightTargetedAbilityMessage -"<<"Forbidden value (" << this->targetId << ") on element of AbstractGameActionFightTargetedAbilityMessage.targetId.";
  }
}

void AbstractGameActionFightTargetedAbilityMessage::_destinationCellIdFunc(Reader *input)
{
  this->destinationCellId = input->readShort();
  if(this->destinationCellId < -1 || this->destinationCellId > 559)
  {
    qDebug()<<"ERREUR - AbstractGameActionFightTargetedAbilityMessage -"<<"Forbidden value (" << this->destinationCellId << ") on element of AbstractGameActionFightTargetedAbilityMessage.destinationCellId.";
  }
}

void AbstractGameActionFightTargetedAbilityMessage::_criticalFunc(Reader *input)
{
  this->critical = input->readByte();
  if(this->critical < 0)
  {
    qDebug()<<"ERREUR - AbstractGameActionFightTargetedAbilityMessage -"<<"Forbidden value (" << this->critical << ") on element of AbstractGameActionFightTargetedAbilityMessage.critical.";
  }
}

AbstractGameActionFightTargetedAbilityMessage::AbstractGameActionFightTargetedAbilityMessage()
{
  m_type = MessageEnum::ABSTRACTGAMEACTIONFIGHTTARGETEDABILITYMESSAGE;
}

