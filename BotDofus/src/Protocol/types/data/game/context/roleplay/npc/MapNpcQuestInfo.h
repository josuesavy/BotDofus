#ifndef MAPNPCQUESTINFO_H
#define MAPNPCQUESTINFO_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/quest/GameRolePlayNpcQuestFlag.h"
#include "src/engines/io/network/utils/FuncTree.h"

class MapNpcQuestInfo : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapNpcQuestInfo(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapNpcQuestInfo(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapNpcQuestInfo(FuncTree tree);
  MapNpcQuestInfo();
  bool operator==(const MapNpcQuestInfo &compared);

  double mapId;
  QList<int> npcsIdsWithQuest;
  QList<GameRolePlayNpcQuestFlag> questFlags;

private:
  void _mapIdFunc(Reader *input);
  void _npcsIdsWithQuesttreeFunc(Reader *input);
  void _npcsIdsWithQuestFunc(Reader *input);
  void _questFlagstreeFunc(Reader *input);
  void _questFlagsFunc(Reader *input);

  FuncTree _npcsIdsWithQuesttree;
  FuncTree _questFlagstree;
};

#endif // MAPNPCQUESTINFO_H