#ifndef FIGHTERSTATSLISTMESSAGE_H
#define FIGHTERSTATSLISTMESSAGE_H

#include "src/Protocol/Types/Data/game/character/characteristic/CharacterCharacteristicsInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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

  CharacterCharacteristicsInformations stats;

private:
  void _statstreeFunc(Reader *input);

  FuncTree _statstree;
};

#endif // FIGHTERSTATSLISTMESSAGE_H