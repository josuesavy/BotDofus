#ifndef ARENAFIGHTERLEAVEMESSAGE_H
#define ARENAFIGHTERLEAVEMESSAGE_H

#include "src/protocol/network/types/data/game/character/CharacterBasicMinimalInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ArenaFighterLeaveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ArenaFighterLeaveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ArenaFighterLeaveMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ArenaFighterLeaveMessage(FuncTree tree);
  ArenaFighterLeaveMessage();

  CharacterBasicMinimalInformations leaver;

private:
  void _leavertreeFunc(Reader *input);

  FuncTree _leavertree;
};

#endif // ARENAFIGHTERLEAVEMESSAGE_H