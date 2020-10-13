#ifndef CHARACTERSTATSLISTMESSAGE_H
#define CHARACTERSTATSLISTMESSAGE_H

#include "src/Protocol/Types/Data/game/character/characteristic/CharacterCharacteristicsInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class CharacterStatsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterStatsListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterStatsListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterStatsListMessage(FuncTree tree);
  CharacterStatsListMessage();

  CharacterCharacteristicsInformations stats;

private:
  void _statstreeFunc(Reader *input);

  FuncTree _statstree;
};

#endif // CHARACTERSTATSLISTMESSAGE_H