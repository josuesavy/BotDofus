#ifndef DUMPEDENTITYSTATSMESSAGE_H
#define DUMPEDENTITYSTATSMESSAGE_H

#include "src/protocol/network/types/data/game/character/characteristic/CharacterCharacteristics.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class DumpedEntityStatsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DumpedEntityStatsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DumpedEntityStatsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DumpedEntityStatsMessage(FuncTree tree);
  DumpedEntityStatsMessage();

  double actorId;
  QSharedPointer<CharacterCharacteristics> stats;

private:
  void _actorIdFunc(Reader *input);
  void _statstreeFunc(Reader *input);

  FuncTree _statstree;
};

#endif // DUMPEDENTITYSTATSMESSAGE_H