#ifndef GUILDINFOSUPGRADEMESSAGE_H
#define GUILDINFOSUPGRADEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildInfosUpgradeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildInfosUpgradeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildInfosUpgradeMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildInfosUpgradeMessage(FuncTree tree);
  GuildInfosUpgradeMessage();

  uint maxTaxCollectorsCount;
  uint taxCollectorsCount;
  uint taxCollectorLifePoints;
  uint taxCollectorDamagesBonuses;
  uint taxCollectorPods;
  uint taxCollectorProspecting;
  uint taxCollectorWisdom;
  uint boostPoints;
  QList<uint> spellId;
  QList<int> spellLevel;

private:
  void _maxTaxCollectorsCountFunc(Reader *input);
  void _taxCollectorsCountFunc(Reader *input);
  void _taxCollectorLifePointsFunc(Reader *input);
  void _taxCollectorDamagesBonusesFunc(Reader *input);
  void _taxCollectorPodsFunc(Reader *input);
  void _taxCollectorProspectingFunc(Reader *input);
  void _taxCollectorWisdomFunc(Reader *input);
  void _boostPointsFunc(Reader *input);
  void _spellIdtreeFunc(Reader *input);
  void _spellIdFunc(Reader *input);
  void _spellLeveltreeFunc(Reader *input);
  void _spellLevelFunc(Reader *input);

  FuncTree _spellIdtree;
  FuncTree _spellLeveltree;
};

#endif // GUILDINFOSUPGRADEMESSAGE_H