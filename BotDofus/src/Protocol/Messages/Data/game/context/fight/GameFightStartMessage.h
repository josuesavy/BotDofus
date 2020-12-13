#ifndef GAMEFIGHTSTARTMESSAGE_H
#define GAMEFIGHTSTARTMESSAGE_H

#include "src/protocol/types/data/game/idol/Idol.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameFightStartMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightStartMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightStartMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightStartMessage(FuncTree tree);
  GameFightStartMessage();

  QList<QSharedPointer<Idol>> idols;

private:
  void _idolstreeFunc(Reader *input);
  void _idolsFunc(Reader *input);

  FuncTree _idolstree;
};

#endif // GAMEFIGHTSTARTMESSAGE_H