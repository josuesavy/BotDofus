#ifndef GAMEACTIONFIGHTTRIGGERGLYPHTRAPMESSAGE_H
#define GAMEACTIONFIGHTTRIGGERGLYPHTRAPMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightTriggerGlyphTrapMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightTriggerGlyphTrapMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightTriggerGlyphTrapMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightTriggerGlyphTrapMessage(FuncTree tree);
  GameActionFightTriggerGlyphTrapMessage();

  int markId;
  uint markImpactCell;
  double triggeringCharacterId;
  uint triggeredSpellId;

private:
  void _markIdFunc(Reader *input);
  void _markImpactCellFunc(Reader *input);
  void _triggeringCharacterIdFunc(Reader *input);
  void _triggeredSpellIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTTRIGGERGLYPHTRAPMESSAGE_H