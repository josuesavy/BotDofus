#ifndef GAMEACTIONFIGHTACTIVATEGLYPHTRAPMESSAGE_H
#define GAMEACTIONFIGHTACTIVATEGLYPHTRAPMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightActivateGlyphTrapMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightActivateGlyphTrapMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightActivateGlyphTrapMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightActivateGlyphTrapMessage(FuncTree tree);
  GameActionFightActivateGlyphTrapMessage();

  int markId;
  bool active;

private:
  void _markIdFunc(Reader *input);
  void _activeFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTACTIVATEGLYPHTRAPMESSAGE_H