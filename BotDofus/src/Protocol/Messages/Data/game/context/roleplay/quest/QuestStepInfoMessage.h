#ifndef QUESTSTEPINFOMESSAGE_H
#define QUESTSTEPINFOMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/quest/QuestActiveInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class QuestStepInfoMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_QuestStepInfoMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_QuestStepInfoMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_QuestStepInfoMessage(FuncTree tree);
  QuestStepInfoMessage();

  QSharedPointer<QuestActiveInformations> infos;

private:
  void _infostreeFunc(Reader *input);

  FuncTree _infostree;
};

#endif // QUESTSTEPINFOMESSAGE_H