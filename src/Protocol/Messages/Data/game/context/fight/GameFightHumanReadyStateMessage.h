#ifndef GAMEFIGHTHUMANREADYSTATEMESSAGE_H
#define GAMEFIGHTHUMANREADYSTATEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameFightHumanReadyStateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightHumanReadyStateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightHumanReadyStateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightHumanReadyStateMessage(FuncTree tree);
  GameFightHumanReadyStateMessage();

  double characterId;
  bool isReady;

private:
  void _characterIdFunc(Reader *input);
  void _isReadyFunc(Reader *input);
};

#endif // GAMEFIGHTHUMANREADYSTATEMESSAGE_H