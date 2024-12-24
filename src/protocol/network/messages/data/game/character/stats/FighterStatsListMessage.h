#ifndef FIGHTERSTATSLISTMESSAGE_H
#define FIGHTERSTATSLISTMESSAGE_H

#include "src/protocol/network/types/data/game/character/characteristic/CharacterCharacteristicsInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class FighterStatsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FighterStatsListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FighterStatsListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FighterStatsListMessage(FuncTree tree);
  FighterStatsListMessage();

  QSharedPointer<CharacterCharacteristicsInformations> stats;

private:
  void _statstreeFunc(Reader *input);

  FuncTree _statstree;
};

#endif // FIGHTERSTATSLISTMESSAGE_H