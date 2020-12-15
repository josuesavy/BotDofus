#ifndef HOUSEINFORMATIONSFORGUILD_H
#define HOUSEINFORMATIONSFORGUILD_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/house/HouseInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class HouseInformationsForGuild : public HouseInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseInformationsForGuild(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseInformationsForGuild(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseInformationsForGuild(FuncTree tree);
  HouseInformationsForGuild();
  bool operator==(const HouseInformationsForGuild &compared);

  uint instanceId;
  bool secondHand;
  QString ownerName;
  int worldX;
  int worldY;
  double mapId;
  uint subAreaId;
  QList<int> skillListIds;
  uint guildshareParams;

private:
  void _instanceIdFunc(Reader *input);
  void _secondHandFunc(Reader *input);
  void _ownerNameFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _mapIdFunc(Reader *input);
  void _subAreaIdFunc(Reader *input);
  void _skillListIdstreeFunc(Reader *input);
  void _skillListIdsFunc(Reader *input);
  void _guildshareParamsFunc(Reader *input);

  FuncTree _skillListIdstree;
};

#endif // HOUSEINFORMATIONSFORGUILD_H