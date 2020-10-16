#ifndef GAMEFIGHTNEWWAVEMESSAGE_H
#define GAMEFIGHTNEWWAVEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameFightNewWaveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightNewWaveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightNewWaveMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightNewWaveMessage(FuncTree tree);
  GameFightNewWaveMessage();

  uint id;
  uint teamId;
  int nbTurnBeforeNextWave;

private:
  void _idFunc(Reader *input);
  void _teamIdFunc(Reader *input);
  void _nbTurnBeforeNextWaveFunc(Reader *input);
};

#endif // GAMEFIGHTNEWWAVEMESSAGE_H