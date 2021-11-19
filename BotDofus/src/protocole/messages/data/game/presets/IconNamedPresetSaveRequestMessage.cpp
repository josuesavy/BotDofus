#include "IconNamedPresetSaveRequestMessage.h"

void IconNamedPresetSaveRequestMessage::serialize(Writer *output)
{
  this->serializeAs_IconNamedPresetSaveRequestMessage(output);
}

void IconNamedPresetSaveRequestMessage::serializeAs_IconNamedPresetSaveRequestMessage(Writer *output)
{
  IconPresetSaveRequestMessage::serializeAs_IconPresetSaveRequestMessage(output);
  output->writeUTF(this->name);
  output->writeByte(this->type);
}

void IconNamedPresetSaveRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_IconNamedPresetSaveRequestMessage(input);
}

void IconNamedPresetSaveRequestMessage::deserializeAs_IconNamedPresetSaveRequestMessage(Reader *input)
{
  IconPresetSaveRequestMessage::deserialize(input);
  this->_nameFunc(input);
  this->_typeFunc(input);
}

void IconNamedPresetSaveRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IconNamedPresetSaveRequestMessage(tree);
}

void IconNamedPresetSaveRequestMessage::deserializeAsyncAs_IconNamedPresetSaveRequestMessage(FuncTree tree)
{
  IconPresetSaveRequestMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&IconNamedPresetSaveRequestMessage::_nameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IconNamedPresetSaveRequestMessage::_typeFunc, this, std::placeholders::_1));
}

void IconNamedPresetSaveRequestMessage::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

void IconNamedPresetSaveRequestMessage::_typeFunc(Reader *input)
{
  this->type = input->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - IconNamedPresetSaveRequestMessage -"<<"Forbidden value (" << this->type << ") on element of IconNamedPresetSaveRequestMessage.type.";
  }
}

IconNamedPresetSaveRequestMessage::IconNamedPresetSaveRequestMessage()
{
  m_type = MessageEnum::ICONNAMEDPRESETSAVEREQUESTMESSAGE;
}

