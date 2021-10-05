#include "PrismUseRequestMessage.h"

void PrismUseRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PrismUseRequestMessage(output);
}

void PrismUseRequestMessage::serializeAs_PrismUseRequestMessage(Writer *output)
{
  output->writeByte(this->moduleToUse);
}

void PrismUseRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismUseRequestMessage(input);
}

void PrismUseRequestMessage::deserializeAs_PrismUseRequestMessage(Reader *input)
{
  this->_moduleToUseFunc(input);
}

void PrismUseRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismUseRequestMessage(tree);
}

void PrismUseRequestMessage::deserializeAsyncAs_PrismUseRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PrismUseRequestMessage::_moduleToUseFunc, this, std::placeholders::_1));
}

void PrismUseRequestMessage::_moduleToUseFunc(Reader *input)
{
  this->moduleToUse = input->readByte();
  if(this->moduleToUse < 0)
  {
    qDebug()<<"ERREUR - PrismUseRequestMessage -"<<"Forbidden value (" << this->moduleToUse << ") on element of PrismUseRequestMessage.moduleToUse.";
  }
}

PrismUseRequestMessage::PrismUseRequestMessage()
{
  m_type = MessageEnum::PRISMUSEREQUESTMESSAGE;
}

