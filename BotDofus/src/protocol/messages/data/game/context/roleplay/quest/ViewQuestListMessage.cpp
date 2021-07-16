#include "ViewQuestListMessage.h"

void ViewQuestListMessage::serialize(Writer *output)
{
  this->serializeAs_ViewQuestListMessage(output);
}

void ViewQuestListMessage::serializeAs_ViewQuestListMessage(Writer *output)
{
  QuestListMessage::serializeAs_QuestListMessage(output);
}

void ViewQuestListMessage::deserialize(Reader *input)
{
  this->deserializeAs_ViewQuestListMessage(input);
}

void ViewQuestListMessage::deserializeAs_ViewQuestListMessage(Reader *input)
{
  QuestListMessage::deserialize(input);
}

void ViewQuestListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ViewQuestListMessage(tree);
}

void ViewQuestListMessage::deserializeAsyncAs_ViewQuestListMessage(FuncTree tree)
{
  QuestListMessage::deserializeAsync(tree);
}

ViewQuestListMessage::ViewQuestListMessage()
{
  m_type = MessageEnum::VIEWQUESTLISTMESSAGE;
}

