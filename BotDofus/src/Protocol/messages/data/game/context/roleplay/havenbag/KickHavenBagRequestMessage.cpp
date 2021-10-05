#include "KickHavenBagRequestMessage.h"

void KickHavenBagRequestMessage::serialize(Writer *output)
{
  this->serializeAs_KickHavenBagRequestMessage(output);
}

void KickHavenBagRequestMessage::serializeAs_KickHavenBagRequestMessage(Writer *output)
{
  if(this->guestId < 0 || this->guestId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - KickHavenBagRequestMessage -"<<"Forbidden value (" << this->guestId << ") on element guestId.";
  }
  output->writeVarLong((double)this->guestId);
}

void KickHavenBagRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_KickHavenBagRequestMessage(input);
}

void KickHavenBagRequestMessage::deserializeAs_KickHavenBagRequestMessage(Reader *input)
{
  this->_guestIdFunc(input);
}

void KickHavenBagRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_KickHavenBagRequestMessage(tree);
}

void KickHavenBagRequestMessage::deserializeAsyncAs_KickHavenBagRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&KickHavenBagRequestMessage::_guestIdFunc, this, std::placeholders::_1));
}

void KickHavenBagRequestMessage::_guestIdFunc(Reader *input)
{
  this->guestId = input->readVarUhLong();
  if(this->guestId < 0 || this->guestId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - KickHavenBagRequestMessage -"<<"Forbidden value (" << this->guestId << ") on element of KickHavenBagRequestMessage.guestId.";
  }
}

KickHavenBagRequestMessage::KickHavenBagRequestMessage()
{
  m_type = MessageEnum::KICKHAVENBAGREQUESTMESSAGE;
}

