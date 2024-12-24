#ifndef GAMEFIGHTHUMANREADYSTATEMESSAGE_H
#define GAMEFIGHTHUMANREADYSTATEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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