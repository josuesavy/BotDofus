#include "TaxCollectorAttackedResultMessage.h"

void TaxCollectorAttackedResultMessage::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorAttackedResultMessage(output);
}

void TaxCollectorAttackedResultMessage::serializeAs_TaxCollectorAttackedResultMessage(Writer *output)
{
  output->writeBool(this->deadOrAlive);
  this->basicInfos.serializeAs_TaxCollectorBasicInformations(output);
  this->alliance->serializeAs_BasicAllianceInformations(output);
}

void TaxCollectorAttackedResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorAttackedResultMessage(input);
}

void TaxCollectorAttackedResultMessage::deserializeAs_TaxCollectorAttackedResultMessage(Reader *input)
{
  this->_deadOrAliveFunc(input);
  this->basicInfos = TaxCollectorBasicInformations();
  this->basicInfos.deserialize(input);
  this->alliance = QSharedPointer<BasicAllianceInformations>(new BasicAllianceInformations() );
  this->alliance->deserialize(input);
}

void TaxCollectorAttackedResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorAttackedResultMessage(tree);
}

void TaxCollectorAttackedResultMessage::deserializeAsyncAs_TaxCollectorAttackedResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TaxCollectorAttackedResultMessage::_deadOrAliveFunc, this, std::placeholders::_1));
  this->_basicInfostree = tree.addChild(std::bind(&TaxCollectorAttackedResultMessage::_basicInfostreeFunc, this, std::placeholders::_1));
  this->_alliancetree = tree.addChild(std::bind(&TaxCollectorAttackedResultMessage::_alliancetreeFunc, this, std::placeholders::_1));
}

void TaxCollectorAttackedResultMessage::_deadOrAliveFunc(Reader *input)
{
  this->deadOrAlive = input->readBool();
}

void TaxCollectorAttackedResultMessage::_basicInfostreeFunc(Reader *input)
{
  this->basicInfos = TaxCollectorBasicInformations();
  this->basicInfos.deserializeAsync(this->_basicInfostree);
}

void TaxCollectorAttackedResultMessage::_alliancetreeFunc(Reader *input)
{
  this->alliance = QSharedPointer<BasicAllianceInformations>(new BasicAllianceInformations() );
  this->alliance->deserializeAsync(this->_alliancetree);
}

TaxCollectorAttackedResultMessage::TaxCollectorAttackedResultMessage()
{
  m_type = MessageEnum::TAXCOLLECTORATTACKEDRESULTMESSAGE;
}

