#ifndef JOBCRAFTERDIRECTORYENTRYPLAYERINFO_H
#define JOBCRAFTERDIRECTORYENTRYPLAYERINFO_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/character/status/PlayerStatus.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/enums/data/PlayableBreedEnum.h"
#include "src/engines/io/network/utils/FuncTree.h"

class JobCrafterDirectoryEntryPlayerInfo : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobCrafterDirectoryEntryPlayerInfo(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobCrafterDirectoryEntryPlayerInfo(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobCrafterDirectoryEntryPlayerInfo(FuncTree tree);
  JobCrafterDirectoryEntryPlayerInfo();
  bool operator==(const JobCrafterDirectoryEntryPlayerInfo &compared);

  double playerId;
  QString playerName;
  int alignmentSide;
  int breed;
  bool sex;
  bool isInWorkshop;
  int worldX;
  int worldY;
  double mapId;
  uint subAreaId;
  bool canCraftLegendary;
  QSharedPointer<PlayerStatus> status;

private:
  void _playerIdFunc(Reader *input);
  void _playerNameFunc(Reader *input);
  void _alignmentSideFunc(Reader *input);
  void _breedFunc(Reader *input);
  void _sexFunc(Reader *input);
  void _isInWorkshopFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _mapIdFunc(Reader *input);
  void _subAreaIdFunc(Reader *input);
  void _canCraftLegendaryFunc(Reader *input);
  void _statustreeFunc(Reader *input);

  FuncTree _statustree;
};

#endif // JOBCRAFTERDIRECTORYENTRYPLAYERINFO_H