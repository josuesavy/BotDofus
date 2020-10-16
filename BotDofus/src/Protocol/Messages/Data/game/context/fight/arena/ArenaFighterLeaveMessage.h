#ifndef ARENAFIGHTERLEAVEMESSAGE_H
#define ARENAFIGHTERLEAVEMESSAGE_H

#include "src/Protocol/Types/Data/game/character/CharacterBasicMinimalInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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