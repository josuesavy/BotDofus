#ifndef QUESTLISTMESSAGE_H
#define QUESTLISTMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/quest/QuestActiveInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class QuestListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_QuestListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_QuestListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_QuestListMessage(FuncTree tree);
  QuestListMessage();

  QList<uint> finishedQuestsIds;
  QList<uint> finishedQuestsCounts;
  QList<QSharedPointer<QuestActiveInformations>> activeQuests;
  QList<uint> reinitDoneQuestsIds;

private:
  void _finishedQuestsIdstreeFunc(Reader *input);
  void _finishedQuestsIdsFunc(Reader *input);
  void _finishedQuestsCountstreeFunc(Reader *input);
  void _finishedQuestsCountsFunc(Reader *input);
  void _activeQueststreeFunc(Reader *input);
  void _activeQuestsFunc(Reader *input);
  void _reinitDoneQuestsIdstreeFunc(Reader *input);
  void _reinitDoneQuestsIdsFunc(Reader *input);

  FuncTree _finishedQuestsIdstree;
  FuncTree _finishedQuestsCountstree;
  FuncTree _activeQueststree;
  FuncTree _reinitDoneQuestsIdstree;
};

#endif // QUESTLISTMESSAGE_H