#ifndef CHARACTERSTATSLISTMESSAGE_H
#define CHARACTERSTATSLISTMESSAGE_H

#include "src/protocol/network/types/data/game/character/characteristic/CharacterCharacteristicsInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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

  QSharedPointer<CharacterCharacteristicsInformations> stats;

private:
  void _statstreeFunc(Reader *input);

  FuncTree _statstree;
};

#endif // CHARACTERSTATSLISTMESSAGE_H