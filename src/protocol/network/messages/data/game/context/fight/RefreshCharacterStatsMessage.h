#ifndef REFRESHCHARACTERSTATSMESSAGE_H
#define REFRESHCHARACTERSTATSMESSAGE_H

#include "src/protocol/network/types/data/game/context/fight/GameFightCharacteristics.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class RefreshCharacterStatsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_RefreshCharacterStatsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_RefreshCharacterStatsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_RefreshCharacterStatsMessage(FuncTree tree);
  RefreshCharacterStatsMessage();

  double fighterId;
  QSharedPointer<GameFightCharacteristics> stats;

private:
  void _fighterIdFunc(Reader *input);
  void _statstreeFunc(Reader *input);

  FuncTree _statstree;
};

#endif // REFRESHCHARACTERSTATSMESSAGE_H