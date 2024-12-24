#include "TeleportHavenBagRequestMessage.h"

void TeleportHavenBagRequestMessage::serialize(Writer *output)
{
  this->serializeAs_TeleportHavenBagRequestMessage(output);
}

void TeleportHavenBagRequestMessage::serializeAs_TeleportHavenBagRequestMessage(Writer *output)
{
  if(this->guestId < 0 || this->guestId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TeleportHavenBagRequestMessage -"<<"Forbidden value (" << this->guestId << ") on element guestId.";
  }
  output->writeVarLong((double)this->guestId);
}

void TeleportHavenBagRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_TeleportHavenBagRequestMessage(input);
}

void TeleportHavenBagRequestMessage::deserializeAs_TeleportHavenBagRequestMessage(Reader *input)
{
  this->_guestIdFunc(input);
}

void TeleportHavenBagRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TeleportHavenBagRequestMessage(tree);
}

void TeleportHavenBagRequestMessage::deserializeAsyncAs_TeleportHavenBagRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TeleportHavenBagRequestMessage::_guestIdFunc, this, std::placeholders::_1));
}

void TeleportHavenBagRequestMessage::_guestIdFunc(Reader *input)
{
  this->guestId = input->readVarUhLong();
  if(this->guestId < 0 || this->guestId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TeleportHavenBagRequestMessage -"<<"Forbidden value (" << this->guestId << ") on element of TeleportHavenBagRequestMessage.guestId.";
  }
}

TeleportHavenBagRequestMessage::TeleportHavenBagRequestMessage()
{
  m_type = MessageEnum::TELEPORTHAVENBAGREQUESTMESSAGE;
}

