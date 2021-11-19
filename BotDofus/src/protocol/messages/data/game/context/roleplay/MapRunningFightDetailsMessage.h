#ifndef MAPRUNNINGFIGHTDETAILSMESSAGE_H
#define MAPRUNNINGFIGHTDETAILSMESSAGE_H

#include "src/protocol/types/data/game/context/fight/GameFightFighterLightInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class MapRunningFightDetailsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapRunningFightDetailsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapRunningFightDetailsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapRunningFightDetailsMessage(FuncTree tree);
  MapRunningFightDetailsMessage();

  uint fightId;
  QList<QSharedPointer<GameFightFighterLightInformations>> attackers;
  QList<QSharedPointer<GameFightFighterLightInformations>> defenders;

private:
  void _fightIdFunc(Reader *input);
  void _attackerstreeFunc(Reader *input);
  void _attackersFunc(Reader *input);
  void _defenderstreeFunc(Reader *input);
  void _defendersFunc(Reader *input);

  FuncTree _attackerstree;
  FuncTree _defenderstree;
};

#endif // MAPRUNNINGFIGHTDETAILSMESSAGE_H