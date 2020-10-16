#include "HavenBagRoomPreviewInformation.h"

void HavenBagRoomPreviewInformation::serialize(Writer *output)
{
  this->serializeAs_HavenBagRoomPreviewInformation(output);
}

void HavenBagRoomPreviewInformation::serializeAs_HavenBagRoomPreviewInformation(Writer *output)
{
  if(this->roomId < 0 || this->roomId > 255)
  {
    qDebug()<<"ERREUR - HavenBagRoomPreviewInformation -"<<"Forbidden value (" << this->roomId << ") on element roomId.";
  }
  output->writeByte(this->roomId);
  output->writeByte(this->themeId);
}

void HavenBagRoomPreviewInformation::deserialize(Reader *input)
{
  this->deserializeAs_HavenBagRoomPreviewInformation(input);
}

void HavenBagRoomPreviewInformation::deserializeAs_HavenBagRoomPreviewInformation(Reader *input)
{
  this->_roomIdFunc(input);
  this->_themeIdFunc(input);
}

void HavenBagRoomPreviewInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HavenBagRoomPreviewInformation(tree);
}

void HavenBagRoomPreviewInformation::deserializeAsyncAs_HavenBagRoomPreviewInformation(FuncTree tree)
{
  tree.addChild(std::bind(&HavenBagRoomPreviewInformation::_roomIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HavenBagRoomPreviewInformation::_themeIdFunc, this, std::placeholders::_1));
}

void HavenBagRoomPreviewInformation::_roomIdFunc(Reader *input)
{
  this->roomId = input->readUByte();
  if(this->roomId < 0 || this->roomId > 255)
  {
    qDebug()<<"ERREUR - HavenBagRoomPreviewInformation -"<<"Forbidden value (" << this->roomId << ") on element of HavenBagRoomPreviewInformation.roomId.";
  }
}

void HavenBagRoomPreviewInformation::_themeIdFunc(Reader *input)
{
  this->themeId = input->readByte();
}

HavenBagRoomPreviewInformation::HavenBagRoomPreviewInformation()
{
  m_types<<ClassEnum::HAVENBAGROOMPREVIEWINFORMATION;
}

bool HavenBagRoomPreviewInformation::operator==(const HavenBagRoomPreviewInformation &compared)
{
  if(roomId == compared.roomId)
  if(themeId == compared.themeId)
  return true;
  
  return false;
}

