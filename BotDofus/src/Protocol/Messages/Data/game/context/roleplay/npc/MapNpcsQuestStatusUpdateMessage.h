#ifndef MAPNPCSQUESTSTATUSUPDATEMESSAGE_H
#define MAPNPCSQUESTSTATUSUPDATEMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/quest/GameRolePlayNpcQuestFlag.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MapNpcsQuestStatusUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapNpcsQuestStatusUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapNpcsQuestStatusUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapNpcsQuestStatusUpdateMessage(FuncTree tree);
  MapNpcsQuestStatusUpdateMessage();

  double mapId;
  QList<int> npcsIdsWithQuest;
  QList<GameRolePlayNpcQuestFlag> questFlags;
  QList<int> npcsIdsWithoutQuest;

private:
  void _mapIdFunc(Reader *input);
  void _npcsIdsWithQuesttreeFunc(Reader *input);
  void _npcsIdsWithQuestFunc(Reader *input);
  void _questFlagstreeFunc(Reader *input);
  void _questFlagsFunc(Reader *input);
  void _npcsIdsWithoutQuesttreeFunc(Reader *input);
  void _npcsIdsWithoutQuestFunc(Reader *input);

  FuncTree _npcsIdsWithQuesttree;
  FuncTree _questFlagstree;
  FuncTree _npcsIdsWithoutQuesttree;
};

#endif // MAPNPCSQUESTSTATUSUPDATEMESSAGE_H