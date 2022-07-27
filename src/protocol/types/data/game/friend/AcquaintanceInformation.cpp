#include "AcquaintanceInformation.h"

void AcquaintanceInformation::serialize(Writer *output)
{
  this->serializeAs_AcquaintanceInformation(output);
}

void AcquaintanceInformation::serializeAs_AcquaintanceInformation(Writer *output)
{
  AbstractContactInformations::serializeAs_AbstractContactInformations(output);
  output->writeByte(this->playerState);
}

void AcquaintanceInformation::deserialize(Reader *input)
{
  this->deserializeAs_AcquaintanceInformation(input);
}

void AcquaintanceInformation::deserializeAs_AcquaintanceInformation(Reader *input)
{
  AbstractContactInformations::deserialize(input);
  this->_playerStateFunc(input);
}

void AcquaintanceInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AcquaintanceInformation(tree);
}

void AcquaintanceInformation::deserializeAsyncAs_AcquaintanceInformation(FuncTree tree)
{
  AbstractContactInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&AcquaintanceInformation::_playerStateFunc, this, std::placeholders::_1));
}

void AcquaintanceInformation::_playerStateFunc(Reader *input)
{
  this->playerState = input->readByte();
  if(this->playerState < 0)
  {
    qDebug()<<"ERREUR - AcquaintanceInformation -"<<"Forbidden value (" << this->playerState << ") on element of AcquaintanceInformation.playerState.";
  }
}

AcquaintanceInformation::AcquaintanceInformation()
{
  m_types<<ClassEnum::ACQUAINTANCEINFORMATION;
}

bool AcquaintanceInformation::operator==(const AcquaintanceInformation &compared)
{
  if(playerState == compared.playerState)
  return true;
  
  return false;
}

