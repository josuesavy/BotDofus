#ifndef ARENAFIGHTERIDLEMESSAGE_H
#define ARENAFIGHTERIDLEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ArenaFighterIdleMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ArenaFighterIdleMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ArenaFighterIdleMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ArenaFighterIdleMessage(FuncTree tree);
  ArenaFighterIdleMessage();
};

#endif // ARENAFIGHTERIDLEMESSAGE_H