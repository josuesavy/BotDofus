#include "IdolsPresetSaveRequestMessage.h"

void IdolsPresetSaveRequestMessage::serialize(Writer *output)
{
  this->serializeAs_IdolsPresetSaveRequestMessage(output);
}

void IdolsPresetSaveRequestMessage::serializeAs_IdolsPresetSaveRequestMessage(Writer *output)
{
  IconPresetSaveRequestMessage::serializeAs_IconPresetSaveRequestMessage(output);
}

void IdolsPresetSaveRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_IdolsPresetSaveRequestMessage(input);
}

void IdolsPresetSaveRequestMessage::deserializeAs_IdolsPresetSaveRequestMessage(Reader *input)
{
  IconPresetSaveRequestMessage::deserialize(input);
}

void IdolsPresetSaveRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IdolsPresetSaveRequestMessage(tree);
}

void IdolsPresetSaveRequestMessage::deserializeAsyncAs_IdolsPresetSaveRequestMessage(FuncTree tree)
{
  IconPresetSaveRequestMessage::deserializeAsync(tree);
}

IdolsPresetSaveRequestMessage::IdolsPresetSaveRequestMessage()
{
  m_type = MessageEnum::IDOLSPRESETSAVEREQUESTMESSAGE;
}

