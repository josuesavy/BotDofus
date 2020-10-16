#ifndef REFRESHCHARACTERSTATSMESSAGE_H
#define REFRESHCHARACTERSTATSMESSAGE_H

#include "src/Protocol/Types/Data/game/context/fight/GameFightMinimalStats.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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
  QSharedPointer<GameFightMinimalStats> stats;

private:
  void _fighterIdFunc(Reader *input);
  void _statstreeFunc(Reader *input);

  FuncTree _statstree;
};

#endif // REFRESHCHARACTERSTATSMESSAGE_H